/*
    Chapter6
    Programming exercises
*/
//1
/*#include <iostream>
using namespace std;
int NHanoiMoves(int n);
int main()
{
    int n;
    cout << "Please input a number: ";
    cin >> n;
    cout << "The NHanoiMoves is " << NHanoiMoves(n) << endl;
    return 0;
}
int NHanoiMoves(int n){
    if(n == 1)
        return 1;
    else
        return 2 * NHanoiMoves(n - 1) + 1;
}
//2


//3



//4
#include <iostream>
using namespace std;
void RecursivePermute(string str,int index);
int main()
{
    RecursivePermute("ABCD",2);
    return 0;
}
void RecursivePermute(string str,int index) {
    if(index == str.length() - 1)
        cout << str << endl;
    else{
        for(int i = index;i < str.length();i++){
            string ch = str.substr(i,i + 1);
            string rest = str.substr(0,index) + ch + str.substr(index,i) + str.substr(i+1);
            RecursivePermute(rest,index + 1);
        }
    }
}
//5


//6
#include <iostream>
using namespace std;
void ListMnemonics(string digit);
const char CH[9] = {'A','D','G','J','N','P','T','W'};
int main()
{
    ListMnemonics("723");
    return 0;
}
void ListMnemonics(string digit){
    if(digit[0] >= 'A' && digit[0] <= 'Z')
        cout << digit << endl;
    else{
        if(digit[0] == '7' || digit[0] == '9'){
            for(int i = 0;i < 4;i++)
                ListMnemonics(digit.substr(1) + char(CH[digit[0] - '2'] + i));
        }
        else{
            for(int i = 0;i < 3;i++)
                ListMnemonics(digit.substr(1) + char(CH[digit[0] - '2'] + i));
        }
    }
}


//8
#include <iostream>
using namespace std;
void ListSubsets(string str);
int main()
{
    string str;
    cout << "This program lists all subsets of a set.\nEnter a string representing a set: ";
    cin >> str;
    ListSubsets(str);
    return 0;
}
void ListSubsets(string str){
    if(str[0] == '{')
        cout << str << endl;
    else{
        for(int i = 0;i < str,length();i++){

            ListSubsets(str);
        }
    }
}
*/


//9
#include <iostream>
using namespace std;
void GenerateBinaryCode(int nBits); 
int main()
{
    GenerateBinaryCode(3);
    return 0;
}
void GenerateBinaryCode(int nBits){
    if(nBits != 0){
        for(int i = 0;i < 2;i++){
            cout << i; 
            GenerateBinaryCode(nBits - 1); 
        }
    }
    else
        cout << endl;
}
/*
//10
#include <iostream>
using namespace std;
int main()
{
    return 0;
}
//11
#include <iostream>
using namespace std;
int main()
{
    return 0;
}
//12
#include <iostream>
using namespace std;
int main()
{
    return 0;
}
//13
#include <iostream>
using namespace std;
int main()
{
    return 0;
}
//14
#include <iostream>
using namespace std;
int main()
{
    return 0;
}
//15
#include <iostream>
using namespace std;
int main()
{
    return 0;
}*/