/* 
 * TODO: put your own comments here. Also you should leave comments on
 * each of your methods.
 */

#include <math.h>
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
    if(image.getRGB(x, y) == newColor)
        return 0;
    else{
        image.setRGB(x, y, color);
    }
}

void personalCurriculum(Map<string, Vector<string>> & prereqMap,string goal) {
    // your code here
    cout << "[recursion personal curriculum called]" << endl;
}

string generate(Map<string, Vector<string> > & grammar, string symbol) {
    // your code here
    cout << "[recursion generate called]" << endl;
    return "";
}
