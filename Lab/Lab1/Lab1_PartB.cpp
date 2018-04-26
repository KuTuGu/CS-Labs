#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <time.h>
#include <stdlib.h>

using namespace std;

//根据文件读取所有单词
void getset(vector<string> &mywords, string file);

//遍历单词，构造字典
void getmap(map<string,vector<string> > &mymap, vector<string> myword, int N);

//输出结果
void getresult(map<string,vector<string> > mymap, int N, int num);

int main(){
    srand((int)time(NULL));
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

    //循环
    while(1){
        cout << "\n# of random words to generate (0 to quit)? ";
        cin >> num;
        
        //判断特殊情况
        if(!num)
            break;
        else if(num < N){
            cout << "Please input valid interger.\n";
            continue;
        }
        
        //正常条件
        else{
            //以字符串为键值,字符串数组为值储存
            map<string,vector<string> > mymap;
            string str,initial;
            vector<string> mywords;
            getset(mywords,file);
            if(mywords.empty()){
                cout << "Input file? ";
                cin >> file;
                continue;
            }
            getmap(mymap, mywords, N);
            getresult(mymap, N, num);
        }
    } 
    return 0;
}

void getset(vector<string> &mywords, string file){
    char ch;
    fstream read(file);
    //读取成功
    if(!read.fail()){
        while(1){
            string word = "";
            while((ch = read.get()) != EOF){
                if(ch != ' ' && ch != '\n')
                    word += ch;
                else
                    break;
            }
            if(word != "")
                mywords.push_back(word);
            if(ch == EOF)
                break;  
        }
    }
    else{
        cout << "The file reading has problem.Try again.\n";
    }
}

void getmap(map<string,vector<string> > &mymap, vector<string> myword, int N){
    int len = myword.size(),j;
    for(int i = 0;i < len;i++){
        string key = "";
        for(j = 0;j < N - 1;j++){
            if(!j)
                key +=  myword[(i + j) % len];
            else
                key +=  " " + myword[(i + j) % len];
        }
        if(mymap[key].empty()){
            vector<string> value;
            value.push_back(myword[(i + j) % len]);
            mymap[key] = value;
        }
        else
            mymap[key].push_back(myword[(i + j) % len]);
    }
}
void getresult(map<string,vector<string> > mymap, int N, int num){
    //随机数
    double domain = double(rand()) / (double(RAND_MAX) + 1);
    int index = int(mymap.size() * domain);
    //随机key
    map<string,vector<string> >::iterator iter;
    iter = mymap.begin();
    while(index--)
        iter++;
    //循环输出
    string key = iter->first, str;
    cout << "...";
    while(num-- > N){
        int flag = key.find(' ');
        str = key.substr(0,flag);
        cout << str + " ";
        index = int(mymap[key].size() * domain);
        str = mymap[key][index];
        key = key.substr(flag + 1) + " " + str;
        domain = double(rand()) / (double(RAND_MAX) + 1);
        index = int(mymap.size() * domain);
    }
    cout << key + " ";
    index = int(mymap[key].size() * domain);
    cout << mymap[key][index] << "...\n";
}
