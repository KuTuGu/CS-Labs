/*
其他的代码被我手贱删了。。。
请自行脑补
默哀三行 
 
 
*/

//13
#include <iostream>
using namespace std;
typedef struct{
    string rank;
    string suit;
}Card;
Card NewCard(string rank,string suit);
string CardName(Card card);
const string rankT[13] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
const string suitT[4] = {"Clubs","Diamonds","Hearts","Spades"};
int main()
{
    int index = 0;
    srand(int(time(NULL)));
    cout << "This program initializes, shuffles, and displays a deck of playing cards.\n\n";
    string str[52];
    for(int i = 0;i < 13;i++){
        for(int j = 0;j < 4;j++){
            Card card = NewCard(rankT[i],suitT[j]);
            str[index] = CardName(card);
            while(4 - str[index].length())
                str[index] = " " + str[index];
            index++;
        }
    }
    for(int i = 0;i < 52;i++){
        index = rand() % (52 - index) + index + 1;
        string temp = str[i];
        str[i] = str[index];
        str[index] = temp;
    }
    for(int i = 0;i < 52;i++){
        cout << str[i];
        if(i % 13 == 12)
            cout << endl;
    }
    return 0;
}
Card NewCard(string rank,string suit){
    Card newcard;
    newcard.rank = rank;
    newcard.suit = suit;
    return newcard;
}
string CardName(Card card){
    return (card.rank.length() > 2) ? (card.rank.substr(0,1) + card.suit.substr(0,1)) : (card.rank + card.suit.substr(0,1));
}

