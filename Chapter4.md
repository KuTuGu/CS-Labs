# Chapter4
## Review questions
1.true          
2.advantages：         
&emsp;&emsp;Simplicity     
&emsp;&emsp;Flexibility     
&emsp;&emsp;Security      
3.Standard Template Library，即"标准样板库"，含有一系列特殊数据结构类       
4.#include "vector.h"     
5.advantages：     
&emsp;&emsp;可以方便地取得数组边界     
&emsp;&emsp;vector扩展了数组的操作     
&emsp;&emsp;。。。   
6.bounds-checking，即"边界检查"，以防访问超出边界之外的值     
7.vector<bool> vec;     
8.false     
9.vec.size();    
10.都是0 - N-1     
11.操作符重载    
12.方便更改原地址的值，而不是更改副本     
13.steps：     
```js
	grid<char> chessboard(8,8);
	for(int i = 0;i < 8;i++){
		for(int j = 0;j < 8;j++){
			chessboard[i][j] = '\0';
		}
	}  
```
14.steps：     
```js
	grid<char> chessboard(8,8);
	for(int i = 0;i < 8;i++){
		for(int j = 0;j < 8;j++){
			if(i == 7 && (j == 0 || j == 7))
				chessboard[i][j] = 'R';
			else
				chessboard[i][j] = '\0';
		}
	}  
```
15.缩写：    
&emsp;&emsp;LIFO，即"后进先出",应用于"栈"        
&emsp;&emsp;FIFO，即"先进先出",应用于"队列"        
16.push(value)和pop()         
17.enqueue(value)和dequeue()      
18.作用：    
&emsp;&emsp;stack，返回栈顶元素，不移除     
&emsp;&emsp;queue，返回队列头元素，不移除       
19.peek()    
20.discrete time，即"离散时间"，引入模型中的所有事件以离散时间单位发生，在单个时间单位内发生的多于一个事件的概率可以忽略不计......不懂             
21.true         
22.false    
23.报错      
24.句法简化：    
&emsp;&emsp;get: arr[key];                
&emsp;&emsp;put: arr[key] = value;      
25.一些情况下可以使用简化的Lexicon类，节省空间，提高效率      
26.files:    
&emsp;&emsp;text文件    
&emsp;&emsp;预编译文件    
27.分割字符串     
28.对于一些特殊的字符是否有新的操作，还是原样保存为字符串       
29.iterator，即"迭代器"，用于循环迭代      
30.违背这两种类的设计初衷233333           
31.steps：    
```js
	 Lexicon::Iterator iter = english.iterator();
      while (iter.hasNext()) {
          string word = iter.next();
			//code to work with that word
	}
```
32.steps：     
```js 
	foreach(int i in english){
	 	//code to work with that word
	}
```
33.优点：     
&emsp;&emsp;节省代码   
&emsp;&emsp;方便他人理解        
34.false    
35.true    
36.空格也会被当作字符串     