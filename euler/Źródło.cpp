#include<iostream>
using namespace std;

double f(double x, double y){
	//return y*y-y;
	return  x+y; 
}

void euler(double x,double xn,double y,double h) {
	double n = (xn - x) / h;
	for (int i = 0; i < n; i++) {
		 y = y + h * f(x , y);
		 x = x + h;
	}
	cout << " f("<<x<<") = " << y << endl;
}

int main() {
	double x0 = 0; 
	double xn = 0.2;
	double y0 = 1;
	double h = 0.1;
	cout << "------------------------" << endl;
	cout << endl;
	euler(x0, xn, y0, h);
	cout << endl;
	cout << "------------------------" << endl;

}