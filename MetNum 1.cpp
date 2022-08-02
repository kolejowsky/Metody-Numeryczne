#include<iostream>

using namespace std;

float interpol_lin(float x0, float f0, float x1, float f1, float x)
{
	float pom;
	pom = f0 + ((f1 - f0) / (x1 - x0))*(x - x0);
	return pom;
}

float interpol_kwad(float x0, float f0, float x1, float f1, float x2, float f2, float x)
{
	float pom;

	float l0 = ((x - x1) * (x - x2)) / ((x0 - x1) * (x0 - x2));
	float l1 = ((x - x0) * (x - x2)) / ((x1 - x0) * (x1 - x2));
	float l2 = ((x - x0) * (x - x1)) / ((x2 - x0) * (x2 - x1));
	
	pom = (l0 * f0) + (l1 * f1) + (l2 * f2);
	
	return pom;
}

int main()
{
	float x_0 = 2;
	float y_0 = 6;

	float x_1 = 3;
	float y_1 = 8;

	float x_2 = 8;
	float y_2 = 7;

	float k = 2.5;
	float l = 3.5;

	cout << "Dane sa punkty: " << endl << endl;
	cout << "A0: ( " << x_0 << " , " << y_0 << " )" << endl;
	cout << "A1: ( " << x_1 << " , " << y_1 << " )" << endl;
	cout << "A2: ( " << x_2 << " , " << y_2 << " )" << endl;

	cout << endl << "Wybierz metode Interpolacji: " << endl << endl;
		cout << "Liniowa - wpisz 0" << endl;
		cout << "Kwadratowa - wpisz 1" << endl << endl;

		bool metoda;
		cin >> metoda;

		if (metoda == 0)
		{
			bool wybor;
			cout << endl << "wybierz pomiedzy ktorymi punktami" << endl << endl;
			cout << "A0 i A1 - wpisz 0" << endl;
			cout << "A1 i A2 - wpisz 1" << endl << endl;
			cin >> wybor;
			if (wybor == 0)
				cout << endl << "interpolacja liniowa dla punktow A0 i A1 oraz dla x rownego " << k << " wynosi: " << interpol_lin(x_0, y_0, x_1, y_1, k) << endl;
			else
				cout << endl << "interpolacja liniowa dla punktow A1 i A2 oraz dla x rownego " << l << " wynosi: " << interpol_lin(x_1, y_1, x_2, y_2, l) << endl;
		} 
		else {
			cout << endl << "interpolacja kwadratowa dla punktow A0, A1 i A2 oraz dla x rownego " << l << " wynosi: " << interpol_kwad(x_0, y_0, x_1, y_1, x_2, y_2, l) << endl;
		}
	return 0;
}
