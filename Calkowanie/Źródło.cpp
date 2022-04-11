#include <iostream>
#include <math.h>
using namespace std;
double f(double x) {
	return (x);
}
double calkaProst(double xp, double xk, double n) {
	double suma = 0;
	double dx = (xk - xp) / n;
	cout << "Pola prostokatow:" << endl;
	for (int i = 1; i <=n; i++) {
			double pole = f(xp + i * dx);
			cout << "Pole " << i << ": " << pole<< endl;
			suma += pole;
	}
	suma *= dx;
	return suma;

}
double calkaTrap(double xp,double xk,double n) {
	double dx = (xk - xp) / n;
	double suma = 0;
	cout << "Pola trapezow:" << endl;
	for (int i = 0; i < n; i++) {
		int j = i + 1;
		double pole = (f(xp + i * dx) + f(xp + (j)*dx))/2;
		cout << "Pole " << j << ": " << pole << endl;
		suma += pole;
	}
	suma *= dx;
	return suma;
}
int main() {
	double n = 100;
	double xp = 1, xk = 5;
	double prost = calkaProst(xp, xk, n);
	cout << endl;
	double trap = calkaTrap(xp, xk, n);
	cout << endl;
	cout << "Wynik calkowania:" << endl;
	cout << "Metoda prostokatow: " << prost << endl;
	cout << "Metoda trapezow: " << trap << endl;
}