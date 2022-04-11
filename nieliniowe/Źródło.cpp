#include <iostream>
#include<math.h>
using namespace std;

#define dok 0.00001

#define eps 1e-14
double f(double x) {
	return log2(x);
}
double fp(double x) {
	return 1/(x*log(2));
}

double bis(double a, double b) {
	if (f(a) * f(b) < 0) {
		double x1;
		while (abs(a - b) > dok) {
			x1 = (a + b) / 2;
			if (abs(f(x1)) <= eps) {
				return x1;
			}
			else if (f(x1) * f(a) < 0) {
				b = x1;
			}
			else {
				a = x1;
			}
		}
		return (a + b) / 2;
	}
	else {
		cout << "Zalozenia metody nie zostaly spelnione" << endl;
	}
}
double NR(double a, double b, int n) {
	if (f(a) * f(b) < 0) {

		double x1 = b;
		if (fp(x1) <=eps) {
			x1 = a;
			if (fp(x1) <= eps) {
				x1 = (b-a)/2;
				if (fp(x1) <= eps) {
					cout << "warunki nie zosta³y spe³nione" << endl;
				}
			}
		}		
		for (int i = 0; i < n; i++) {
			if (abs(f(x1)) <= dok) {
				return x1;
			}
			double x2 = x1 - (f(x1) / fp(x1));
			if (abs(x2 - x1) <= dok) {
				return x1;
			}
				x1 = x2;
		}
		return x1;
	}
	else {
		cout << "Zalozenia metody nie zostaly spelnione" << endl;
	}
}

int main() {
	double a = 0, b =6;
	cout << "-------------------------" << endl;
	cout << " METODA BISEKCJI" << endl;
	cout<<" "<<bis(a, b)<<endl;
	cout << "-------------------------" << endl;
	cout << " METODA NEWTONA-RAPHSONA" << endl;
	cout<<" "<<NR(a,b,100)<<endl;
	cout << "-------------------------" << endl;
}