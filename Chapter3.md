# Chapter3
## Review questions
1.定义：      
&emsp;&emsp;interface，即"接口"，指实体把自己提供给外界的一种抽象化物，用以由内部操作分离出外部引用的方法        
&emsp;&emsp;package，即"包"，将一些自定义函数封装，仅留下一个接口，以供外界访问，而不需要知道包内部的细节      
&emsp;&emsp;abstraction，即"抽象化"，是将数据与程序隐藏，以语义来呈现出它的功能，隐藏起它的实现细节
&emsp;&emsp;implementation，即"实现"，是指通过计算机编程和开发，把技术规范或算法变成程序，软件组件或其他计算机系统      
&emsp;&emsp;client，即"客户端"，是指用户的计算机端        
2.区别：     
&emsp;&emsp;library是指一系列抽象函数的定义，但并未具体应用      
&emsp;&emsp;client是指一系列基于library的具体实现     
3.C++中的接口借助头文件来实现，通过引用头文件，可以访问其中的抽象函数     
4.头文件中定义的一系列抽象函数      
5.统一性、简洁性、充分性、通用性、稳定性      
6.当一个接口被许多程序引用时，如果接口不稳定，造成的损失会很大     
7.extending an interface，即"扩展一个接口"，是指可以向接口中添加新的抽象函数，但不可以更改之前的函数      
8.comments可以方便其他引用该接口的人快速理解该接口的功能，而不必再去翻看说明书      
9.false    
10.interface boilerplate：     
&emsp;&emsp;\#ifndef magic.h
&emsp;&emsp;\#define magic.h        
&emsp;&emsp;\#endif     
可以在编译这个头文件前检查是否之前已经编译过该文件，防止重复编译      
11.因为计算机计算的结果都是确定的，不存在真的随机结果      
12.RandomInteger(1000,9999);     
13.不能，必须先设置不同的种子      
14.因为未设置种子，系统会自动设置一个常数作为种子，导致每次调用rand()都会生成      
15.seed，即"种子"，是指srand()的参数，传入种子，函数会返回一个对应的整数      
16.step：(我简化了一下)           
&emsp;&emsp;int digit = rand();     
&emsp;&emsp;int domain = digit % (high - low + 1);     
&emsp;&emsp;return domain + low;     
17.与C相比，为了简便C++引用了string这一概念，不需要再去理解类似于C字符串数组的string储存方式      
18.循环遍历字符串，用str.at()或str[]提取每一个字符      
19.引用字符串接口      
20.判断两个字符串是不是相等     
21.s1     
22.返回空字符     
23.从头至尾，一个个按编码格式比较每个字符的大小     
24.结果依次为：    
&emsp;&emsp;5     
&emsp;&emsp;0     
&emsp;&emsp;'C'     
&emsp;&emsp;"ABCDE"       
&emsp;&emsp;"a"        
&emsp;&emsp;"ZCDE"      
&emsp;&emsp;"ABC"      
&emsp;&emsp;"E"      
&emsp;&emsp;"DE"    
&emsp;&emsp;"D"     
25.结果依次为：    
&emsp;&emsp;false     
&emsp;&emsp;ture      
&emsp;&emsp;false          
&emsp;&emsp;ture     
&emsp;&emsp;3     
&emsp;&emsp;9     
&emsp;&emsp;4      
&emsp;&emsp;-1(有时返回补码)      
&emsp;&emsp;"catch-22"         
&emsp;&emsp;"3.140"      
26.定义：    
&emsp;&emsp;ifstream，"文件输入流"，指针指向该文件，可读取文件      
&emsp;&emsp;ofstream，"文件输出流"，指针指向该文件，可向该文件输出   
&emsp;&emsp;important      
27.方便读取和输出       
28.in.fail();判断     
29.定义：     
&emsp;&emsp;cin，标准输入流    
&emsp;&emsp;cout，标准输出流    
&emsp;&emsp;cerr，标准错误流    
30.in.get() == EOF;     
31.EOF可转化-1，没有对应的char，可用于判断是否文件结束，而char都有具体意义，不能判断文件是否结束      
32.用于返回当前字符到输入流     
33.in.fail();     
34.区别：     
&emsp;&emsp;GetLine，库函数，用于标准输入流，读取一串字符串      
&emsp;&emsp;getline，库函数，用于文件输入流，读取一串字符串     
35.false    
36.结果依次为：    
&emsp;&emsp;true      
&emsp;&emsp;true      
&emsp;&emsp;true       
&emsp;&emsp;7         
&emsp;&emsp;'A'     
&emsp;&emsp;'a'       
37.乘以π / 180        
         