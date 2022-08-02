#include <iostream>
using namespace std;

int main(){
	
	    float x0 = 1;
    float y0 = 3.1;
    float x1 = 2;
    float y1 = 4.2;
    float x2 = 3;
    float y2 = 7.3;
    float x3 = 4;
    float y3 = 9.4;
    float x4 = 5;
    float y4 = 6.5;
    
     cout << "Podaj x = ";
    float x;
    cin >> x;
    
    float f0 = (y1-y0)/(x1-x0);
    float f1 = (y2-y1)/(x2-x1);
    float f2 = (y3-y2)/(x3-x2);
    float f3 = (y4-y3)/(x4-x3);
    float f01 = (f1-f0)/(x2-x0);
    float f12 = (f2-f1)/(x3-x1);
    float f23 = (f3-f2)/(x4-x2);
    float f012 = (f12-f01)/(x3-x0);
    float f123 = (f23-f12)/(x4-x1);
    float f0123=(f123-f012)/(x4-x0);
    
    float L = y0 + f0*(x-x0)+f01*(x-x0)*(x-x1)+f012*(x-x0)*(x-x1)*(x-x2)+f0123*(x-x0)*(x-x1)*(x-x2)*(x-x3);

cout << L;
}
