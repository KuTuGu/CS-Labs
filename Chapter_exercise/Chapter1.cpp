/*Chapter1
  Programming exercises
*/

//1
#include <iostream>
using namespace std;
int main()
{
    double degree;
    cin >> degree;
    cout << 9.0 / 5 * degree + 32 << endl;
    return 0;
}
//2
#include <iostream>
using namespace std;
int main()
{
    double distance;
    cin >> distance;
    cout << "convert to inch: " << distance /  0.0254 << " inches" << endl;
    cout << "convert to foot: " << distance /  0.0254 / 12 << " feet" << endl;
    return 0;
}
//3
#include <iostream>
using namespace std;
int main()
{
    int sum = 0;
    for(int i = 0;i < 101;i++){
        sum += i;
    }
    cout << sum << endl;
    return 0;
}
//4
#include <iostream>
using namespace std;
int main()
{
    int N,sum = 0;
    cin >> N;
    for(int i = 1;i < 2 * N;i += 2){
        sum += i;
    }
    cout << sum << endl;
    return 0;
}
//5
#include <iostream>
using namespace std;
int main()
{
    int N,max = 0;
    while(1){
        cin >> N;
        if(N == 0)
            break;
        if(N > max)
            max = N;
    }
    cout << "The largest value is " << max << endl;
    return 0;
}
//6
#include <iostream>
using namespace std;
long Reverse(long n);
int main()
{
    long N;
    cout << "This program reverses the digits in an integer." << endl;
    cout << "Enter a positive integer: ";
    cin >> N;
    cout << "The largest value is " << Reverse(N) << endl;
    return 0;
}
long Reverse(long n){
    int rev = 0;
    while (n > 0) {
        rev += n % 10;
        n /= 10;
        if(n != 0)
            rev *= 10;
    }
    return rev;
}
//7
#include <iostream>
using namespace std;
bool IsPerfect(int n);
int main()
{
    for(int i = 1;i < 10000;i++){
        if(IsPerfect(i))
            cout << i << endl;
    }
    return 0;
}
bool IsPerfect(int n){
    int sum = 0;
    for(int i = 1;i <= n / 2;i++){
        if(n % i == 0){
            sum += i;
        }
    }
    if(sum == n)
        return true;
    return false;
}
//8
#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(int n);
int main()
{
    int n,flag = 0;
    cout << "Enter number to be factored: ";
    cin >> n;
    if(isPrime(n)){
        cout << n << endl;
        return 0;
    }
    for(int i = 2;n != 1;){
        if(n % i == 0){
            if(isPrime(i)){
                n /= i;
                if(flag == 0){
                    cout << i;
                    flag = 1;
                }
                else
                    cout << " * " << i;
            }
        }
        else
            i++;
    }
    return 0;
}
bool isPrime(int n){
    int end = sqrt(n);
    if(n < 2)
        return false;
    for(int i = 2;i <= end;i++){
        if(n % i == 0)
            return false;
    }
    return true;
}
//9
#include <iostream>
using namespace std;
int Round(double x);
int main()
{
    int n;
    cout << "Input a floating-point number: ";
    cin >> n;
    cout << "Round(n) is " << Round(n) <<endl;
    return 0;
}
int Round(double x){
    return x > 0 ? int(x + 0.5) : int(x - 0.5);
}
//10
#include <iostream>
using namespace std;
int main()
{
    double result = 0.0;
    for(int i = 1;i < 20000;i += 2){
        double num = 1.0/ i;
        if((i + 1) % 4 == 0)
            num *= -1;
        result += num;
    }
    cout << result <<endl;
    return 0;
}
//11
#include <iostream>
#include <math.h>
using namespace std;
const int RADIUS = 1;
const double WIDTH = 0.01;
int main()
{
    double area = 0.0;
    for(int i = 0;i < 100;i++){
        double height = sqrt(1 - pow(((i + 0.5) * WIDTH),2));
        area += height * WIDTH;
    }
    cout << area <<endl;
    return 0;
}
//12
#include <iostream>
using namespace std;
const string DIGIT[20] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
const string CARRY[8] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
void output(int n,bool wrap);
int main()
{
    int num;
    cout << "Enter numbers in figures; use a negative value to stop." << endl;
    while(1){
        cout << "Number: ";
        cin >> num;
        if(num > 999999)
            cout << "It is too big,please input again" << endl;
        else if(num < 0)
            break;
        else if(num >= 0 && num <= 19)
            cout << DIGIT[num] << endl;
        else{
            output(num,true);
        }
    }
    return 0;
}
void output(int n,bool wrap){
    int left,flag = 0;
    if((left = n / 1000)){
        flag = 1;
        output(left,false);
        if((n %= 1000))
            cout << " thousand ";
        else
            cout << " thousand";
    }
    if((left = n / 100)){
        if((n %= 100))
            cout << DIGIT[left] << " hundred ";
        else
            cout << DIGIT[left] << " hundred";
    }
    if(n > 19){
        if(n % 10)
            cout << CARRY[n / 10 - 2] << "-" << DIGIT[n % 10];
        else
            cout << CARRY[n / 10 - 2];
    }
    else if(n)
        cout << DIGIT[n];
    if(wrap)
        cout << endl;
}

