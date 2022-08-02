

#include <iostream>

using namespace std; 

float lag_int(float xi[5], float yi[5], float x)
{
    float l[5] = { 1,1,1,1,1 };
    float L = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i != j)
            {
                l[i] = l[i] * ((x - xi[j]) / (xi[i] - xi[j]));
            }
        }
        L += yi[i] * l[i];
    }

    return L;
}

float cubic_spline(float xi[5], float yi[5], float x)
{
    float h[4];

    float u[3];
    float w[3];
    float v[3];
    for (int i = 0; i < 4; i++)
    {
        h[i] = xi[i + 1] - xi[i];
    }
    for (int i = 1; i < 4; i++)
    {
        u[i-1] = h[i - 1] / (h[i - 1] + h[i]);
        w[i-1] = h[i] / h[i - 1] + h[i];
        float pom1 = ((yi[i + 1] - yi[i]) / h[i]);
        float pom2 = ((yi[i] - yi[i - 1]));
        v[i - 1] = (pom1 - pom2) / (h[i - 1] + h[i]);
        //indeksy y chyba są ok
    }

    float c[5];
    c[0] = 0;
    c[2] = (3 * v[1] - 1.5 * u[1] * v[0] - 1.5 * w[1] * v[2]) / (2 - 0.5 * u[1] * w[0] - 0.5 * u[2] * w[1]);
    c[1] = 1.5 * v[0] - 0.5 * w[0] * c[2];
    c[3] = 1.5 * v[2] - 0.5 * u[2] * c[2];
    c[4] = 0;

    float d[4];
    float a[4];
    float b[4];

    for (int i = 0; i < 4; i++)
    {
        d[i] = (c[i + 1] - c[i]) / (3*h[i]);
        a[i] = yi[i];
        b[i] = (yi[i + 1] - yi[i] - c[i] * h[i] * h[i] - d[i] * h[i] * h[i] * h[i]) / h[i];
    }

    
    /*for (int i = 0; i < 4; i++)
    {
        cout << "v " << i << "= " << a[i] << endl;
        cout << "w " << i << "= " << b[i] << endl;
        cout << "u " << i << "= " << c[i] << endl;
        cout << "c " << i+1 << "= " << c[i + 1] << endl;
    }*/
    
    float s[5];
    for (int i=0; i < 4; i++)
    {
        float t = x - xi[i];
        s[i] = a[i] + (b[i] * t) + (c[i] * t * t) + (d[i] * t * t * t);
    }

   
    if (x >= xi[0] && x <= xi[1])
        return s[0];
    else if (x > xi[1] && x <= xi[2])
        return s[1];
    else if (x > xi[2] && x <= xi[3])
        return s[2];
    else if (x > xi[3] && x <= xi[4])
        return s[3];
   
    
    return 0;
}



int main()
{

    
    float xi[5] = { 1,2,3,4,5 };
    float yi[5] = { 3.1, 4.2, 7.3, 9.4, 6.5 };
    float x = 5;

    cout << "dane sa punkty: " << endl << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "A" << i << ": ( " << xi[i] << " , " << yi[i] << " )" << endl;
    }
    if (x >= xi[0] && x <= xi[4])
    {
        cout << endl;
        cout << "interpolacja lagrange'a w punkcie x = " << x << " wynosi " << lag_int(xi, yi, x) << endl;
        cout << "cubic spline w punkcie x = " << x << " wynosi " << cubic_spline(xi, yi, x) << endl;
        //cubic_spline(xi, yi, x);
    }
    else
    {
        cout << endl;
        cout << "liczba spoza zakresu" << endl;
    }
    
}


