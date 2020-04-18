# SchoolBusSystem
>Useing c++ language to achieve the bus operation system


## 项目介绍
>一卡通乘车模拟系统是一款通用性极强的校园乘车管理系统，软件功能囊括了银行从用户开户到最终销户等业务的全过程。软件适用于许多校园卡乘车。软件覆盖校园卡的现金充值与办理新卡业务，软件的各个模块操作界面简单、实用，软件模拟系统让用户可以在最短的时间内掌握软件的使用方法。软件系统采用一卡通管理系统与校车管理系统，操作简单易学。本软件主要是为用户能够使用校园卡乘车服务的目的设计。主要业务包括用户注册、充值、注销、乘车、校车运行管理、查询校车运行情况等项目。所有操作都会保存文件中，实现一卡通管理和校车管理服务的目的。

## 实验环境
![](https://img-blog.csdnimg.cn/20200419070840735.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzQ1MjQyNA==,size_16,color_FFFFFF,t_70)

## 实验内容
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;一卡通模拟系统主要完成的功能是，支持一卡通刷卡乘车;对每张一卡通的使用情况及费用进行统计；对每辆班车的运行情况进行统计。
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<font color =black size=4>实现使用一卡通刷卡时，扣除乘车费用及显示卡内信息的功能。</font><br/>
<font size=4 color=black>具体要求：</font><br/>
&nbsp;&nbsp;&nbsp;&nbsp;1、本系统中的一卡通用于乘坐班车。按照一卡通持有人员，可将一卡通分为教师卡、学生卡和限制卡。教师卡免费乘车；学生卡每次乘车扣除2块钱；限制卡乘车，每月的前20次免费，之后每次扣除2块钱。<br/>
>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 每次刷卡乘车时，应显示出每张卡片的持有人姓名及卡内余额。对于限制卡，还应显示出已经乘坐的次数；当达到20次时，提示这是本月最后一次免费乘车；第21次时，提示本次开始收费。<br/>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font size=4 color=black>实现使用一卡通刷卡时，扣除乘车费用及显示卡内信息的功能。</font>
<br/>

<font size=4 color=black>具体要求：</font><br/>
>1. 如果刷卡后，卡内余额低于（小于等于）5块钱，应提示持卡人，余额过低，及时充值。
>2. 如果卡内余额少于2块钱，提示余额不足，不准乘车。
>3. 能够显示出每张一卡通的信息，包括持卡人姓名、一卡通编号、所属单位、卡内余额、有效期等（可以根据需要自行添加其他信息）。
>4. 能够显示出每张一卡通每月的累计乘车次数。
>5. 系统中拥有的一卡通数量：学生卡 > 教师卡 > 限制卡
>6. 每个人只能且仅能持有一张一卡通。
>7. 一卡通系统的新需求：在系统中增加对班车信息的管理
<br/>

&nbsp;&nbsp;&nbsp;&nbsp;2、实现统计班车的基本信息：车牌号、型号、载乘人数、驾驶员姓名、运行时间段<br/>

>1. 为班车编制运行时刻表：每辆班车的运行时段、每个班次应该达到和离开乘车点的时间、预计的全程运行时间
>2. 刷卡上车时，统计已经上车的人数。如果达到该班车的载乘人数，则禁止继续上车。
>3. 记录每辆班车实际到达和离开乘车点的时间、达到目的地的时间。
>4. 每天对每辆班车的运行信息进行汇总：
>5. 每辆车的实际乘车人数与载乘人数比；
>6. 发车准时率
>7. 每辆班车的按时达到率

&nbsp;&nbsp;&nbsp;&nbsp;3、在系统中增加对一卡通持卡人信息的管理<br/>
>1. 保存持卡人的基本信息：姓名、性别、职务、所属单位、工资号/学号等
2. 记录每个人的乘车次数
3. 增加申请新卡、注销一卡通的功能


## 实验步骤
### 一、设计六个类
#### &nbsp;&nbsp;&nbsp;&nbsp;（1）、类名：Card
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;属性：友元类Teacher、Student、Limit；<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;持卡者名字（name）、卡号（card_num）、卡类型（id）、持卡单位（company）、余额（money）、使用次数（times）;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;方法:注册新卡（init）、删除（del）、查询信（ask_inform）、查询余额（ask_money）、查询次数（ask_times）、判断余额支持支付（money_out）、写入文件（save）;<br/>
#### &nbsp;&nbsp;&nbsp;&nbsp;（2）类名：Student
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;属性：继承类Card使用Card的属性<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;方法：（虚函数） 充值（add_money）、使用次数记录（use）:<br/>
#### &nbsp;&nbsp;&nbsp;&nbsp;（3）类名：Teacher<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;属性：继承类Card使用Card的属性<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;方法：（虚函数） 充值（add_money）、使用次数记录（use）<br/>
#### &nbsp;&nbsp;&nbsp;&nbsp;（4）类名：Limit<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;属性：继承类Card使用Card的属性<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;方法：（虚函数） 充值（add_money）、使用次数记录（use）:<br>

![](https://img-blog.csdnimg.cn/20200419073000527.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzQ1MjQyNA==,size_16,color_FFFFFF,t_70)
<br/>
#### &nbsp;&nbsp;&nbsp;&nbsp;（5）类名：Bus<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;属性：使用Card的继承关系建立友元函数Teacher、Student、Limit的使用use成员函数、建立两个Time类的数组，表示开始运行时间和到达运营时间riding[20]、c_riding[20]：校车车牌号bus_num、汽车类型bus_type、驾驶员rider_name、校车的最大座位量person_max、当前的上车数量person_num总的运行次数time_num、理论运营时间all_time、实际运行时间C-all_time：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;方法：校车信息添加（init）、更改校车信息（f_init）、计算上车人数（count）、总的运行时间的计算（C-time）、判断是否坐满（if_full）、写入文件（save）、汇总班车运行信息（inform）:<br/>

![](https://img-blog.csdnimg.cn/20200419073140363.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzQ1MjQyNA==,size_16,color_FFFFFF,t_70)
<br/>
#### &nbsp;&nbsp;&nbsp;&nbsp;（6）类名：Time<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;属性：建立友元类Bus、两个用于存储发车时间和到达时间、将字符串转化为数值用start和arrive存储、之后得到实际运行时间总时间间隔（interval）<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;方法：时间的初始化（init）、写入文件（save）：<br/>

![](https://img-blog.csdnimg.cn/20200419073254538.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzQ1MjQyNA==,size_16,color_FFFFFF,t_70)

<br/>
### 二、设计一卡通：注册、充值、查询余额、查询已使用次数、退出<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1、注册：Card& Card::init(string nname,int num,int cardnum,string com,int mon,int t)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;使用类的成员函数init函数，作用类似于类的析构函数，对类中的数据成员进行初始化，同时返回一个Card类型的对象，以此达到注册的功能：在注册的时候规定，1开头的卡号为老师卡、2开头的为学生卡、3开头的为限制卡
<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2、删除：void Card::del(int num)<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;同时输入卡号，对写入文件的Card对象进行名字、卡号进行置于0：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3、查询：void Card::ask_times(int num)、void Card::ask_inform(int num)、void Card::ask_money(int num)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;对输入的卡号在文件中进行匹配，找出其中相匹配的卡号，同时输出其中的使用次数、余额<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4、充值：<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;（教师卡）Card& Teacher::add_money(int num,int n)、<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;（学生卡）Card& Student::add_money(int num,int n)、<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;（限制卡）Card& Limit::add_money(int num,int n)：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;教师卡：由于教师卡不可以充值，所以当匹配到老师卡时，提示输出“很抱歉！教师卡不能充值！”<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;学生卡：当匹配到学生卡时，使用引用类型的返回类型，对类中的money进行加充值金额（限制卡也一样）：
<br/>
### 三、设计校车管理：新建校车信息、指定运行计划表（理论运行时间表）、校车运行信息汇总：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1、新建校车信息：Bus& Bus::init(string num, string type, string rider, int person)
将新建校车信息当成析构函数使用，也就是对象的初始化：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2、制定运行时间计划表：Bus& Bus::f_init(string num, string type, string rider, int person)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3、校车运行信息汇总：void Bus::inform()：<br/>
### 四、三、设计主函数：
使用if语句进行匹配从而进行相应的功能：<br/>
1：卡系统管理：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1：注册卡：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2：充值卡：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3：查询余额：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4：查询持卡人信息：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;5：注销卡号：<br/>
2：校车信息管理系统：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;建立新的校车信息：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;建立新校车的运行时间计划表：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0：退出（进行乘车业务）<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;进行输入乘&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;车车牌号：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;输入乘车卡号：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;显示乘车客户的卡号、名字、使用次数：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;显示车上的人数：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 ：退出乘车系统：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;显示当日校车的运行信息：<br/>

## 测试结果

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1、主界面：
![](https://img-blog.csdnimg.cn/20200419074318470.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzQ1MjQyNA==,size_16,color_FFFFFF,t_70)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2、办理业务（注册新卡）
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;当选择1卡业务：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;出现1：办理新卡、2：充值、3：查询余额、4：查询已经使用次数、5：注销、0：退出：
![](https://img-blog.csdnimg.cn/20200419074318470.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzQ1MjQyNA==,size_16,color_FFFFFF,t_70)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1、新添加卡，就输入：“姓名 卡类型 持卡单位”、否则按：“0 0 0”退出：<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;如果添加成功，便提示success!否则提示Wrong!<br/>
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200419074538334.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzQ1MjQyNA==,size_16,color_FFFFFF,t_70)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2：加入新卡后便进行充值操作：输入新加的卡号（如：10002）进行加入充值金额：100,；即可：<br/>
![在这里插入图片描述](https://img-blog.csdnimg.cn/2020041907462895.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzQ1MjQyNA==,size_16,color_FFFFFF,t_70)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3：查询余额：输入查询卡号：如果是老师卡：提示不能充值、如果是学生和限制卡便出现充值成功的提醒：OK!<br/>
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200419074656344.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzQ1MjQyNA==,size_16,color_FFFFFF,t_70)
<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4:查询使用次数：（输入卡号即可）<br>
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200419074728244.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzQ1MjQyNA==,size_16,color_FFFFFF,t_70)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;5:注销卡号：输入注销卡号即可<br/>
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200419074755378.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200419074810665.png)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0：退出卡管理系统：
<br/>
3、汽车管理系统<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;建立新的校车信息，输入车牌号、类型、驾驶员姓名、承载人数，同时再建立其运行时间表：输入运行时间次数X，之后按照提示类型输入时间：<br/>
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200419075013925.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzQ1MjQyNA==,size_16,color_FFFFFF,t_70)
<br>
4、刷卡上车<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;输入车牌号、一卡通号进行上车：（如果是1开头的一卡通号，则为老师卡，提示免费乘车；若为2开头则为学生卡，若为3开头的为限制卡，输出乘车人的信息），上车结束后进行输入“0 0”进行退出： <br>

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200419075102101.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzQ1MjQyNA==,size_16,color_FFFFFF,t_70)<br>

5、汇总当日校车的运行情况
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;将信息存入文件studentcard2中：<br/>
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200419075156819.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzQ1MjQyNA==,size_16,color_FFFFFF,t_70)<br>
![在这里插入图片描述](https://img-blog.csdnimg.cn/2020041907521682.png)<br/>
## 实验总结
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;面向对象方法学的出发点和基本原则是尽量模拟人类习惯的思维方式，使软件开发的方法与过程尽可能接近人类认识世界解决问题的方法与过程，从而使描述问题的问题空间与实现解法的解空间在结构上尽可能一致。
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;对象彼此间仅能通过发送消息互相联系。对象与传统数据有本质区别，他不是被动的等待外界对他施加操作，相反，是数据处理的主体，必须向它发消息请求它执行它的某个操作以及处理它的数据，而不能从外界直接对它的数据进行处理。<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;把对象作为融合了数据及在数据上的操作行为的统一的软件构件，程序中任何元素都是对象，复杂对象由比较简单的对象组合而成。<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;把所有的对象都划分成类，每个类都定义了一组数据和一组操作，类是对具有相同数据和相同操作的一组相似对象的定义。<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;最后便是自己的感触，第一次实现这样大的C++项目，真是不容易。此次课设，使我从管理的角度、全面的、系统的体验了一下。，对软件的各个方面从策划，设计，测试，到运行，所有角色都扮演了一遍。发现完成一项开发软件的工程，真是不容易的事情。 <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;尤其，在需求分析和对象设计阶段，除编码外，时间花的最长的两个阶段。即便如此，在编程的时候，还是觉得前面需求分析做的不是很彻底。但因时间原因，也没法做得再细致了。<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;操作方面，从大二上学期自学C语言，到如今基本掌握基础C++编程，真的是一次蜕变。在面对着许许多多的新知识学会了自己查找，自己思考，摆脱了高中的依赖心理，学会自己设计、实现，虽然这过程十分痛苦，但是最后结果还是让人欣慰。<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;希望以后能够在工作时用到这些！
