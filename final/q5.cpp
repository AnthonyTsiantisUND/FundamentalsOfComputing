#include <iostream>
using namespace std;
#include <vector>

void display(vector<int>);
int find_sum(vector<int>);

int main() {
	vector<int> nums = {23, 25, 27, 29};
	
	display(nums);
	cout << "their sum is: " << find_sum(nums) << endl;

	return 0;
}

void display(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}


int find_sum(vector<int> vec) {
	int sum = 0;
	for (int i: vec) {
		sum += i;
	}

	return sum;
}
