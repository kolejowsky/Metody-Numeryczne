#include <iostream>
#include <cmath>

using namespace std;

float f(float x)
{
    //return pow(x,3) + 4 * pow(x,2) - 10;
    return pow(x, 4) - 9 * pow(x, 3) - 15;
    //return pow(x, 3) + 27;
}

float bisekcja(float a, float b, int licznik, float dokladnosc);
float falsi(float a, float b, int licznik, float dokladnosc);
float sieczne(float a, float b, int licznik, float dokladnosc);


int main()
{
    float a = 6;
    float b = 10;
    float l = 1;
    float eps = 0.000001;
    cout << "bisekcja: " << bisekcja(a, b, l, eps) << endl;
    cout << "falsi: " << falsi(a, b, l, eps) << endl;
    cout << "siecznych: " << sieczne(a, b, l, eps) << endl;
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
float falsi(float a, float b, int licznik, float dokladnosc)
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

    float c = b-f(b)*((b-a)/(f(b)-f(a)));
    //cout << "c= " << c << " f(c)= " << f(c) << " a= " << a << " b= " << b << endl;
    if (f(c) == 0 || licznik > 100 || fabs(b - a) <= dokladnosc)
    {
        return c;
    }

    if (f(a) * f(c) < 0)
    {
        return falsi(a, c, licznik, dokladnosc);
    }
    else if (f(c) * f(b) < 0)
    {
        return falsi(c, b, licznik, dokladnosc);
    }
    return -999;
}

float sieczne(float a, float b, int licznik, float dokladnosc)
{
    licznik++;

    float x1 = (a * f(b) - b * f(a)) / (f(b) - f(a));

    a = b;
    b = x1;
    if (f(x1) == 0 || licznik > 100 || fabs(b - a) <= dokladnosc)
    {
        return x1;
    }

   
    return sieczne(a, b, licznik, dokladnosc);
}