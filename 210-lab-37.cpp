#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string);
void coutHundred(map<int, list<string>>&);


int main() {
	
	map<int, list<string>> hash_table;

	ifstream fin;
	fin.open("lab-37-data-3.txt");
	
	string value;
	int hashIndex;
	int count = 0;

	//read values from file and populate hash table while outputting first 100 entries
	if (fin.good()) {
		while (getline(fin, value)) {
			
			//set hashIndex as ascii sum of value
			hashIndex = gen_hash_index(value);
			 
			//at hashIndex, set the value in list to read value
			hash_table[hashIndex].push_back(value);

			//display first 100 entries from file
			if (count < 100) {
				
				cout << "Entry " << count + 1 << endl;
				//access int/key/index in map pair and output
				cout << "Hash index: " << hashIndex << endl;
				
				//access value in map list/value and ouput
				cout << "Value: " << value << endl << endl;
			}
			count++;
		}

		fin.close();
	}
	else {
		cout << "File not found" << endl;
	}
	
	int choice;

	do {
		cout << "1. Print first 100 entries" << endl;
		cout << "2. Search for key" << endl;
		cout << "3. Add key" << endl;
		cout << "4. Remove key" << endl;
		cout << "5. Modify key" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter choice: " << endl;
	} while (choice != 6);

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