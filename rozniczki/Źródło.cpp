#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

double f(double x, double y) {
	return y*y-y;
}

void RK2(double y0,double h,double x0, double b) {
	int n = round((b - x0) / h);
	vector<double>y(n + 1);
	y[0] = y0;
	double x = x0;
	for (int i = 1; i <= n; i++) {
		y[i] = y[i-1] + h / 2 * (f(x, y[i-1]) + f(x + h, y[i-1] + h * f(x, y[i-1])));
		 x += h;
	}
	cout << " y" << "(" << x << ") = " << y[n] << endl;
}

void RK4(double y0, double h, double x0, double b) {
	int n = round((b - x0) / h);
	vector<double>y(n+1);
	y[0] = y0;
	double x = x0;
	for (int i = 1; i <= n; i++) {
		double k1 = h * f(x, y[i-1]);
		double k2 = h * f(x + 0.5 * h, y[i-1] + 0.5 * k1);
		double k3 = h * f(x + 0.5 * h, y[i-1] + 0.5 * k2);
		double k4 = h * f(x + h, y[i-1] + k3);
		y[i] = (((k1 + 2 * k2 + 2 * k3 + k4) / 6 )+y[i-1]);
		x += h;
	}
		cout << " y"<<"(" << x << ") = " << y[n] << endl;

}

int main() {
	double y0 = -1;
	double x0 = 2;
	double xn =20;
	double h = 0.001;
	cout << "--------------------------" << endl;
	cout << " METODA HEUNA" << endl;
	RK2(y0, h, x0, xn);
	cout << "--------------------------" << endl;
	cout << "--------------------------" << endl;
	cout << " METODA R-K 4 RZEDU" << endl;
	RK4(y0, h, x0, xn);
	cout << "--------------------------" << endl;
}