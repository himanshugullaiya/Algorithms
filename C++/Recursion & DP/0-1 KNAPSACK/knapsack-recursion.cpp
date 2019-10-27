#include <iostream>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;
typedef long long int lli;

int deleteElement(int arr[], int n, int i) 
{ 
// If x found in array 
if (i < n) 
{ 
 // reduce size of array and move all 
 // elements on space ahead 
 n = n - 1; 
 for (int j=i; j<n; j++) 
    arr[j] = arr[j+1]; 
} 

return n; 
} 

int knapsack(int capacity, int n_items, int* weights, int* values)
{

	if(capacity < *min_element(weights, weights + n_items) || n_items == 0)
	{
		return 0;
	}
	
	else
		 if (n_items == 1)
			return values[0];
		
		else
		{
			int size_arrs = sizeof(values)/sizeof(values[0]);
			int* max_value_add = max_element(values, values + size_arrs);
			int max_value = *max_element(values, values + size_arrs);
			int index = max_value_add - values;
			int weight_at_index = weights[index];
			deleteElement(values, size_arrs, index);
			deleteElement(weights, size_arrs, index);
	
			int a = knapsack(capacity - weight_at_index, n_items - 1, weights, values) + max_value;
			int b = knapsack(capacity, n_items - 1, weights, values);
			
			return max(a,b);
				
		}		

}
			
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n_items, cap;
		cin>>n_items>>cap;
		int items_w[n_items], values[n_items];
		
		for (int i = 0; i< n_items; i++)
			cin>>items_w[i];
			
		for (int i = 0; i< n_items; i++)
			cin>>values[i];
		
		cout<<knapsack(cap, n_items, items_w, values);
		cout<<endl;
		
		
	}
}
