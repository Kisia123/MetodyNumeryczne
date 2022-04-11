#include <iostream>
#include <vector>
using namespace std;

struct Point {
	double x, y;
     Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
};

double gauss(vector<Point> tab) {

	double points[] = { 0.5773502692,-0.5773502692 };
	//Pochodna po Ksi
	double Ksipoch[2][4];
	for (int i = 0; i < 2; i++) {
		Ksipoch[i][0] = -0.25 * (1 - points[i]);
		Ksipoch[i][1] = 0.25 * (1 - points[i]);
		Ksipoch[i][2] = 0.25 * (1 + points[i]);
		Ksipoch[i][3] = -0.25 * (1 + points[i]);
	}
	//pochodna po Ni
	double Nipoch[2][4];
	for (int i = 0; i < 2; i++) {
		Nipoch[i][0] = -0.25 * (1 - points[i]);
		Nipoch[i][1] = -0.25 * (1 + points[i]);
		Nipoch[i][2] = 0.25 * (1 + points[i]);
		Nipoch[i][3] = 0.25 * (1 - points[i]);
	}
	//pochodne wspó³rzêdnych x i y oraz Jakobianu
	double J[2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			double XpoKsi = 0, XpoNi = 0;
			double YpoKsi = 0, YpoNi = 0;
			for (int n = 0; n < 4; n++) {
				XpoKsi += Ksipoch[i][n] * tab[n].x;
				XpoNi += Nipoch[i][n] * tab[n].x;
				YpoKsi += Ksipoch[j][n] * tab[n].y;
				YpoNi += Nipoch[j][n] * tab[n].y;
			}
			J[i][j] = XpoKsi * YpoNi - YpoKsi * XpoNi;
			//cout << "j: "<<J[i][j] << endl;
		}
	}
	//calkowanie
	double w[2] = { 1,1 };
	double pole = 0; 
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			pole += w[i] * w[j] * J[i][j];
		}
	}
	return abs(pole);
}
int main() {
	Point p1(-3, -1);
	Point p2(-1, 0);
	Point p3(2, 0);
	Point p4(-2, 3);
	vector<Point>tab= { p1,p2,p3,p4 };
	cout << "-------------------------" << endl;
	cout << " Wierzcholki czworokata: " << endl;
	cout << " w1 = ( " << p1.x << "," << p1.y << " )" << endl;
	cout << " w2 = ( " << p2.x << "," << p2.y << " )" << endl;
	cout << " w3 = ( " << p3.x << "," << p3.y << " )" << endl;
	cout << " w4 = ( " << p4.x << "," << p4.y << " )" << endl;
	cout << " Pole czworokata wynosi:" << endl;
	cout<<" P = "<<gauss(tab)<<endl;
	cout << "-------------------------" << endl;
}