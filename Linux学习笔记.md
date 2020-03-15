[TOC]

# Linux

> 第一篇 vim 的使用

* 打开vim帮助文档`vimtutor`
* 快速删除一行`dd`
* `A` 在本行的末尾插入
* `i` 在当前插入
* `a`在后一位插入
* `set paste` 设置格式

## SHELL

> 认识shell并使用相关文件

在Linux系统中，shell是操作系统的外壳，为用户提供使用操作系统的接口，它是命令语言、命令解释程序和程序设计语言的统称。shell是用户和操作系统之间的一个接口。用户在命令提示符下输入的每个命令都首先由shell程序进行解释，然后再传给Linux内核的。

> BASH简介

Bourne shell是最早被大量使用及标准化的shell，几乎所有的Linux都支持它。它是由贝尔实验室开发的，由于开发者是Steven Bourne，所以被命名为“Bourne shell”。Bourne Again shell（bash）是Bourne shell的扩展，与Bourne shell完全兼容，并且在其基础上增加和增强了很多功能。其中包括了很多csh和ksh的优点。bash不仅有非常灵活和强大的编程接口，同时又有非常友好的用户界面。它内建40个shell命令和12个命令行参数。目前bash是大多数linux默认的shell

> BASH的功能

shell 为用户提供了使用操作系统的接口，使用户与操作系统内核之间进行沟通。

> 简单命令介绍

* `history`  ：bash的history功能提供了一种执行命令的最快方法，就是使用命令记录号码
* `!<记录号>`  : 可以执行历史记录中标记的命令
* `alias`  ：Linux中的别名功能是指提供给用户使用自定义的简单字符串，来替换复杂的命令选项，或是替换连续多个命令的连续组合的功能，从而使得用户可以自定义符合自己习惯的操作命令。
* `unalias`  ：取消特定别名。
* `>`  : 改写重定向，会删除原来的内容。
* `>>` ：追加重定向，新的内容将会被追加在原来内容的后面。

> 交互式处理

![img](https://ese3a9b6c5d0ic.prissl.qiqiuyun.net/coursematerial-36/20200310103643-or5tzsozpggg4ks0/6f2dcd31806fc33b_img5?e=1583991235&token=ExRD5wolmUnwwITVeSEXDQXizfxTRp7vnaMKJbO-:iMeEptAwGwp0QJUhpm9C1GkkmnA=) 

>TERMINAL, SHELL, BASH三者的关系

![img](https://ese3a9b6c5d0ic.prissl.qiqiuyun.net/coursematerial-36/20200310103643-or5tzsozpggg4ks0/6f2dcd31806fc33b_img6?e=1583991235&token=ExRD5wolmUnwwITVeSEXDQXizfxTRp7vnaMKJbO-:3UjE8P955HKZ6CapXvwoJ95JB4E=)

> 全局设置

![img](https://ese3a9b6c5d0ic.prissl.qiqiuyun.net/coursematerial-36/20200310103643-or5tzsozpggg4ks0/6f2dcd31806fc33b_img8?e=1583991235&token=ExRD5wolmUnwwITVeSEXDQXizfxTRp7vnaMKJbO-:IV8bxUdbiguf4sRLUUbrPBajdmc=)

*  /etc/profile 文件

>在Linux的shell中使用的变量分为以下环境变量、内部变量和用户变量3类。环境变量是Linux系统环境的一部分，通常不需要用户去定义。shell使用环境变量来存储系统信息，这些变量可以提供给在shell中执行的程序使用，不同的shell会有不同的环境变量及其设置的方法。内部变量是由系统提供的，用户不能修改它们。用户变量是用户在编写shell脚本的时候定义的，可以在shell脚本中任意使用和修改。

* .bashrc_profile 文件

> 每个系统用户的子目录下都有一个.bashrc_profile文件，用于设置每个用户的bash环境变量，Linux系统启动时，在读取/etc/profile文件的内容之后，就会检查该文件。

* /etc/bashrc文件

> 用户每次登录Linux系统的时候，都会自动读取并执行该文件

****



> 个人设置

![img](https://ese3a9b6c5d0ic.prissl.qiqiuyun.net/coursematerial-36/20200310103643-or5tzsozpggg4ks0/6f2dcd31806fc33b_img9?e=1583991235&token=ExRD5wolmUnwwITVeSEXDQXizfxTRp7vnaMKJbO-:ryguCpwJsX-2h2wHvDG9PNI56GA=)

*  .bashrc 文件

>在读取~/.bashrc_profile文件的过程中，Linux会在执行~/.bashrc_profile文件的内部中调用并执行~/.bashrc文件。另外，与前面两个文件不同，Linux系统每次用户登录bash的时候都会读取~/.bashrc文件，并重新设置该文件中定义的环境变量。而/etc/profile和~/.bashrc_profile只在系统启动的时候才读取。

### shell变量

> SHELL 变量

在Linux的shell中使用的变量分为以下环境变量、内部变量和用户变量3类。环境变量是Linux系统环境的一部分，通常不需要用户去定义。shell使用环境变量来存储系统信息，这些变量可以提供给在shell中执行的程序使用，不同的shell会有不同的环境变量及其设置的方法。内部变量是由系统提供的，用户不能修改它们。用户变量是用户在编写shell脚本的时候定义的，可以在shell脚本中任意使用和修改。

> 普通变量

```shell
num=100
str=hell0
echo $num
100
```

> 局部变量
>
> >

```shell
local num=100
echo ${num}
100
```

> 环境变量
>
> >

```shell
export num=100
echo ${num}
100
```

> 特殊变量

* 位置变量
  * `$0`:获取当前执行shell脚本的文件名，包括路径。
  * `$n`:获取当前执行脚本的第n个参数，n=1……9， 如果n大于9，则需要将n使用大括号括起来；
  * `$*`:获取当前shell的所有参数，将所有命令行参数视为单个字符串，相当于`$1$2$3`;
  * `$#`:得到执行当前脚本的参数个数；
  * `$@`:获取这个程序所有参数，并保留参数之间的任何空白， 相当于"`$1`  `$2`  `$3`", 这是将参数传给其他程序的最好办法；
* 状态变量
  * `$?` :判断上一指令是否成功执行，零为成功，非零为不成功；
  * `$$`:去当前进程的PID
  * `$!`:上一个指令的PID
  * `${parameter:-word}`:如果变量未定义，则表达式的值为word；
  * `$parameter:=word`:如果变量未定义，则设置变量的值为word，返回表达式的值也是word；
  * `$parameter:?word`：用于捕捉由于变量未定义而导致的错误并退出程序
  * `${parameter:+word}`如果变量已经定义，返回word，也就是真
  * `${!prefix*}`
  * `${!prefix@}`:prefix 开头的变量
  * `${#parameter}`:输出字符串的长度
  * `${parameter:offset}`:从第offset字符开始截取
  * `${parameter:offset:length}`:从offset字符开始截取，取length长度
  * `${parameter#pattern}`:从头删除最短匹配
  * `${parameter##pattern}`:最长
  * `${parameter%pattern}`:从尾删除最短
  * `${parameter%%pattern}`:从尾删除最长
  * `${parameter/pattern/string}`:第一个匹配被替换
  * `${parameter//pattern/string}`:全部匹配被替换
  * `${parameter/#pattern/string}`:字符串开头的替换
  * `${parameter/%pattern/string}`:字符串结尾的替换
  * `${parameter，，} ￥{parameter^^}`:全部转换为小写，大写
  * `${parameter,} ${parameter^}`:首字母转换为小写，大写

### shell 输入输出

> 输入输出 -READ

* ```shell
  read [options] [variable...]
  ```

  * -a array         把输入复制到数组array中，从索引号零开始。
  * -d delimiter  用字符串delimiter中的第一个字符指示输入结束，而不是一个换行符
  * -e                   使用Readline来处理输入。这使得与命令行相同的方式编辑输入
  * -n num          读取num个输入字符，而不是整行
  * -p prompt     为输入显示提示信息，使用字符串prompt
  * -r                    Raw mode， 不把反斜杠字符解释为转义字符
  * -s                    Silent mode
  * -t   seconds   超时
  * -u   fd              使用文件描述符fd中的输入，而不是标准输入

> 输入输出 - ECHO

* echo string
  * echo -e ”Hello HaiZei\n"           开启转义
  * echo “Hello $name, This is HaiZei"
  * echo  "\"Hello HaiZei\""

> 输入输出 - PRINTF

* ```
  printf format-string [arguments...]
  ```

  > printf "Hello %s, This is HaiZei\n" "Small A"
  >
  > > Hello Small A, This is HaiZei

### shell 函数



### shell 流程控制

> 流程控制 - IF

```shell
if test conditon;then
	command1
	elif condition2;then
	command2
	else 
	command3
fi
```

> for 循环

```shell
for var in item1 item2 ... itemN
do 
	command1
	command2
	command3
done
```

> while 语句

```shell
while conditon
do
	command
done
```

> until 循环

```shell 
until condition
do 
	command
done
```

> case

```shell
case 值 in
	模式1)
	command1
	command2
	；； #相当c语言中的break；
	模式2）
	command3
	command4
	；；
esac
```



### shell 数组

> 数组中可以存放多个值，Bash Shell 只支持一维数组，初始化不需要定义数组大小，数组下标元素由0开始

```shell
array=(1 2 3 4 5) 
array[0]=6
array[1]=7
array[2]=8
declare -a array2
chho "数组的元素为：${array[*]}"
echo "数组元素个数为： ${#array[*]}"
```

## bash系统命令



> man 手册
>
> > 可用man手册来查看命令的用法
> >
> > man  <命令>



> bash 通配符

* ? 代表单个任意字符
* 代表任意几个任意字符
* [list] 匹配list中的任意单一字符
* [!list] 匹配除list中的任意单一字符
* [c1 - c2] 匹配c1 - c2中的任意单一字符
* {string1, string2,...} 匹配sring1 或 string2 其一字符串

> 任务管理

* & 在命令的后面加上&表示后台执行的意思

```shell
command &
```

* ;  命令分隔符，在命令之间以；相连，表示顺序执行的意思

```shell
command1;command2
```

* && 命令间以&& 相连时，只有第一个命令成功执行，第二个命令才会执行

```
command1 && command2
```

* || 命令之间以|| 相连时，如果前一个命令执行失败，则执行第二个命令

```
command1 || command2
```

* ``命令中如果包含另一个命令，在执行的时候系统将优先执行命令中的子命令，然后将其结果 带入父命令继续执行

```shell
command1 `command2`
```

* `ctrl + z` 在shell中执行命令时，可以将该任务暂时挂起

> 挂起

* `bg` 执行命令， 可以将挂起的命令后台运行

```

```

* `fg` 执行命令可以将后台的命令转为前台执行
* `jobs` 在linux系统中，执行命令可以查看所有在后台执行和挂起的任务以及任务编号

> d

> 管道，重定向

* `>`改写重定向，会删除原来的内容
* `>>`追加重定向，新的内容将会被追加在原来内容的后面
* `<` 是从文件到命令的重定向
* `<<` 定义一个结束符  $ cat >> a.log << EOF$  输入时遇到EOF便停止
* `|` 管道命令操作符，简称管道符，用该命令将两个命令隔开，管道左边命令的输出就会作为管道右边命令的输入

> 转义符

* `''` 硬转义，硬硬引用，内部所有的shell元字符，通配符都会被关掉。其内部不允许出现单引号。
* `""`软转义，软引用，其内部只允许出现特定的shell元字符`$` `\` 以及命令替换符
* 反斜杠，转义，去除其后紧跟的元字符或通配符的特殊意义

> 系统信息

* `uptime` 打印系统运行时长和平均负载
* `w`当前登录用户列表及正在执行的任务
* `who`显示当前登录系统的用户信息
* `whoami`打印当前有效的用户名称
* `last`显示用户最近登录信息
* `uname`打印当前系统信息
* `date ` 显示或设置系统时间与日期
  * -d "string" 显示字符串所指的日期
    * `date -d "100 days ago”` 显示100天前的日期
    * `date -d "now +100 days"` 显示100天后的日期
  * -s "string" 设置时间
  * -u 显示GMT
* `cal`显示日历
  * -1， -3 显示最近一个月和三个月的日历
  * -j 显示一年的第几天
  * -y 显示当前年

> 文件与目录
>
> > 绝对路径
> >
> > 相对路径

* `cd`切换当前工作目录
  * `cd /etc`切换到`/etc`目录
  * `cd ..`切换到上层目录
  * `cd .`切换到当前目录
  * `cd` 回到到自己的家目录
  * `cd ~`回到自己的家目录
  * `cd -`回到上次工作目录
* `pwd` 打印当前工作目录

> pwd [-LP]
>
> > L 显示逻辑工作目录
> >
> > P显示物理工作目录

* `mkdir`创建目录

> mkdir [pm] <dir>
>
> > -p 自动设置父目录
> >
> > -m 设置权限

* `rmdir` 删除目录

> rmdir [p] <dir>
>
> > p 删除祖先

> 文件与目录的管理

* `ls` 显示文件及目录信息

  * `-a`显示所有文件及目录，隐藏文件除外
  * `-l`除文件名称外，亦将文件形态，权限，拥有者，文件大小等全部列出
  * `-r`将文件以相反次序显示
  * `-t`将文件依建立时间之先后次序列出
  * `-A`同-a， 但不列出当前目录，及父目录
  * `-F`在列出的文件名称后加一符号，例可执行文档加*， 目录则加/
  * `-R`若目录下有文件，则一下之文件亦皆依序列出
  * -`1`列出文件及目录，每个占一行

* `cp`拷贝

  * `-i` 若文件存在，询问用户
  * `-r`递归复制
  * `-a`pdr的集合
  * `-p`连同文件属性一起拷贝
  * `-d`若源文件为连接文件的属性，则复制连接文件的属性
  * `-s`拷贝为软连接
  * `-l`拷贝为硬连接
  * `-u`源文件比目的文件新才拷贝

* `rm` 删除

  > rm [irf] <dir_or_file>

  * `-i`互动模式
  * `-r`递归删除
  * `-f`force

* `mv` 移动

  > mv [ifu] <source...> <dest>

  * `-i`互动模式
  * `-f`force
  * `-u`源文件更新才会移动

* `basename`取文件名

* `dirname`取目录名

> 文件内容的查阅

* `cat`正向连续读

  > cat [-AbEnTv] <file>

  * `-A`相当于-vET
  * `-v`列出看不出的字符
  * `-E`显示断行符为`$`
  * `-T`显示TAB为^I
  * `-b`列出行号
  * `-n`列出行号，连同空行也编号

* `tac`反向连续读

* `nl`输出行号显示文件

  > nl [-bnw] <file>

  * `-b`行号指定的方式
    * `-b a` 相当于cat -a
    * `-b t`相当于cat -b
  * `-n`列出行号的表示方法
    * `-n ln`行号在屏幕最左边显示
    * `-n rn`行号在自己字段的最右边显示
    * `-n rz`行号在自己字段的最右边显示，前面自动补全0
  * `-w <num>`行号所占位数

* `more`一页一页的显示文件内容

  * `/string`向下查找string关键字
  * `：f`显示文件名称和当前显示的行数
  * `q`离开

* `less`与more相似，但是可以上下翻看

  * `/string`向下查找 `n:`继续向下查找
  * `/?string`反向查找 `N：`继续反向查询

* `head`只看头几行

  * `-n num`：显示前num行
  * `-n -num`：除了后num行外，其他的都显示

* `tail`只看末尾几行

  * `-n num`显示文件后num行
  * `-n +num`除了前num行，其他的都显示

* `od`以二进制方式查看文件内容