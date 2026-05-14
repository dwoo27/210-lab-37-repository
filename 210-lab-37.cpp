#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int sum_ascii(string);


int main() {
	
	ifstream fin;
	fin.open("lab-37-data-3.txt");
	
	string value;
	int grandTotal = 0;
	
	if (fin.good()) {
		while (getline(fin, value)) {
			grandTotal += sum_ascii(value);
		}

		fin.close();
	}
	else {
		cout << "File not found" << endl;
	}
	
	cout << "Grand total: " << grandTotal;
	

	return 0;
}
/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

int sum_ascii(string val) {
	int total = 0;

	for (int i = 0; i < val.length(); i++) {
		total += (int)val[i];
	}
	
	return total;

}