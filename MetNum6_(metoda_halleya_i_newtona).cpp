#include <iostream>
#include <cmath>

using namespace std;

float f(float x)
{
    //return pow(x,3) + 4 * pow(x,2) - 10;
    //return pow(x, 4) - 9 * pow(x, 3) - 15;
    //return pow(x, 3) + 27;

    return pow(x, 2) - 9 * sin(x);
}

float fp(float x)
{
    return 2 * x - 9 * cos(x);
}

float fpp(float x)
{
    return 2 + 9 * sin(x);
}

float bisekcja(float a, float b, int licznik, float dokladnosc);
float halley(float a, float b, float x0, int licznik,  float dokladnosc);
float newton_raphson(float a, float b, float x0, int licznik, float dokladnosc);


int main()
{
    float a = 1;
    float b = 10;
    float l = 1;
    float eps = 0.000001;
    cout << "bisekcja: " << bisekcja(a, b, l, eps) << endl;
    cout << "halley: " << halley(a, b, (a+b)/2, l, eps) << endl;
    cout << "newton_raphson: " << newton_raphson(a, b, (a+b)/2, l, eps) << endl;
}


float bisekcja(float a, float b, int licznik, float dokladnosc)
{
    licznik++;
    //cout << licznik << endl;

    if (f(a) * f(b) >= 0)
    {
        return -999;
    }
    else if (f(a) * f(b) == 0)
    {
        if (f(a) == 0)
        {
            return a;
        }
        else if (f(b) == 0)
        {
            return b;
        }
    }

    float c = (b + a) / 2;
    //cout << "c= " << c << " f(c)= " << f(c) << " a= " << a << " b= " << b << endl;
    if (f(c) == 0 || licznik > 100 || fabs(b - a) <= dokladnosc)
    {
        return c;
    }

    if (f(a) * f(c) < 0)
    {
        return bisekcja(a, c, licznik, dokladnosc);
    }
    else if (f(c) * f(b) < 0)
    {
        return bisekcja(c, b, licznik, dokladnosc);
    }
    return -999;
}

float halley(float a, float b, float x0, int licznik, float dokladnosc)
{
    licznik++;
    //cout << licznik << endl;
    //1.
    if (f(a) * f(b) >= 0)
    {
        return -999;
    }

    float xi = x0 - (2*f(x0)*fp(x0))/((2*pow(2*fp(x0),2))-(fpp(x0)*f(x0)));
    //cout << "c= " << c << " f(c)= " << f(c) << " a= " << a << " b= " << b << endl;
    if (f(xi) == 0 || licznik > 100 || f(xi) <= dokladnosc)
    {
        return xi;
    }

    return halley(a, b, xi, licznik, dokladnosc);
   
}

float newton_raphson(float a, float b, float x0, int licznik, float dokladnosc)
{
    licznik++;
    //cout << licznik << endl;
    //1.
    if (f(a) * f(b) >= 0)
    {
        return -999;
    }

    float xi = x0 - f(x0)/fp(x0);
    //cout << "c= " << c << " f(c)= " << f(c) << " a= " << a << " b= " << b << endl;
    if (f(xi) == 0 || licznik > 100 || f(xi) <= dokladnosc)
    {
        return xi;
    }

    return halley(a, b, xi, licznik, dokladnosc);

}