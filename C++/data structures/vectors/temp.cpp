#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
typedef long long int lli;

bool sortbysec(pair<int,int> &a, pair<int,int> &b)
{
	return a.second < b.second;
}

int main()
{
	vector<pair<int,int>> vect;
int arr[] = {10, 20, 5, 40 }; 
    int arr1[] = {30, 60, 20, 50}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    // Entering values in vector of pairs 
    for (int i=0; i<n; i++) 
        vect.push_back( make_pair(arr[i],arr1[i]) );
    sort(vect.begin(), vect.end(), sortbysec);
    
    for(int i = 0; i < n; i++)
	{
		cout<<vect[i].first<<" "<<vect[i].second;
		cout<<endl;
			}    	

}

