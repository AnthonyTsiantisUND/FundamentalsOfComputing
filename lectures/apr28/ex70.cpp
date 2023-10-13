#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	char str[20];
	strcpy(str, "Notre Dame");

	string col;

	col = "Rice"; // col is an object not an address

	cout << "Col's length is " << col.length() << endl;
	

	return 0;
}
