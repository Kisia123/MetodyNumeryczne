#include<iostream>
#include<vector>
using namespace std;
//double first(vector<double>x, vector<double>y,int i) {
//
//		double d = (y[i+1] - y[i]) / (x[i+1] - x[i]);
//		cout << "first  "<<d << endl;
//		return d;
//	}
//	
//
//
//void second(vector<double>x, vector<double>y) {
//
//	int size = x.size();
//
//	for (int i =1; i < size; i++) {
//		int k =1;
//			/*			cout << first(x, y, i + k) << endl;
//						cout << first(x, y, i + k - 1) << endl;
//						cout << x[i + k] << endl;
//						cout << x[i] << endl;
//						break;*/
//			cout << x[i + k] << endl;
//			cout << x[i] << endl;
//			double c = ((first(x, y, i + k) - first(x, y, i + k - 1)) / (x[i +1 ] - x[i-k]));
//
//			cout << c << endl;
//			k++;
//			break;
//		}
//
//		}
void Newton(vector<double>x, vector<double>y,double point) {
	int size = x.size();
	double** tab = new double* [size];
	for (int i = 0; i < size; i++) {
		tab[i] = new double[size];
	}
	cout << "1 Rzedu:" << endl;
	for (int j = 0; j < size-1; j++) {

		double d = (y[j + 1] - y[j]) / (x[j + 1] - x[j]);
		tab[j][0] = d;
		cout << tab[j][0] << endl;
	}

	for (int k = 1; k < size-1; k++) {
		cout << k +1 << " Rzedu: " << endl;
		for (int i = k; i < size-1; i++) {
			tab[i][k] =( tab[i][k - 1] - tab[i - 1][k - 1]) / (x[i+1] - x[i-k]);
			cout << tab[i][k] << endl;
		}
			
	}
	double suma = y[0];
	double iloczyn = 1;
	for (int w = 0; w < size-1; w++) {
		iloczyn *= (point - x[w]);
		suma += tab[w][w] * iloczyn;
		cout << suma << endl;
	}
	cout << "suma: " << suma << endl;
}

int main() {
	vector<double>x = {1,2,4,10,20};
	vector <double>y = {0,1,2,3.32,4.32};
	double punkt = 7;
	Newton(x, y,punkt);
}