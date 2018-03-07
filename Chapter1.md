#Chapter1
## Review questions   
1.源文件(source file)经过编译后生成目标文件(object file)，再经过和预编译库的链接(linking)生成可执行文件(executable file)    
2.C++的注释和C相同：    
&emsp;&emsp;单行注释：//   
&emsp;&emsp;多行注释：/* ...... */    
3.#include后使用 " <> " 和 ' "" ' 的区别(两者功能基本上相同)：   
&emsp;&emsp;" <> "：编译时会先在系统include目录里搜索文件，如果找不到才会在源代码所在目录搜索       
&emsp;&emsp;' "" '：与上述查找顺序相反    
4.const float CENTIMETERS_PER_INCH = 2.54;    
5.main函数   
6.endl即"end of line",将换行符写入输出流，并将与设备关联的缓冲区的内容刷到设备中，保证目前为止程序所暂存的所有输出都真正写入输出流,与cout连用表示一行输出             
7.name，type，lifetime，scope     
8.abcfhkl     
9.domain,operations      
10.C++对于type的长度没有作出明确的定义，但长度大小顺序一定是long >= int >= short        
11.ASCLL代表一种字符与数字对应的编码格式，方便字符在计算机中的存储    
12.true,false   
13.double x = GetReal();  
14.cout << i << d << c << s << endl;    
15.结果依次为：     
&emsp;&emsp;int    5      
&emsp;&emsp;int    3     
&emsp;&emsp;float  3.8       
&emsp;&emsp;float  1.8      
&emsp;&emsp;int    4       
&emsp;&emsp;int    2       
16.一元运算符只有一个操作数，二元有两个      
17.截断，即小数取整    
18.结果依次为：  
&emsp;&emsp;4        
&emsp;&emsp;2        
&emsp;&emsp;42            
&emsp;&emsp;42       
19.a = a + b; 即 a += b;其他二元运算符同样如此               
20.区别：    
&emsp;&emsp;x++先进行完该运算表达式，再进行x的自增    
&emsp;&emsp;++x先进行x的自增，再进行该运算表达式         
21.短路求值，即最小化求值。只有当第一个运算数的值无法确定逻辑运算的结果时，才对第二个运算数进行求值，否则不必进行第二步判断，可以优化计算机效率     
22.组成：       
&emsp;&emsp;if:条件       
&emsp;&emsp;switch:所要判断的值，每种case，（defalut）     
&emsp;&emsp;while:继续循环条件    
&emsp;&emsp;for:初始值，继续循环条件，每次循环后进行的操作     
23.Firstly,we should judge the value of the values the user given.Secondly,according to the value,seach for the case match the value from top to down.Thirdly,execute the statement after the 
colon in this case.      
24.sentinel，即"哨兵",通常用于函数的返回值，用于判断函数得出的结果，每个值都具有独有的意义     
25.结果依次为：  
&emsp;&emsp;for(int i = 0;i < 101;i++){...}      
&emsp;&emsp;for(int i = 0;i < 100;i += 7){...}     
&emsp;&emsp;for(int i = 100;i > -1;i -= 2){...}    
26.函数原型，即在函数定义前先声明，告诉编译器(compiler)     
27.当函数调用时，系统会根据指向栈中的代码段中已定义的相应函数指针，调用该函数，根据向其中传入的参数，执行所有语句      
28.逐步细化，即"自顶向下设计"，先做个整体的框架，将问题细化，然后逐步处理细化出来的东西，最后整合，就是完整的系统     
