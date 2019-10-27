#include <iostream>
#include <vector>
#include <string>
using namespace std;


int LCS(string a, string b, int m , int n)
{
	
	if ( m == 0 || n== 0)
		return 0;
	
	else if (a[m-1] == b[n-1])
		return 1 + LCS(a.substr(0,m-1), b.substr(0,n-1), m-1, n-1);   // string.substr(inclusive,exclusive)
		
	else
		return max(LCS(a.substr(0,m-1), b, m-1, n) , LCS(a, b.substr(0,n-1), m, n-1));
	
}

int main()
{

string a = "DAFSXS";
string b = "QWEDAPSS";
int score = LCS(a,b,a.size(),b.size());   // DASS
cout<<score; 

}

