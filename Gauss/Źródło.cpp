#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

void gauss(vector<vector<double>> tab) {
	int wsize = tab.size();
	int ksize = wsize + 1;
	for (int i = 0; i < wsize - 1; i++) {
		for (int w = i + 1; w < wsize; w++) {
			double wsp = (double)tab[w][i] / tab[i][i];
			for (int k = i; k < ksize; k++) {
				tab[w][k] -= wsp * tab[i][k];
			}
		}
	}
	vector<double>X = vector<double>(wsize);
	for (int w = wsize - 1; w >= 0; w--) {

		double solution = tab[w][ksize - 1];
		for (int k = ksize - 2; k > w; k--) {
			solution -= tab[w][k] * X[k];
		}
		X[w] = solution / tab[w][w];
	}
	for (int i = 0; i < wsize; i++) {
		for (int j = 0; j < ksize; j++) {
			cout << tab[i][j] << ", ";
		}
		cout << endl;
	}
	for (int i = 0; i < X.size(); i++) {
		cout <<"x"<<i+1<<" = "<< X[i] << ", ";
	}
	cout << endl;
}
int main() {
	int n;
	vector<vector<double>> tab = { {1,1,1,1,1},{0,2,0,4,-2},{-1,0,1,2,10},{-2,5,1,0,-7} };
	gauss( tab);
}
