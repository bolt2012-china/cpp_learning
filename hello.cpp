#include <iostream>
#include <vector>
using namespace std;

//bool match(int x1, int x2) { return ((x1 + 10) ^ 0xaaa) > ((x2 + 10) ^ 0xaaa); }
bool match(int n, int m) {
  return n>m;
}

int main() {
  int n,a=0;
  vector<int> v;
  cin >> n;
  while (cin >> a)
  {
    v.push_back(a);
  }
  int low=0, high=v.size()-1;
  int temp;
  while (low<high)
  {
    if (match(v[low], v[high]))
      high--;
    else
    {
      temp=v[low];
      v[low]=v[high];
      v[high]=temp;
    }
    low++;
    high=v.size()-1;
  }

  cout << v[0] << " " << v[1] << " " << v[2]  << endl;
}
