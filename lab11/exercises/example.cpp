#include <iostream>
using namespace std;
#include <vector>

int main()
{
  int arr[] = {134, 75, 49, 61};
  vector<int> vec = {134, 75, 49, 61};

  // index-based, with array
  for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
    cout << arr[i] << endl;

  // index-based, with vector
  for (int i = 0; i < vec.size(); i++)
    cout << vec[i] << endl;

  // range-based on vector
  for (int n: vec)
    cout << n << endl;

  return 0;
}

