#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string);


int main() {
	
	map<int, list<string>> hash_table;

	ifstream fin;
	fin.open("lab-37-data-3.txt");
	
	string value;
	int hashIndex;
	
	if (fin.good()) {
		while (getline(fin, value)) {
			hashIndex = gen_hash_index(value);

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

int gen_hash_index(string val) {
	int total = 0;

	for (int i = 0; i < val.length(); i++) {
		total += (int)val[i];
	}
	
	return total;

}