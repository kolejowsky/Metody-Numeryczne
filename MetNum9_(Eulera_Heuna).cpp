#include <iostream>

using namespace std;

float f(float x, float y);

float y(float x);

float wypisz_x(float a, float b, float x0, float n, int i);

float wart_praw(float a, float b, float x0, float y0 ,int n, int i);

float met_Eul(float a, float b, float x0, float y0, int n, int i);

float met_Heuna(float a, float b, float x0, float y0, int n, int i);

int main()
{
    float pocz = -1;
    float kon = 1;
    float x0 = -1;
    float y0 = 2;
    float n = 10;

    cout << "przedzial [ " << pocz << " ; " << kon << " ]" << endl;
    cout << "wartosc poczatkowa: x0 = " << x0 << "  " << "y0 = f(x0) = " << y0 << endl;
    cout << "liczba krokow: " << n << endl << endl;

    bool wybor = 0;
    cout << "Zmienic wartosci?" << endl << "0 - nie , 1 - tak" << endl;
    cin >> wybor;

    if (wybor == 1)
    {
        cout << "podaj poczatek przedzialu: " << endl;
        cin >> pocz;
        cout << "podaj koniec przedzialu: " << endl;
        cin >> kon;
        cout << "podaj liczbe krokow: " << endl;
        cin >> n;

        cout << endl << endl;
        cout << "przedzial [ " << pocz << " ; " << kon << " ]" << endl;
        cout << "wartosc poczatkowa: x0 = " << x0 << "  " << "y0 = f(x0) = " << y0 << endl;
        cout << "liczba krokow: " << n << endl << endl;
    }
    cout << "wartosc x " << endl;
    wypisz_x(pocz, kon, pocz, n, 0);

    cout << endl <<"wartosc prawidlowa: " << endl;
    wart_praw(pocz, kon, pocz,y(pocz), n, 0);

    cout << endl << "metoda Eulera: " << endl;
    met_Eul(pocz, kon, pocz, y(pocz), n, 0);

    cout << endl << "metoda Heuna: " << endl;
    met_Heuna(pocz, kon, pocz, y(pocz), n, 0);

    
    /*for (int i = 0; i < n; i++)
    {
        cout << "y" << i << " = " << y(i) << endl;
    }*/
}

float f(float x, float y)
{
    return -(y*y);
}

float y(float x)
{
    return (1 / (x + (3.0 / 2)));
}

float wypisz_x(float a, float b, float x0, float n, int i)
{
    float h = (b-a)*1.0 / n*1.0;
    //cout << "h0 = " << h << endl;
    cout << "x0 = " << a << endl;
    for (int i = 0; i < n; i++)
    {
        float x1 = a + ((i + 1) * h);
        cout << "x" << i+1 << " = " << x1 << endl;
    }

    return x0;
}

float wart_praw(float a, float b, float x0, float y0, int n, int i)
{
    float h = (b - a)*1.0 / n*1.0;
    float x1 = x0 + (i + 1) * h;
    float y1 = y(x1);

    //cout << "i" << i << " = " << i << endl;
    //cout << "x" << i << " = " << x0 << endl;
    cout << "y" << i << " = " << y0 << endl;

    if (i <= n - 1)
    {
        return wart_praw(a, b, x1, y1, n, i + 1);
    }
    else
    {
        return y1;
    }
}

float met_Eul(float a, float b, float x0, float y0, int n , int i)
{
    float h = (b - a)*1.0 /  n*1.0;
    float x1 = x0 + (i + 1) * h;
    float y1 = y0 + h * f(x0, y0);

    cout << "y" << i << " = " << y0 << endl;
    
    if (i <= n - 1)
    {
        return met_Eul(a, b, x1, y1, n, i + 1);
    }
    else
    {
        return y1;
    }

}

float met_Heuna(float a, float b, float x0, float y0, int n, int i)
{
    float h = (b - a)*1.0 / n;
    float x1 = x0 + (i + 1) * h;
    float y1 = y0 + (h/2.0) * (f(x0, y0)+f(x0+h,y0+(h*f(x0,y0))));

    cout << "y" << i << " = " << y0 << endl;

    if (i <= n - 1)
    {
        return met_Heuna(a, b, x1, y1, n, i + 1);
    }
    else
    {
        return y1;
    }

}