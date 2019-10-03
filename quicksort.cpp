#include <iostream>
#include <vector>
using namespace std;

void swap(int* a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
 
void quicksort(int arr[], int l, int r)
{

	
	if(l<r)
	{
	int pivot = arr[l], pivot_point;
	int i = l+1, j = r, hold_i = 0, hold_j = 0,count = 0;
	
	while(i < j)
	{
		if(arr[i] > pivot)
			{
			hold_i = 1;
			}
		else
			i++;
			
		if(arr[j] < pivot)
		{
			hold_j = 1;
		}
		else
			j--;
			
			
		if( hold_i == 1 && hold_j == 1)
		{
			swap(&arr[i], &arr[j]);
			hold_i = 0; hold_j = 0;
			i++; j--;
		}
	}
	
	if(i == j)
	{
		if(pivot <= arr[i])
			j--;
		else
			i++;	
	}
	
	swap(&arr[l], &arr[j]);
	pivot_point = j;
	
	quicksort(arr, l, pivot_point);
	quicksort(arr, pivot_point + 1, r); 	
	}			
}

int main()
{
int arr[] = {1,7,3,9,13,5,17,7,2,2,2,2,2,2};
int n = sizeof(arr)/sizeof(arr[0]);

for(int i = 0; i< n; i++)
	cout<<arr[i]<<" ";
	cout<<endl;
	
quicksort(arr, 0, n-1);

for(int i = 0; i< n; i++)
	cout<<arr[i]<<" ";
	cout<<endl;


}

