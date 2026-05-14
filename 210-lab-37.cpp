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
			//set hashIndex as ascii sum of value
			hashIndex = gen_hash_index(value);
			 //at hashIndex, set the value in list to read value
			hash_table[hashIndex].push_back(value);
		}

		fin.close();
	}
	else {
		cout << "File not found" << endl;
	}
	
	int count = 0;
	//loop through table contents
	for (const auto& p : hash_table) { 
		if (count == 100) {
			break;
		}

		//access int/key/index in map pair and output
		cout << "Hash index: " << p.first << endl; 

		//loop through and output values in map list/value
		for (const string& value : p.second) {
			cout << "Value: " << value << endl;
		}

		cout << endl;
		count++;
	}
	

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