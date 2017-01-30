#include <iostream>
int get_change(int m)
 {
  //write your code here
  int c = 0;
  while(m > 0)
  {
  	if(m >= 10)
  	{
  		c = c + m / 10;
  		m=m % 10;
  	}
  	else if(m >= 5)
  	{
  		c = c + m / 5;
  		m = m % 5;
  	}
  	else
  	{
  		c = c + m;
  		m = 0;
  	}
  }
  return c;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
