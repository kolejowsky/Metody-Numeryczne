

#include <iostream>
#include <math.h>
#include <random>
#include <time.h>


using namespace std;

float f(float x)
{
    return sin(x);
}

float fp(float x)
{
    return cos(x);
}

float monte_carlo1(float a, float b, float fmax,int n);
float monte_carlo2(float a, float b, float fmax, int n);
float GL4(float a, float b);
float GL5(float a, float b);

int main()
{
    float a = 0;
    float b = 3.14159265358979323846;
    float fmax = 1;
    float n = 10000;
    srand(time(NULL));

    cout << "przedzial: [ " << a << " ; " << b << " ]" << endl;
    cout << "n = " << n << endl;
    cout << "metoda monte carlo 1: " << monte_carlo1(a, b, fmax, n)<<endl;
    cout << "metoda monte carlo 2: " << monte_carlo2(a, b, fmax, n)<<endl;
}

float monte_carlo1(float a, float b, float fmax, int n)
{
    float suma=0;
    for (int i = 0; i < n; i++)
    {
        suma += f(a + (a + b) * rand() * 1.0 / RAND_MAX);
    }
    float fi = suma / n*1.0;
    return (b-a)*fi;
}

float monte_carlo2(float a, float b, float fmax, int n)
{
    float xl;
    float yl;
    float nt=0;

    for (int i = 0; i < n; i++)
    {
        xl = a + (b - a) * rand()*1.0 / RAND_MAX;
        yl = fmax * rand()*1.0 / RAND_MAX;
        if (f(xl >= 0))
        {
            if (yl < f(xl))
            {
                nt+=1;
            }
        }
        else
        {
            if (yl > f(xl))
            {
                nt++;
            }
        }
    }
    float I = (b - a) * fmax * (nt / n);
    return I;
}

float GL4(float a, float b)
{
    float w1 = 0.3478548451;
    float w2 = 0.6521451549;
    float w3 = w2;
    float w4 = w1;

    float x4 = 0.8611363116;
    float x3;

    return 0;
}
