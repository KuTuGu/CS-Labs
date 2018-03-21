#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <set>
using namespace std;

//每个字符可更换次数
const int ALPHA_LENGTH = 26;

//取得用户输入
void getWords(string &word1, string &word2);
//输出题目要求
void printWordLadder(string word1, string word2, string dict);

int main() {
    cout << "Welcome to CS 106B Word Ladder.\n";
    cout << "Please give me two English words, and I will change the first into the second by changing one letter at a time.\n\n";
    string word1, word2, dict;
    cout << "Dictionary file name? ";
    getline(cin, dict);
    cout << endl;
    while(1){
        getWords(word1, word2); 
        if(word1 != "" && word2 != "" && dict != "")
            printWordLadder(word1, word2, dict);
        else
            break;
    }
    cout << "Have a nice day.";
    return 0;
}

void getWords(string &word1, string &word2) {
    while (1) {
        cout << "Word #1 (or Enter to quit): ";
        getline(cin, word1);
        if(word1 == "")
            break;
        cout << "Word #2 (or Enter to quit): ";
        getline(cin, word2);
        if(word2 == "")
            break;
        if (word1.length() == word2.length())
            break;  
        cout << "Please enter two words with the same length." << endl;
    }
}

void printWordLadder(string word1, string word2, string dict){
    //新建队列
    queue<vector<string> > myQueue;
    vector<string> myVector;
    //添加开始单词
    myVector.push_back(word1);
    myQueue.push(myVector);
    //新建文件流，打开文件
    string token;
    ifstream dictionary(dict);
    //新建字典，储存文件中的单词
    set<string> myDictionary;
    //新建字典，储存已访问过的单词
    set<string> testedWords;
    //如果文件正常打开
    if(!dictionary.fail()) {
        //储存文件中的单词
        while (dictionary >> token)
            myDictionary.insert(token);
            //队列非空时，广度搜索
        while (!(myQueue.empty())) {
            //取出队列头元素
            vector<string> ladder = myQueue.front();
            myQueue.pop();
            string word = ladder.back();
            //访问最后一个元素,如果等于终点单词，直接输出前面的所有元素
            if (word == word2) {
                cout << "The ladder from " << word2 << " back to " << word1 << ":\n";
                for(int i = ladder.size() - 1; i > 0; i--)
                    cout << ladder[i] << " ";
                cout << ladder[0] << endl << endl;
                break;
            } 
            //不结束，则
            else {
                string test;
                for (int i = 0; i < word.size(); i++) {
                    for (char j = 'a'; j <= 'z'; j++) {
                        test = word.substr(0, i) + j + word.substr(i + 1);
                        //如果总单词中有该单词，且未访问过
                        if (myDictionary.count(test) && !testedWords.count(test)) {
                            vector<string> copy = ladder;
                            copy.push_back(test);
                            myQueue.push(copy);
                            testedWords.insert(test);
                        }
                    }
                }
            }
        }
        cout << "Sorry, there is no path.\n\n";
    }
    else
        cout << "Couldn't open the dictionary" << endl;
}