#include<iostream>
#define fi 0.61803398
#define eps 0.000001
using namespace std;
double f(double x) {
	return pow(x,2)-1;
}

double opt(double a , double b) {
	double xl = b - fi *(b - a);
	double xp = a + fi * (b - a);
	while ((b - a) > eps) {
		if (f(xl) > f(xp)) {
			a = xl;
			xl = xp;
			xp = a + fi * (b - a);
		}
		else{
			b = xp;
			xp= xl;
			xl = b - fi * (b - a);
		}
	}
	return(xl + xp) / 2;
}

int main() {
	double a = -3;
	double b = -1;
	cout << fixed;
	cout<<"minimum: "<<opt(a, b);
}