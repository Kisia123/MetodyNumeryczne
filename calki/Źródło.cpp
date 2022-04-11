#include<iostream>
#include <math.h>
//#include <cstdlib>
#include<time.h>
//#include<random>
using namespace std;
double f(double x) {
	return (pow(x,3)+3*pow(x,2)+1);
}
double randomNumber(double xp,double xk) {
	double x =xp+static_cast<double>(rand())/(static_cast<double>(RAND_MAX/(xk-xp)));
	return x;
}
void simpson(double xp, double xk) {
	double h = (xk - xp) / 2;
	double I = (f(xp) + 4 * f((xp + xk) / 2) + f(xk)) * (h / 3);
	cout << " Metoda Simpsona: "<<I<<endl;
}
void simpsonzl(double xp, double xk, int n) {
	double h = (xk - xp) / n;
	double suma = 0;
	for (int i = 1; i <= n/2; i++) {
		suma += (f(xp) + 4 * f(xp + h) + f(xp + h * 2)) * (h / 3);
		xp += 2 * h;
	}
	cout <<" Zlozona metoda Simpsona: " << suma << endl;
}
void monteCarlo(double xp, double xk,int m) {
	double suma = 0;
	for (int i = 0; i < m; i++) {
		suma += f(randomNumber(xp, xk)) / m;
	}
	suma *= abs(xk - xp);
	cout << " Metoda Monte Carlo: "<< suma<<endl;
}
//void monteCarlo2(double xp,double xk,int m) {
//	std::random_device rd;  
//	std::knuth_b gen(rd()); 
//	std::uniform_real_distribution<> dis(xp, xk);
//	double suma = 0;
//	for (int i = 0; i < m;i++) {
//		suma += f(dis(gen)) / m;
//	}
//	suma *= abs(xk - xp);
//	std::cout << "calka monte2: " << suma << endl;
//}
int main() {
	int n =26;
	int m = 62500;
	double xp = 10, xk = -3;
	cout << "---------------------------------" << endl;
	cout << " WYNIKI CALKOWANIA:\n" << endl;
	simpson(xp, xk);
	simpsonzl(xp, xk, n);
	srand(time(0));
	monteCarlo(xp, xk,m);
	cout << "---------------------------------" << endl;

//	monteCarlo2(xp, xk,m);
}
