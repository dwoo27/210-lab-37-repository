#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string);
void firstHundred(map<int, list<string>>&);
bool searchKey(map<int, list<string>>&, string);
void addKey(map<int, list<string>>&, string);


int main() {
	
	map<int, list<string>> hash_table;
	list<string> fh; //list to store first hundred entries

	ifstream fin;
	fin.open("lab-37-data-3.txt");
	
	string value;
	int hashIndex;

	//read values from file and populate hash table while outputting first 100 entries
	if (fin.good()) {
		while (getline(fin, value)) {	
			//set hashIndex as ascii sum of value
			hashIndex = gen_hash_index(value);
			 
			//at hashIndex, set the value in list to read value
			hash_table[hashIndex].push_back(value);

			//store first 100 values read to use for firstHundred function
			if (fh.size() < 100) {
				fh.push_back(value);
			}

			
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

		cin >> choice;

		//prevents program from crashing if user enters str instead of int for invalid choice
		if(cin.fail()) {
			cin.clear();
			choice = 0;
		}

		cin.ignore(1000, 10);

		switch (choice) {
			//print first 100 entries
			case 1:
				cout << endl;
				firstHundred(fh);
				cout << endl;
				break;
			
			//search for key
			case 2:
				cout << "Enter key to search: " << endl;
				getline(cin, value);

				if (searchKey(hash_table, value)) { //searches for key
					cout << "Key found" << endl << endl;
				}
				else {
					cout << "Key not found" << endl << endl;
				}
				break;

			//add key
			case 3:
				cout << "Enter key to add: " << endl;
				getline(cin, value);

				if (tree.searchNode(value)) { //searches if new record to be added already exists
					cout << "Record already exists" << endl << endl;
				}
				else {
					tree.insertNode(value); //otherwise add new record
					cout << "Record added: " << value << endl << endl;
				}
				break;
			// remove key
			case 4:
			
			//modify key
			case 5:
			
			//exit
			case 6:

			default: //default for invalid choice
				cout << "Invalid choice. Please try again." << endl << endl;
		}

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

void firstHundred(list<string>& fh) {
	int count = 0;
	
	//display first 100 entries from file
	for (const string& value : fh) {
		cout << "Entry " << count + 1 << endl;
		
		//convert value to hash index/key
		cout << "Hash index: " << gen_hash_index(value) << endl;
		
		//output value
		cout << "Value: " << value << endl << endl;

		count++;
	}
}

bool searchKey(map<int, list<string>>& hash_table, string value){
	int hashIndex = gen_hash_index(value);

	auto it = hash_table.find(hashIndex); //set it to find hashIndex in map

	if (it == hash_table.end()) { //return false if not found
		return false;
	}

	for (const string& val : it->second) { //loops through list of index found
		if (val == value) { //compares each element to value searched for
			return true; //returns true if found
		}
	}

	return false;

}

void addKey(map<int, list<string>>& hash_table, string value) {
	int hashIndex = gen_hash_index(value);//creates index for value
	hash_table[hashIndex].push_back(value); //at new index, add value in hash table
}