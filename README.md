# Tinc 本地卸载分流方案
首先，请记住5月31日这个日子，防火墙从这一天开始彻底疯了。。。

对于国内外分流，我知道的方案有iptables，或者添加路由，当然如果是PC客户端的话，也可以用PAC。
- 使用路由的：
  https://github.com/FQrabbit/VPN-skip-China-route-Window

- 使用iptables的:
  https://github.com/houzhenggang/turn-socks-to-vpn

上面两种都可以配合chinadns来实现国内外流量分流。

下面是这里描述的另外一种方案

## 拓扑图
![alt text](https://raw.githubusercontent.com/chk-jxcn/tinc-local-offload/master/1.png)

## 原理
在tinc中启动两个接口，当tun0中接收到报文时，如果目标地址匹配china subnets的话，转发到另外一个接口，如果设置了NAT地址，则把源地址进行NAT后送出去。

国内流量的方向
```
eth1下的设备->eth1->tun1->tun0->eth0
```
国外流量的方向
```
eth1下的设备->eth1->tun1->VPN 服务器
```

配合chinaDNS(https://github.com/cherrot/gochinadns) 可以实现国内域名发送到国内地址, 国外域名发送到国外地址

修改的路由及iptables部分(iptables 做NAT，ip rule实现源地址路由)：
```
# $INTERFACE = tun1
# $INTERFACELOCAL = tun0
ip route add default via 192.168.1.1 dev eth0 200
ip route add default dev $INTERFACE scope link table 500

ip rule add from 192.168.200.100 lookup 500
ip rule add from all iif $INTERFACELOCAL lookup 200

iptables -t nat -A POSTROUTING -o $INTERFACE -j MASQUERADE
iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
```

修改的tinc代码：
- 增加tun1设备
- 使用https://github.com/chuckination/lctrie 来进行目标地址匹配(Intel 3205U测试，单线程匹配5000条国内子网表，大概10Mqps，对于大部分机器来说都不是瓶颈了)
- 移植freebsd下的libalias(https://wiki.freebsd.org/Libalias)来执行NAT（不执行NAT也可以，但是iptables似乎无法正确在出口对tun0进来的包进行NAT）

## 遇到的问题
* tinc-1.1pre17无法在freebsd链接libz，需要删除__nonull__的定义 （bug of tinc）
* lctrie 中的ip addr结构与tinc有冲突，用uint32_t 传递IP地址
* libalias 中的LIST_NEXT等宏在linux中未定义，引入freebsd的queue头文件
* libalias 中检测头文件是否包含的宏与linux头文件定义不一致
* libalias 中的ip, tcp, udp等结构与linux中定义不一致，引入宏定义 -DNO_FW_PUNCH -D_BSD_SOURCE -D__BSD_SOURCE -D__FAVOR_BSD
* chinadns 实现中的upstream DNS server会根据IP来决定是否Trusted，修改为全部Untrusted(因为需要使用内网dns服务器进行缓存)
