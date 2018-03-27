# Chapter2
## Review questions
1.定义：     
&emsp;&emsp;pointer:指向变量在内存中的物理地址     
&emsp;&emsp;array:由相同的原子类型组成的复合类型，在物理地址上是连续的     
&emsp;&emsp;record:即structure,可以由不相同的原子类型组成的复合类型，在物理地址上是连续的    
2.结果依次为：           
&emsp;&emsp;用整型来定义枚举变量      
&emsp;&emsp;enum polygonT{Triangle = 3,Square,Pentagon,Hexagon, Octagon};      
3.优点：    
&emsp;&emsp;不需要将变量全部定义出来     
&emsp;&emsp;枚举的名称具有具体意义，更易读，易区分     
&emsp;&emsp;编译器对枚举的检查更容易     
4.true    
5.directionT LeftFrom(directionT dir) {return dir == 0 ? directionT(3) : directionT(dir - 1);}      
6.struct定义了一个record，是结构体的关键字     
7.定义：   
&emsp;&emsp;bit：计算机存储的最小单元，储存二进制的0和1    
&emsp;&emsp;byte：一个字节，由8个bit组成，在内存中占据一个地址     
&emsp;&emsp;word：一个字，由地址连续的两个字节组成    
&emsp;&emsp;address：内存中存储数据的单元的地址      
8.false，未作出明确规定     
9.fasle    
10.sizeof可以确定变量或类型在具体机器上所占据的内存大小    
&emsp;&emsp;可以按如下格式使用：     
&emsp;&emsp;&emsp;&emsp;sizeof + 变量   
&emsp;&emsp;&emsp;&emsp;sizeof + (类型)      
11.通过指针可直接访问变量的内存地址，进而可以改变变量的值，尤其是在参数传递方面      
12.lvalue，即"左值"，可以表示对象，即具有对应的可以由用户访问的存储单元，操作符中的一些操作数也需要是左值    
13.类型：     
&emsp;&emsp;p1:int*;    
&emsp;&emsp;p2:int;    
14.bool \*pFlag = ...;    
15.基本操作：    
&emsp;&emsp;&，取地址，可以取得变量在内存中的地址，指针进而指向该地址，即指向该变量    
&emsp;&emsp;\*，解引用，可以取得指针所指向内存中的地址处所储存的值  
dereferencing，"提取"，即"解引用"         
16.区别：       
&emsp;&emsp;指针赋值，是指两个指针指向同一个地址，并没有复制值副本，改变一个另一个也同样变        
&emsp;&emsp;值赋值，是指值复制出一个副本，两个变量值相等，但本质不同，改变一个另一个不变     
17.四个图表依次为： 
         
PS:"-"前面是该地址变量名称，后面是该地址处的值（该地址未列出），且四个变量地址不一定连续     

<table>
	<tr>
		<td><table>
			<tr>
				<td>v1-10</td>
			</tr>
			<tr>
				<td>v2-25</td>
			</tr>
			<tr>
				<td>p1-&v1</td>
			</tr>
			<tr>
				<td>p2-&v2</td>
			</tr>
		</table></td>
		
		<td><table>
			<tr>
				<td>v1-35</td>
			</tr>
			<tr>
				<td>v2-25</td>
			</tr>
			<tr>
				<td>p1-&v1</td>
			</tr>
			<tr>
				<td>p2-&v2</td>
			</tr>
		</table></td>
			
		<td><table>
			<tr>
				<td>v1-35</td>
			</tr>
			<tr>
				<td>v2-25</td>
			</tr>
			<tr>
				<td>p1-&v1</td>
			</tr>
			<tr>
				<td>p2-&v1</td>
			</tr>
		</table></td>
			
		<td><table>
			<tr>
				<td>v1-70</td>
			</tr>
			<tr>
				<td>v2-25</td>
			</tr>
			<tr>
				<td>p1-&v1</td>
			</tr>
			<tr>
				<td>p2-&v1</td>
			</tr>
		</table></td>
	</tr>
</table>

18.NULL，表示指针所指向的位置在内存中不存在，即该指针为空，不过有时编译器会将NULL转化为0，从而使得指针指向地址为0的内存地址           
19.call by reference，即"引用调用"，与"值调用"相对应，两者区别同指针赋值和值赋值类似          
20.结果依次为：             
&emsp;&emsp;double realArray[100] = {0.0};     
&emsp;&emsp;bool inUse[16] = {0};    
&emsp;&emsp;string lines[1000] = {"\0"};             
21.int squares[11] = {0};for(int i = 0;i < 11;i++){squares[i] = i * i;}                                 
22.allocated size >= effective size                                  
23.第一个元素地址图表：  
  
<table>
	<tr>
		<td>1000</td>
	</tr>
	<tr>
		<td>1001</td>
	</tr>
	<tr>
		<td>1002</td>
	</tr>
	<tr>
		<td>1003</td>
	</tr>
</table>
依次类推   delete[]
24.先定义二维数组     
第一行，直接定义二维数组第二维第一个元素    
第二行至第六行循环赋值      
第七行至第八行循环二维数组第二维的前两个元素，转化为大写后赋值   
25.计算机会先查找intArray的首地址，再偏移3个int长度，最后取得该偏移地址的地址      
26.false    
27.1040     
28.区别：
&emsp;&emsp;声明数组，会分配5个int长度的空间，数组指针指向首地址    
&emsp;&emsp;声明指针，只分配一个int空间，指针指向首地址     
29.步骤：
&emsp;&emsp;struct关键字 + record的name    
&emsp;&emsp;定义构成record的各种原子类型   
30.*(p).cost == p -> cost        
31.heap，即"堆"，是由函数库提供的，当使用动态函数去获得新的内存空间时，函数会先从堆中获取空间      
32.操作：     
&emsp;&emsp;new函数，会动态申请空间，堆如果有剩余空间，会返回相应大小的空间，以指针形式返回      
&emsp;&emsp;delete函数，会销毁废弃的空间，令指针指向NULL     
33.delete[]会对应的删除new出来的数组空间     
34.garbage collection，即"垃圾回收机制"，会自动检测堆中是否存在废弃的空间，如果存在，会自动销毁，维系堆空间的稳定    
    

  