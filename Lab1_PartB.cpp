#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){

    //读取用户输入
    int N, num;
    cout << "Welcome to CS 106B Random Writer ('N-Grams').\n";
    cout << "This program makes random text based on a document.\n";
    cout << "Give me an input file and an 'N' value for groups of words, and I'll create random text for you.\n\n";
    string file;
    cout << "Input file? ";
    cin >> file; 
    while(1){
        cout << "Value of N? ";
        cin >> N;
        if(N > 1)
            break;
        else
            cout << "Please input valid interger.\n";
    }
    while(1){
        cout << "\n# of random words to generate (0 to quit)? ";
        cin >> num;
        if(!num)
            break;
        else if(num < N){
            cout << "Please input valid interger.\n";
            continue;
        }
        else{
            //以字符串为键值,字符串数组为值储存
            map<string,vector<string> > mymap;
            string str;
            fstream read(file);
            //读取成功
            if(!read.fail()){
                int flag = 0,index = 0;
                string *initial = new string;
                string key;
                while(1){
                    char ch;
                    read >> str;
                    read.get(ch);
                    if(ch == -1)
                        break;
                    else
                       read.unget(); 
                    cout << str + "...\n";

                    //构建字符串键值
                    /*for(int i = 0;i < N;i++){
                        read >> str;
                        //如果是第一次循环，储存前N个字符串
                        if(!flag)
                            *(initial + i) = str;
                        //如果读取到文件结束
                        if(str == "")
                            str = *(initial + index++);
                        if(!i)
                            key = str;
                        else
                            key += (" " + str); 
                    }
                    flag = 1;
                    cout << key + "...\n";
                    //如果利用了备用字符串，说明是最后一次读取
                    if(index)
                        break;*/
                }
              
            }
            else{
              cout << "The file reading has problem.Try again.\n";
            }
        }
    } 
    return 0;
}