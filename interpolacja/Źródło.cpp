#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

double interpolacja( vector<double>x, vector<double> y,double point) {
	int stopien = x.size();
	double Lx = 0;
	for (int i = 0; i < stopien; i++) {
		double li = 1;
		for (int j = 0; j < stopien; j++) {
			if (j != i) {
				li *= ((point - x[j]) / (x[i] - x[j]));

			}
			
			
		}
		Lx += (y[i] * li);
		cout <<"l"<<i<< " = "<<li << endl;
	}
	
	return Lx;
}
vector<double> split(const string& s, char t) {
	vector<double> wektor;
	std::stringstream ss(s);
	std::string number;
	while (std::getline(ss, number, t)) {
		wektor.push_back(std::stod(number));
	}
	return wektor;
}

int main() {
	ifstream plik;
	plik.open("liczby.txt");
	string line;
	getline(plik, line);
	int n = stoi(line);
	vector<double> x;
	vector<double>y;

	getline(plik, line);
	x = split(line, ',');

	getline(plik, line);
	y = split(line, ',');

	getline(plik, line);
	double l = stod(line);

	cout << "L(x) = "<<interpolacja(x,y,l)<< endl;
}