#include <iostream>
#include <string>
using namespace std;

int sum_ascii(string);


int main() {
	char a = 'A';
	cout << a << endl;
	cout << (int)a << endl;
	int b = 66;
	cout << b << endl;
	cout << (char)b << endl;

	string value = "ABC";
	string v2 = "123";

	cout << value << endl;
	cout << sum_ascii(value);
	cout << v2 << endl;
	cout << sum_ascii(v2);


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
		cout << (int)val[i] << endl; //cout line for testing and verification
	}
	
	return total;

}