#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
void aproksymacja(vector<double>x, vector<double>y) {
	int n = x.size();
	double sumamn = 0, sumax = 0, sumay = 0;
	double sumax2 = 0, sumay2 = 0;
	for (int i = 0; i < n; i++) {
		sumamn += x[i] * y[i];
		sumax += x[i];
		sumay += y[i];
		sumax2 += x[i] * x[i];
		sumay2 += y[i] * y[i];
	}
	double l = n * sumamn - sumax * sumay;
	double m = n * sumax2 - (sumax * sumax);
	double a1 =l/ (n * sumax2 - ((sumax * sumax)));
	double a0 = (sumay * sumax2 - sumax * sumamn) / m;
	cout << "Rownanie prostej:" << endl;
	cout << "y(x) = " << a0 << " + " << a1 << "x"<<endl;
	cout << endl;
	double r = l / (sqrt(m) * sqrt(n * sumay2 - (sumay * sumay)));
	cout << "Wspolczynnik korelacji wynosi:" << endl;
	cout<<"r = " << r << endl;
}
int main() {
	vector<double> x = { 1,2,7,- 3,5,- 5.6,- 2,0,- 4.3,- 4.6,2.34,2.9,9,- 10,0.7,1.5,- 4,3,3.67,2.13,1.87,	};
	vector<double>y = { 0,4,2,3,5,7,9,10,- 11,2,- 8.9,6.7,9.2,1.23,1.78,- 7,- 5.4,- 8.13,2.4,2,1	};
	cout << "------------------------------" << endl;

	aproksymacja(x, y);
	cout << "------------------------------" << endl;

}