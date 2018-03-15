/*
 Chapter4
 Programming exercises
*/
//1
#include <iostream>
#include <vector>
using namespace std;
void RemoveZeroElements(vector<int> & vec);
int main() {
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(1);
    RemoveZeroElements(arr);
    cout << arr[0] << " " << arr[1] << endl;
}
void RemoveZeroElements(vector<int> & vec){
    unsigned long len = vec.size();
    for(int i = 0;i < len;i++){
        if(vec[i] == 0)
            vec.erase(vec.begin() + i);
    }
}
//2
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
bool ReadVector(ifstream & infile, vector<double> & vec);
int main() {
    vector<double> roots;
    ifstream infile("/Users/apple/Downloads/muxi/CS_Labs/Chapter4_2.txt");
    if(infile.fail()){
        cout << "error";
        return 1;
    }
    cout << boolalpha << ReadVector(infile, roots) << endl;
    cout << boolalpha << ReadVector(infile, roots) << endl;
    cout << boolalpha << ReadVector(infile, roots) << endl;
    return 0;
}
bool ReadVector(ifstream & infile, vector<double> & vec){
    int flag = 0;
    while(1){
        string number;
        getline(infile,number);
        if((number == "\n" || number == "")){
            if(flag)
                break;
            return false;
        }
        flag = 1;
        vec.push_back(stod(number));
    }
    return true;
}
//3
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void SortTextFile(ifstream & infile, vector<string> & lines);
int main() {
    vector<string> lines; 
    ifstream infile("/Users/apple/Downloads/muxi/CS_Labs/Chapter4_3.txt");
    SortTextFile(infile,lines);
    for(int i = 0;i < lines.size();i++)
        cout << lines[i] << endl;
    return 0;
}
void SortTextFile(ifstream & infile, vector<string> & lines){
    while(1){
        string line;
        getline(infile,line);
        if(line == "")
            break;
        lines.push_back(line);
        for(int i = 1;i < lines.size();i++){
            if(lines[i - 1] > line){
                lines.insert(lines.begin() + i - 1,line);
                lines.pop_back();
                break;
            }
        }
    }
}
//4
#include <iostream>
#include <grid>
using namespace std;
bool CheckLine(Grid<char> & board, char mark, int row, int col,
               int dRow, int dCol, int size);
bool CheckForWin(Grid<char> & board, char mark, int size);           
int main() {
    return 0;
}
bool CheckLine(Grid<char> & board, char mark, int row, int col,
               int dRow, int dCol, int size) {
   for (int i = 0; i < size; i++) {
      if (board[row][col] != mark) return false;
      row += dRow;
      col += dCol;
}
   return true;
}
bool CheckForWin(Grid<char> & board, char mark, int size) {
    for (int i = 0; i < size; i++) {
        if (CheckLine(board, mark, i, 0, 0, 1,size)) return true;
        if (CheckLine(board, mark, 0, i, 1, 0,size)) return true;
    }
    if (CheckLine(board, mark, 0, 0, 1, 1,size)) return true;
    return CheckLine(board, mark, size - 1, 0, -1, 1,size);
}
//5
#include <iostream>
#include <vector>
using namespace std;
int Calcu(vector< vector<int> > & vec2D, int row, int col, int dRow, int dCol);
void Store(vector< vector<int> > & vec2D);
bool IsMagicSquare(vector< vector<int> > & vec2D);
vector<int> Sum;
int main()
{
    vector< vector<int> > vec2D;
    vector<int> vec;
    vec.push_back(8);
    vec.push_back(1);
    vec.push_back(6);
    vec2D.push_back(vec);
    vec.clear();
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(7);
    vec2D.push_back(vec);
    vec.clear();
    vec.push_back(4);
    vec.push_back(9);
    vec.push_back(2);
    vec2D.push_back(vec);
    cout << boolalpha << IsMagicSquare(vec2D) << endl;
    return 0;
}
int Calcu(vector< vector<int> > & vec2D,int row, int col, int dRow, int dCol) {
    int sum = 0;
    for(int i = 0; i < vec2D[0].size(); i++){
        sum += vec2D[row][col];
        row += dRow;
        col += dCol;
    }
    return sum;
}
void Store(vector< vector<int> > & vec2D){
    for (int i = 0; i < vec2D[0].size(); i++) {
        Sum.push_back(Calcu(vec2D, i, 0, 0, 1)); 
        Sum.push_back(Calcu(vec2D, 0, i, 1, 0));
    }
    Sum.push_back(Calcu(vec2D, 0, 0, 1, 1));
    Sum.push_back(Calcu(vec2D, vec2D[0].size() - 1, 0, -1, 1));
}
bool IsMagicSquare(vector< vector<int> > & vec2D){
    if(vec2D[0].size() != vec2D.size())
        return false;
    for(int i = 0;i < vec2D.size() - 1;i++){
        if(vec2D[i].size() != vec2D[i + 1].size())
            return false;
    }
    Store(vec2D);
    for(int i = 0;i < Sum.size() - 1;i++){
        if(Sum[i] != Sum[i + 1])
            return false;
    }
    return true;
}
//6
#include <iostream>
#include <vector>
using namespace std;
bool Store_check(vector< vector<int> > & vec2D, int row, int col, int dRow, int dCol);
bool CheckSudokuSolution(vector< vector<int> > & vec2D);
int main()
{
    //不想试了...
    return 0;
}
bool Store_check(vector< vector<int> > & vec2D, int row, int col, int dRow, int dCol){
     vector<int> & vec(9,0);
    for(int i = 0; i < 9; i++){
        vec[vec2D[row][col]] = 1;
        row += dRow;
        col += dCol;
    }
    for(int i = 1; i < 10; i++){
        if(!vec[i])
            return true;
    }
    return false;
}
bool CheckSudokuSolution(vector< vector<int> > & vec2D){
    for(int i = 0; i < vec2D[0].size(); i++){
        if(Store_check(vec2D, i, 0, 0, 1)) 
            return false;
        if(Store_check(vec2D, 0, i, 1, 0))
            return false;
    }
    for(int i = 1;i < 8; i += 3){
        for(int j = 1;j < 8; j += 3){
            vector<int> vec(9,0);
            vec[vec2D[i - 1][j - 1]] = 1;
            vec[vec2D[i - 1][j]] = 1;
            vec[vec2D[i - 1][j + 1]] = 1;
            vec[vec2D[i][j - 1]] = 1;
            vec[vec2D[i][j]] = 1;
            vec[vec2D[i][j + 1]] = 1;
            vec[vec2D[i + 1][j - 1]] = 1;
            vec[vec2D[i + 1][j]] = 1;
            vec[vec2D[i + 1][j + 1]] = 1;
            for(int i = 1; i < 10; i++){
                if(!vec[i])
                    return false;
            }
        }
    }
    return true;
}
//7
#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;
int main()
{
    stack<int> digit; 
    cout << "Enter a list of integers, ending with 0:\n";
    while(1){
        int num;
        cout << "> ";
        cin >> num;
        if(!num)
            break;
        else
            digit.push(num);
    }
    if(!digit.empty())
        cout << "Those integers in reverse order are:\n";
    while(!digit.empty()){
        int num = digit.top();
        digit.pop();
        cout << setw(4) << num << endl;
    }
    return 0;
}
//8
#include <iostream>
#include <stack>
#include <map>
using namespace std;
int main()
{
    map<char,char> dict;
    dict['}'] = '{';
    dict[')'] = '(';
    dict[']'] = '[';
    stack<char> result,character;
    string str;
    cout << "Please input a string to checks whether the bracketing operators in the string are properly matched:\n";
    cin >> str;
    for(int i = 0;i < str.length();i++){
        if(str[i] == '{' || str[i] == '[' || str[i] == '(')
            character.push(str[i]);
        else if(str[i] == '}' || str[i] == ']' || str[i] == ')'){
            while(1){
                char ch = character.top();
                character.pop();
                if(ch == dict[str[i]])
                    break;
                result.push(ch);
            }
        }
    }
    while(!character.empty()){
        char ch = character.top();
        character.pop();
        result.push(ch);
    }
    cout << result.size() << endl;
    return 0;
}
//9
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void ReverseQueue(queue<string> & que);
int main()
{
    queue<string> que;
    que.push("123");
    que.push("456");
    ReverseQueue(que);
    cout << que.front();
    return 0;
}
void ReverseQueue(queue<string> & que){
    stack<string> sta;
    for(int i = 0;i < que.size();i++){
        sta.push(que.front());
        que.pop();
    }
    for(int i = 0;i < sta.size();i++){
        que.push(sta.top());
        sta.pop();
    }
}
//10
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    
    return 0;
}
//11
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    
    return 0;
}
//12
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    
    return 0;
}
//13
/*
捕捉器不仅可以捕捉两个乒乓球，应该可以捕捉多个    
要记录乒乓球降落的位置，以后该位置仅接受球，不再发出球    
在随机的1-4次单位时间(循环)内，随机单位的一个球会被再次被发出
直到空中所有的球落下，循环停止  
要计算单位时间(循环)进行了多少次，计算出位置被击中的百分率和空中球数量的最大值
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //初始化空中的球数量和最大值
    int num = 1,max = 1;
    //随机种子的播种
    srand(int(time(NULL)));
    //二维数组储存球数量
    vector< vector<int> > vec2D(25);
    //该位置是否被击中
    vector<int> flag(625,0);
    //初始化每个位置的球数量
    for(int i = 0;i < 25;i++){
        vector<int> vec(25,2);
        vec2D[i] = vec;
    }
    //直到空中没有球，才停止循环
    while(num){
        //求随机的行、列
        double domain = double(rand()) % double(RAND_MAX + 1);
        int row = domain * 26;
        int col = domain * 26;
        //进行该位置的球数量的变化操作,......未完成
        if(vec2D[row][col] && !flag[row][col]){
            num += vec2D[row][col] - 1;
            vec2D[row][col] = 0;
            flag[row][col] = 1;
        }
        else if(vec2D[row][col]){
            num--;
            vec2D[row][col] = 1;
        }
        //随机循环抛出随机位置的一个球,......未完成
        //更改空中球数量最大值的操作
        if(num > max)
            max = num; 
        
    }
    return 0;
}
//14
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main()
{
    map<string,string> dict;
    string ch[27] = {"·-","-···","-·-·","-··","·","··-·","--·","····","··","·---","-·-","·-··","--","-·","---","·--·","--·-","·-·","···","-","··-","···-","·--","-··-","-·--","--··"};
    for(int i = 0;i < 27;i++)
        dict[ch[i]] = i + 'A';
    cout << "Morse code translator\n";
    while(1){
        cout << "> ";
        char a = cin.peek();
        if(a == '\n')
            break;
        if(isalpha(a)){
            string str;
            getline(cin,str);
            if(str == "")
                break;
            for(int i = 0;i < str.length();i++){
                if(isalpha(str[i])){
                    if(i)
                        cout << " ";
                    cout << ch[str[i] - 'A'];     
                }
            }
            cout << endl;
        }
        else{
            while(1){
                string str;
                char a = cin.peek();
                if(a == '\n'){
                    cin.get();
                    cout << endl;
                    break;
                }
                cin >> str;
                cout << dict[str];
            }
        }
    }
    return 0;
}
//15
//遍历即可，STL没有lexicon，自行脑补运行画面23333
//16
//略
//17
//不知道stod为什么报错
#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<string,double> symbolTable;
    string *keys = new string;
    int flag = 0;
    while(1){
        string str;
        cout << "> ";
        getline(cin,str);
        cout << str + "\n";
        if(str == "quit")
            break;
        else if(str.find("=")){
            int index = str.find("=");
            cout << str.substr(0,index - 1) << " " <<  stod(str.substr(index + 2)) << endl;
            symbolTable[str.substr(0,index - 1)] = stod(str.substr(index + 2));
            *(keys + flag) = str.substr(0,index - 1);
            flag++;
        }
        else if(str == "list"){
            cout << flag << "..." << endl;
            for(int i = 0;i < flag;i++){
               cout << keys[i] +  " = " << symbolTable[keys[i]] << endl;
            }
        }
        else{
            if(symbolTable[str] - int(symbolTable[str]))
                cout << symbolTable[str] << endl;
            else
                cout << int(symbolTable[str]) << endl; 
        }
    }
    return 0;
} 
//18
//自行脑补，STL没有Scanner库