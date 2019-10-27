#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

string LCS(string a, string b, int m,int  n)   // m,n - lengths of a,b  (rows,columns)
{
	int arr[m+1][n+1]; memset(arr,0,sizeof(arr));
	string lcs; int longest_length;
	
	for(int x = 1; x <= m; x++)
		{
			for(int y = 1; y <= n; y++)
			{
				if(a[x-1] == b[y-1])
					arr[x][y] = (1 + arr[x-1][y-1]);
				
				else
					arr[x][y] = max(arr[x-1][y], arr[x][y-1]);
					
			}
		}
		
//************PRINTING TABULATION TABLE********************

//	for(int x = 0; x <= m; x++)
//		{
//			for(int y = 0; y <= n; y++)
//			{
//				cout<<arr[x][y];
//			}
//			cout<<endl;
//		}
	longest_length = arr[m][n];
	
	int x = m, y = n, temp = 0;
	while( x > 0 || y > 0)
	{
		if (a[x-1] == b[y-1])
		{
			x = x-1;
			y = y-1;
			lcs.append(a,x,1);
		}
		
		else if(arr[x-1][y] == arr[x][y-1])
		{
			x = x-1;
		}
		
		else
		{
			temp = max(arr[x-1][y], arr[x][y-1]);
			if (arr[x-1][y] == temp)
				x = x-1;
			else
				y = y-1;
		}
	}
	return lcs;
	
}

int main()
{
string a = "ABCBDAB";
string b = "BDCABA";   //CAC
string longest = LCS(a,b, a.size(),b.size());
reverse(longest.begin(),longest.end());
cout<<"Lcs of "<<a<<" & "<<b<<" is: "<<longest<<" (length "<<longest.size()<<")";

}

