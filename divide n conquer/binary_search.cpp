#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
using std::vector;
int binary_search(const vector<int> &a, int x,int left, int right) {
	int mid = (left+right)/2;
  if(left >right)
  {
  	return(-1);
  }
  else if(a[mid]<x)
  {
  	left = mid+1;
  	binary_search(a,x,left,right);
  }
  else if(a[mid]>x)
  {
  	right = mid-1;
  	binary_search(a,x,left,right);
  }
  else if(a[mid]==x)
  {
  	return(mid);
  }
}

int main() {
  int n;
  std::cin >>n;
  vector<int> a(n);
  for (int i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  // std::sort(a.begin(),a.end()); // to sort the array
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i],0,n) << ' ';
  }
}
