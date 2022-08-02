// MetNum7_(calki).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>

using namespace std;

float f(float x)
{
    return pow(x,4)+3*pow(x,3)+12*pow(x,2)+7*x+9;
};

float met_trap(float xp, float xk, int n);

float trap_ep(float xp, float xk, float ep);

int main()
{
    float xp = 2;
    float xk = 4;
    int n = 5000;
    int ep = 0.0001;
    cout << "przedzia³ [ " << xp << " ; " << xk << " ]" <<"podzielony na "<< n << " podprzedzialow" << endl;
    //cout << "Metoda trapezow: " << trap_ep(xp, xk, ep)<<endl;
    cout << "Metoda trapezow: " << met_trap(xp, xk, n)<<endl;
}

float met_trap(float xp, float xk, int n)
{
    float suma = 0;
    float dx = (xk - xp) / n;

    for (int i = 1; i < n; i++)
    {
        suma += f(xp + i*dx);
    }
    suma += (f(xp) + f(xk));
    
    return suma*dx;
}

float met_simps(float xp, float xk, int n)
{
    float suma = 0;
    float dx = (xk - xp) / n;

    for (int i = 1; i < n; i++)
    {
        suma += f(xp + i * dx);
    }
    suma += (f(xp) + f(xk));

    return suma * dx;
}


float trap_ep(float xp, float xk, float ep)
{
    float pom = 1;
    int licznik = 1;
    do
    {
        pom = (met_trap(xp, xk, 2 * licznik) - met_trap(xp, xk, licznik)) / met_trap(xp, xk, licznik);
        licznik++;
        //cout << licznik << endl;
        //cout << pom << endl;
    } while (fabs(pom) > ep && licznik < 1000);
    
    return met_trap(xp,xk,2*licznik);
}

