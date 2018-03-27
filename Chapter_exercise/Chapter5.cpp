/*
 Chapter5
 Review questions部分，问题太弱智，不再一一作答
 Programming exercises
*/
//1
#include <iostream>
using namespace std;
int Cannonball(int floor);
int main(){
    int floor,num;
    cout << "Please input a floor: ";
    cin >> floor;
    num = Cannonball(floor);
    cout << "The total num is " << num << endl;
    return 0;
}
int Cannonball(int floor){
    if(floor == 1)
        return 1;
    else
        return floor * floor + Cannonball(floor - 1); 
}
//2
#include <iostream>
using namespace std;
int RaiseIntToPower(int n, int k);
int main(){
    int n,k;
    cout << "Please input two integers:\n";
    cin >> n >> k;
    cout << "The power is: " << RaiseIntToPower(n,k) << endl;
    return 0;
}
int RaiseIntToPower(int n, int k){
    if(!k)
        return 1;
    else
        return n * RaiseIntToPower(n,k - 1);
}
//3
#include <iostream>
using namespace std;
int GCD(int n,int k);
int main()
{
    int n,k;
    cout << "Please input two integers:\n";
    cin >> n >> k;
    int max = n > k ? n : k;
    int min = n > k ? k : n;
    cout << "The greatest common divisor is: " << GCD(max,min) << endl;
    return 0;
}
int GCD(int n,int k){
    if(!(n % k))
        return k;
    else
        return GCD(k,n % k);
}
//4
#include <iostream>
using namespace std;
int Fib(int n);
int main()
{
    int n;
    cout << "Please input a number: ";
    cin >> n;
    cout << "The fib is " << Fib(n) << endl;
    return 0;
}
int Fib(int n){
    if(n < 2)
        return n;
    int sum = 0,pre = 1,bre;
    for(int i = 0;i < n;i++){
        bre = sum;
        sum += pre;
        pre = bre;
    }
    return sum;
}
//5
#include <iostream>
#include <iomanip>
using namespace std;
int Fib1(int n);
int Fib2(int n);
void present(int n);
int main(){
    int n;
    cout << "Please input a number: ";
    cin >> n;
    present(n);
    return 0;
}
int Fib1(int n){
    if (n < 2)
        return 1;
    else 
        return Fib1(n - 1) + Fib1(n - 2) + 1;
}
int Fib2(int n){
    if (n < 3)
        return n + 2;
    else
        return Fib2(n - 1) + Fib2(n - 2) - Fib2(n - 3);
}
void present(int n){
    cout << "This program compares the performance of two algorithms to compute the Fibonacci sequence.\n\n";
    cout << "Number of calls:\n";
    cout << "   N     Fib1   Fib2\n";
    cout << "  --     ----   ----\n";
    for(int i = 0;i <= n;i++)
        cout << setw(4) << i << setw(9) << Fib1(i) << setw(7) << Fib2(i) << endl;
}
//6
#include <iostream>
#include <iomanip>
using namespace std;
int DigitSum(int n);
int main()
{
    int n;
    cout << "Please input a number: ";
    cin >> n;
    cout << "The DigitSum is " << DigitSum(n) << endl;
    return 0;
}
int DigitSum(int n){
    if(n < 10)
        return n;
    else
        return n % 10 + DigitSum(n / 10);
}
//7
#include <iostream>
#include <iomanip>
using namespace std;
int DigitSum(int n);
int DigitalRoot(int n);
int main()
{
    int n;
    cout << "Please input a number: ";
    cin >> n;
    cout << "The DigitalRoot is " << DigitalRoot(n) << endl;
    return 0;
}
int DigitSum(int n){
    if(n < 10)
        return n;
    else
        return n % 10 + DigitSum(n / 10);
}
int DigitalRoot(int n){
    if(n < 10)
        return n;
    else
        return DigitalRoot(DigitSum(n));
}
//8
#include <iostream>
#include <iomanip>
using namespace std;
int Combinations(int x,int y);
int main()
{
    int n,m;
    cout << "Please input two number: ";
    cin >> n >> m;
    cout << "The Combinations is " << Combinations(n,m) << endl;   
    return 0;
}
int Combinations(int x,int y){
    if((x == y) || !y)
        return 1;
    else
        return Combinations(x - 1,y - 1) + Combinations(x - 1,y);
}
//9
#include <iostream>
#include <iomanip>
using namespace std;
string Reverse(string str);
int main()
{
    cout << Reverse("program") << endl;
    return 0;
}
string Reverse(string str){
    if(str == "")
        return "";
    else
        return str.substr(str.length() - 1) + Reverse(str.substr(0,str.length() - 1));
}
//10
#include <iostream>
#include <iomanip>
using namespace std;
string IntegerToString(int integer);
int main()
{
    int n;
    cout << "Please input a number: ";
    cin >> n;
    cout << "The IntegerToString is " << IntegerToString(n) + "\n";
    return 0;
}
string IntegerToString(int integer){
    char *str = new char;
    if(integer < 10){
        *str = integer + '0';
        return str;
    }
    else{
        *str = integer % 10 + '0';
        return IntegerToString(integer / 10) + *str;
    }
}