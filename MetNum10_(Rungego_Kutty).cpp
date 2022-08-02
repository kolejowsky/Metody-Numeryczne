#include <iostream>
#include <iomanip>

using namespace std;

float f(float x, float y);
float y(float x);
float RK4(float a, float b, float x0, float y0, int n, int i);


int main()
{
    float pocz = -1;
    float kon = 1;
    float x0 = -1;
    float y0 = 2;
    float n = 10;
    RK4(pocz, kon, x0, y0, n, 0);

}
float f(float x, float y)
{
    return -(y * y);
}

float y(float x)
{
    return (1 / (x + (3.0 / 2)));
}

float RK4(float a, float b, float x0, float y0, int n, int i)
{   
    float h = (b - a) * 1.0 / n * 1.0;
    float k1 = h * f(x0, y0);
    float k2 = h * f((x0 + (0.5 * h)), (y0 + (0.5 * k1)));
    float k3 = h * f((x0 + (0.5 * h)), (y0 + (0.5 * k2)));
    float k4 = h * f((x0 + h), (y0 + k3));
    
    
    int yi= y0+((k1 + 2 * k2 + 2 * k3 + k4) / 6.0);
    int xi = x0 + h;
    i++;
    if (i == 0)
    {
        cout << "----x----y----" << endl;
        cout << "   " << x0 << "    " << y0 << "    " << endl;
    }
    //cout << "   " << xi << "    " << yi << "    " << endl;
    /*cout << "h" << i << " = " << h << endl;
    cout << "k1 " << i << " = " << k1 << endl;
    cout << "k2 " << i << " = " << k2 << endl;
    cout << "k3 " << i << " = " << k3 << endl;
    cout << "k4 " << i << " = " << k4 << endl;
    cout << "x " << i << " = " << xi << endl;
    cout <<"y " << i << " = " << yi << endl;*/
    
    if (i < n)
    {
        return RK4(a, b, xi, yi, n, i);
    }
    return yi;

}
