/* 
 * TODO: put your own comments here. Also you should leave comments on
 * each of your methods.
 */

#include <math.h>
#include <map>
#include "recursion.h"
#include "map.h"
#include "vector.h"
#include "set.h"
#include "gwindow.h"
#include "gobjects.h"
#include "tokenscanner.h"
using namespace std;

int gcd(int a, int b) {
    if(b == 0){
        cout << "gcd(" << a << ", " << b << ") = " << a << endl;
        return a;
    }
    else{
        cout << "gcd(" << a << ", " << b << ") = gcd(" << b << ", " << a % b << ")\n";
        return gcd(b, a % b);
    }
}

void serpinskii(GWindow &w, int leftX, int leftY, int size, int order) {
    if(order == 1){
        w.drawLine(leftX, leftY, leftX + size, leftY);
        w.drawLine(leftX, leftY, leftX + size / 2, leftY + sqrt(3) / 2 * size);
        w.drawLine(leftX + size / 2, leftY + sqrt(3) / 2 * size, leftX + size, leftY);
    }
    else{
        serpinskii(w, leftX, leftY, size / 2, order - 1);
        serpinskii(w, leftX + size / 2, leftY, size / 2, order - 1);
        serpinskii(w, leftX + size / 4, leftY + sqrt(3) / 4 * size, size / 2, order - 1);
    }
}

int floodFill(GBufferedImage& image, int x, int y, int newColor) {
    int num = 0;
    if(image.getRGB(x, y) == newColor)
        return num;
    else{
        image.setRGB(x, y, color);
        num++;
        if(image.inBounds(x, y) && image.getRGB(x + 1, y) == newColor)
            num += floodFill(image, x + 1, y, newColor);
        else if(image.inBounds(x, y) && image.getRGB(x - 1, y) == newColor)
            num += floodFill(image, x - 1, y, newColor);
        else if(image.inBounds(x, y) && image.getRGB(x, y + 1) == newColor)
            num += floodFill(image, x, y + 1, newColor);
        else
            num += floodFill(image, x, y - 1, newColor);
        return num;
    }
}

void personalCurriculum(Map< string, Vector<string> > &prereqMap, string goal) {
    map< string, Vector<string> >::iterator iter;
    if(prereqMap[goal]){
        Vector<string> before = prereqMap[goal];
        for(int i = 0;i < before.size();i++){
            personalCurriculum(prereqMap, before[i]);
            for(iter = prereqMap.begin(); iter != prereqMap.end(); iter++) {
                    Vector<string> value = iter->second;
                    for(int j = 0;j < value.size();j++){
                        if(value[j] == before[i])
                            value.removeAt(j);
                    }
                    prereqMap[iter->first] = value;
            }

        }
    }
    else
        cout << goal << endl;
}

string generate(Map< string, Vector<string> > &grammar, string symbol){
    Vector<string> vec;
    string str, result = "";
    if(grammar.find(symbol) != grammar.end()){
        vec = grammar[symbol];
        int random = randomReal(0, vec.size() - 1);
        str = vec[random];
        TokenScanner scanner(str);
        while (scanner.hasMoreTokens()) {
            string token = scanner.nextToken();
            result += generate(grammar, token);
        }
    }
    else
        result = symbol;
    return result;
}

