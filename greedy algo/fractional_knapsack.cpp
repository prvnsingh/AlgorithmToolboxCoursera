#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values, int n) {
  // write your code here
  double value = 0.0;
  std::vector<double> ratio(n);	//array to hold ratio of value by weight
  for (int i=0;i<n;i++)
  {
  	ratio[i]=(double)values[i]/weights[i];
  }
  for(int j=0;j<n-1;j++)	//bubble sorting of ratios for maximum to get 0 index
  	{
  		for(int k=0;k<n-j-1;k++)
  		{	
  			if(ratio[k]<ratio[k+1])
  			{
  				double itemr = ratio[k];
  				ratio[k]= ratio[k+1];
  				ratio[k+1]=itemr;
  				  
				  int w ;					//changing the corresponding weights index
				  w = weights[k];
				  weights[k] = weights[k+1];
				  weights[k+1] = w;
				  
				  int v;					// changing the corresponding values index 
				  v = values[k];
				  values[k] = values[k+1];
				  values[k+1] = v;
  			}
  		}
  	}
  	
	for(int l=0;l<n;l++)
	{
		  if(capacity>weights[l])
  		{
  			value = value + weights[l]*ratio[l];
  			capacity = capacity - weights[l];
  		}
  		else
  		{
  			value = value + capacity*ratio[l];
  			capacity = 0;
  			break;
  		}
  	}	  
  return value;
}  
int main() {
	int n;	// number of item knapsack can contain
  int capacity; // total ammount it can contain
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values,n);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
