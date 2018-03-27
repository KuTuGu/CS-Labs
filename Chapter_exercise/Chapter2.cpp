/*
 Chapter2
 Programming exercises
*/

//1
#include <iostream>
using namespace std;
const string week[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
enum weekdayT{
  Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday
};
string NextDay(weekdayT day);
string PreviousDay(weekdayT day);
string IncrementDay(weekdayT day,int delta);
int main() {
    weekdayT day = Monday;
    cout << PreviousDay(day) << endl;
    cout << NextDay(day) << endl;
    cout << IncrementDay(day,-15) << endl;
    return 0;
}
string NextDay(weekdayT day){
    return week[(day + 1) % 7];
}
string PreviousDay(weekdayT day){
    return week[int(day)];
}
string IncrementDay(weekdayT day,int delta){
    if(delta >= 0)
        return week[(day + delta) % 7];
    else{
        if(abs(delta) > day)
            return week[7 - (abs(delta) - day) % 7];
        else
            return week[(day + delta) % 7];
    }
}
//2
#include <iostream>
#define π 3.14
using namespace std;
void read(double *height,double *radius);
void compute(double height,double radius,double *surface,double *volume);
void display(double surface,double volume);
int main(){
    double height,radius,surface,volume;
    read(&height,&radius);
    compute(height,radius,&surface,&volume);
    display(surface,volume);
    return 0;
}
void read(double *height,double *radius){
    cin >> *height >> *radius;
}
void compute(double height,double radius,double *surface,double *volume){
    *surface = 2 * π * height * radius;
    *volume = π * height * radius * radius;
}
void display(double surface,double volume){
    cout << "表面积是" << surface << endl;
    cout << "体积是" << volume << endl;
}
//3
/*
 * File: gymjudge.cpp
 * ------------------
 * This program averages a set of gymnastic scores.
 */


#include <iostream>
#include "genlib.h"
#include "simpio.h"
using namespace std;
// Constants
const int MAX_JUDGES = 100;
const double MIN_SCORE =   0.0;
const double MAX_SCORE  = 10.0;
//Private function prototypes
void ReadAllScores(double scores[], int nJudges);
double GetScore(int judge);
double Mean(double array[], int n);
//Main program


int main(){
    double scores[MAX_JUDGES];
    cout << "Enter number of judges: ";
    int nJudges = GetInteger();
    if (nJudges > MAX_JUDGES) Error("Too many judges");
    ReadAllScores(scores, nJudges);
    cout << "The average score is " << Mean(scores, nJudges) << endl;
    return 0;
}


/*
 * Function: ReadAllScores
 * Usage: ReadAllScores(scores, nJudges);
 * --------------------------------------
 * This function reads in scores for each of the judges.  The
 * array scores must be declared by the caller and must have
 * an allocated size that is at least as large as nJudges.
 * Because people tend to count starting at 1 rather than 0,
 * this program adds 1 to the argument to GetScore, which means
 * that the values the user sees will range from 1 to n instead
 * of between 0 and n-1.
 */

void ReadAllScores(double scores[], int nJudges) {
    for (int i = 0; i < nJudges; i++) {
        scores[i] = GetScore(i + 1);
    }
}



/*
 * Function: GetScore
 * Usage: score = GetScore(judge);
 * -------------------------------
 * This function reads in the score for the specified judge.
 * The implementation makes sure that the score is in the
 * legal range before returning.
 */


double GetScore(int judge) {
    while (true) {
        cout << "Score for judge #" << judge << ": ";
        double score = GetReal();
        if (score >= MIN_SCORE && score <= MAX_SCORE) return score;
        cout << "That score is out of range.  Try again." << endl;
    } }

 
/*
 * Function: Mean
 * Usage: mean = Mean(array, n);
 * -----------------------------
 * This function returns the statistical mean (average) of a
 * distribution stored in array, which has effective size n.
 */


double Mean(double array[], int n) {
    double total = 0,max = -1,min = 101,maxi,mini;
    for (int i = 0; i < n; i++) {
        if(array[i] > max){
            max = array[i];
            maxi = i;
        }
        if(array[i] < min){
            min = array[i];
            mini = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if(i != maxi && i != mini)
            total += array[i];
    }
    return total / n;
}
//4
#include <iostream>
using namespace std;
bool IsSorted(int array[],int n);
int main(){
    int a[5] = {1,2,3,4,5};
    cout << boolalpha << IsSorted(a,5) << endl;
    return 0;
}
bool IsSorted(int *array,int n){
    for(int i = 0;i < n - 1;i++){
        if(array[i] > array[i + 1])
            return false;
    }
    return true;
}
//5
#include <iostream>
using namespace std;
int main(){
    int j = 1;
    int list[1000] = {0};
    while(j++ < 1000){
        for(int i = j + 1;i < 1001;i++){
            if(i % j == 0)
                list[i] = 1;
        }
    }
    for(int i = 2;i < 1001;i++){
        if(!list[i])
            cout << i << endl;
    }
    return 0;
}
//6
#include <iostream>
#include <iomanip.h>
using namespace std;
int main(){
    int digit[] = {100, 95, 47, 88, 86, 92, 75, 89, 81, 70, 55, 80};
    int list[11] = {0};
    for(int i = 0;i < 12;i++){
        if(digit[i] == 100)
            list[10]++;
        else
            list[digit[i] / 10 % 10]++;
    }
    for(int i = 0;i < 11;i++){
        cout << setw(3) << i * 10 << ": ";
        while(list[i]--)
            cout << "*";
        cout << endl;
    }
    return 0;
}
//7
#include <iostream>
using namespace std;
int main(){
    int digit[12] = {100, 95, 47, 88, 86, 92, 75, 89, 81, 70, 55, 80};
    int list[11] = {0},max = 0;
    for(int i = 0;i < 12;i++){
        if(digit[i] == 100)
            list[10]++;
        else
            list[digit[i] / 10 % 10]++;
    }
    for(int i = 0;i < 11;i++){
        if(list[i] > max)
            max = list[i];
    }
    for(;max > 0;max--){
        int flag = 0;
        for(int i = 0;i < 11;i++){
            if(list[i] == max){
                list[i]--;
                while(flag++ < (i + 1) * 3 - 2)
                    cout << " ";
                cout << "*";
            }
        }
        cout << endl;
    }
    for(int i = 0;i < 11;i++){
        cout << " " << i * 10;
    }
    cout << endl;
    return 0;
}
//8
#include <iostream>
using namespace std;
void RemoveZeroElements(int array[],int *n);
int main(){
    int array[13] = {65,0,95,0,0,79,82,0,84,94,86,90,0};
    int length = 13;
    RemoveZeroElements(array,&length);
    cout << length << endl;
    for(int i = 0;i < length;i++){
        if(i)
            cout << " " << array[i];
        else
            cout << array[i];
    }
    cout << endl;
    return 0;
}
void RemoveZeroElements(int array[],int *n){
    int length = 0;
    for(int i = 0;i < *n - length;i++){
        if(array[i] == 0){
            for(int j = i;j < *n - 1 - length;j++)
                array[j] = array[j + 1];
            length++;
            i--;
        }
    }
    *n -= length;
}
//9
#include <iostream>
using namespace std;
void InitCheckerboard(char array[8][9]);
void DisplayCheckerboard(char array[8][9]);
int main(){
    char array[8][9] = {'0'};
    InitCheckerboard(array);
    DisplayCheckerboard(array);
    return 0;
}
void InitCheckerboard(char array[8][9]){
    for(int i = 0;i < 8;i++){
        for(int j = 0;j< 8;j++){
            if(i % 2){
                if(j % 2)
                    array[i][j] = ' ';
                else{
                    if(i == 1)
                        array[i][j] = 'b';
                    else if(i == 3)
                        array[i][j] = '-';
                    else
                        array[i][j] = 'r';
                }
            }
            else{
                if(j % 2){
                    if(i < 3)
                        array[i][j] = 'b';
                    else if(i == 4)
                        array[i][j] = '-';
                    else
                        array[i][j] = 'r';
                }
                else
                    array[i][j] = ' ';
            }
        }
    }
}
void DisplayCheckerboard(char array[8][9]){
    for(int i = 0;i < 8;i++){
        for(int j = 0;j< 8;j++){
            cout << array[i][j];
        }
        cout << endl;
    }
}
//10
#include <iostream>
using namespace std;
int main(){
    double digit,max = -1,min = 0,flag = 0;
    cout << "Enter the elements of the array, one per line.\nUse -1 to signal the end of the list." << endl;
    while(1){
        cin >> digit;
        if(digit == -1)
            break;
        if(!flag){
            min = digit;
            flag++;
        }
        if(digit > max)
            max = digit;
        if(digit < min)
            min = digit;
    }
    cout << "The range of values is " << min << "-" << max << endl;
    return 0;
}
//11
#include <iostream>
using namespace std;
int *IndexArray(int n);
int main(){
    int *array = IndexArray(8);
    for(int i = 0;i < 8;i++){
        if(!i)
            cout << array[i];
        else
            cout << " " << array[i];
    }
    cout << endl;
    return 0;
}
int *IndexArray(int n){
    int *array = new int[n];
    for(int i = 0;i < n;i++){
        *(array + i) = i;
    }
    return array;
}
//12
#include <iostream>
using namespace std;
struct employeeRecordT{
    string name;
    string title;
    string ssnum;
    double salary;
    int withholding;
};
struct payrollT{
    int num;
    employeeRecordT *employ;
};
payrollT GetPayroll();
int main(){
    payrollT pay = GetPayroll();
    for(int i = 0;i < pay.num;i++){
        cout << i + 1 << endl;
        cout << pay.employ[i].name << endl;
        cout << pay.employ[i].title << endl;
        cout << pay.employ[i].ssnum << endl;
        cout << pay.employ[i].salary << endl;
        cout << pay.employ[i].withholding << endl;
    }
    return 0;
}
payrollT GetPayroll(){
    int num;
    cout << "How many employees: ";
    cin >> num;
    employeeRecordT *employees = new employeeRecordT[num];
    for(int i = 0;i < num;i++){
        cout << "Employee #" << i + 1 << ":" << endl;
        cout << "Name: ";cin >> employees[i].name;
        cout << "Title: ";cin >> employees[i].title;
        cout << "SSNum: ";cin >> employees[i].ssnum;
        cout << "Salary: ";cin >> employees[i].salary;
        cout << "Withholding exemptions: ";cin >> employees[i].withholding;
    }
    payrollT pay;
    pay.num = num;
    pay.employ = employees;
    return pay;
}

//13
/*
 这里要用到第12题的payrollT类型
 该源码假设在payrollT已存在的情况下所写
 但因为实际没有定义payrollT类型，故无法正常运行
*/
#include <iostream>
#include <iomanip.h>
using namespace std;
int main(){
    cout << "Name                    Gross Tax Net" << endl;
    cout << "--------------------------------------" << endl;
    for(int i  = 0;i < pay.num;i++){
        double tax = (pay.employ[i].salary - (pay.employ[i].withholding * 1)) * 0.25;
        double net_pay = pay.employ[i].salary - tax;
        cout << pay.employ[i].name;
        while(14 - pay.employ[i].name.size())
            cout << " ";
        cout << setw(10) << pay.employ[i].salary << " - ";
        cout << setw(5) << tax << " = ";
        cout << setw(6) << net_pay << endl;
    }
    return 0;
}
//14
#include <iostream>
using namespace std;
struct libraryT{
    string title;
    string authors[5];
    int catalog;
    string subjects[5];
    string publisher;
    int publication;
    bool circulating;
};
void SearchBySubject(libraryT *libdata,string subject);
int main(){
    return 0;
}
void SearchBySubject(libraryT *libdata,string subject){
    for(int i = 0;i < 1000;i++){
        if(!libdata[i].publication)
            break;
        for(int j = 0;j < 5;j++){
            if(libdata[i].subjects[j] == subject){
                cout << libdata[i].title << libdata[i].authors[0] << libdata[i].catalog << endl;
                break;
            }
        }
        
    }
}
//15
#include <iostream>
using namespace std;
int *GetDynamicIntegerArray(int sentinel,int &n);
int main(){
    int length = 0,sentinel;
    int *array;
    cin >> sentinel;
    array = GetDynamicIntegerArray(sentinel,length);
    cout << length << endl;
    return 0;
}
int *GetDynamicIntegerArray(int sentinel,int &n){
    int digit;
    int *p = new int;
    for(int i = 0;;i++){
        cin >> digit;
        if(digit == sentinel)
            break;
        *(p + i) = digit;
        n++;
    }
    return p;
}
