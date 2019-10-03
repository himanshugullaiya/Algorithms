#include <iostream>
#include <vector>
using namespace std;

class MERGESORT
{
	public:
		void mergesort(int arr[], int l, int r)
		{
			if( l < r)
			{
				int m = (l + r)/2;
				mergesort(arr, l, m);
				mergesort(arr, m+1, r);
				merge(arr, l, m, r);
			}
		}
		
		void merge(int arr[], int l, int m, int r)
		{
			int i = l, j = m+1, k = 0;
			int size = r-l+1;
			int temp[size];
			while(i <= m && j <= r)
			{
				if (arr[i] == arr[j])
				{
					temp[k] = arr[i];
					i++; j++;
				}
				
				else if(arr[i] < arr[j])
				{
					temp[k] = arr[i];
					i++;
				}
				
				else
				{
					temp[k] = arr[j];
					j++;
				}
				k++;
			}
			
			while(i <= m)
			{
				temp[k] = arr[i];
				i++; k++;
			}
			
			while(j <= r)
			{
				temp[k] = arr[j];
				j++; k++;
			}
			
			for(int i = 0; i < size; i++)
			{
				arr[l+i] = temp[i];
			}
		}
};

int main()
{ 
MERGESORT m;
int arr[] = {10,3,2,1,9,8};
int n = sizeof(arr)/sizeof(arr[0]);

for(int i = 0; i < n; i++)
	cout<<arr[i]<<" ";
	cout<<endl;
	
m.mergesort(arr, 0, n);

for(int i = 0; i < n; i++)
	cout<<arr[i]<<" ";

}
