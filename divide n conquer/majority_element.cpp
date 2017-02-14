#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
int get_majority_element(vector<int> &a)
 {
 	sort(a.begin(),a.end());
	 int count = 1, c= 1;
	 for(int i = 0;i<a.size()-1;i++)
 	{
		if(a[i]==a[i+1])
		{
			count = count +1 ;
		}
		else if (c<count)
		{
			c = count;
			count=1;
		} 
		else
		{
			count = 1;
		} 		
	}
	if(c > a.size()/2)
	return 1;
	else
	return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a)) << '\n';
}
