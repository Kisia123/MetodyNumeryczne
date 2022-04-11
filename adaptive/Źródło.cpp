#include<iostream>
using namespace std;

double f(double x) {
	return x*x*exp(x*x)*(x-1);
}

double adaptive2(double a, double b,double t) {

	double h = (b - a) / 2;

    double f0 = f(a);
    double f1 = f(a + 0.5 * h);
    double f2 = f(a + h);
    double f3 = f(a + 1.5 * h);
    double f4 = f(b);

    double s0 = h * (f0 + 4 * f2 + f4) / 3;
    //double s1 = h*(f0+f4);
    double s1 = h * (f0 + 4 * f1 + 2 * f2 + 4 * f3 + f4) / 6;
    double s;
    if (abs(s0 - s1) >= 10 * t) {
        s = adaptive2(a, a + h,  t/2) + adaptive2(a + h, b,  t/2);
    }
    else {
        s = s1+ (s1 - s0) / 10;
    }
    return s;

}

int main() {
	double a = -2, b=2;
	double h = 0.01;
	double t = 0.05;
    cout << "----------------------------" << endl;
	cout << " WYNIK CALKOWANIA:\n metoda adaptacyjna: "<<adaptive2( a,b,t) << endl;
    cout << "----------------------------" << endl;
}