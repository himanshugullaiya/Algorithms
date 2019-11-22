#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long int lli;

int fact(int x)
{
	if (x > 1)
		return fact(x-1)*x;
	
	else
		return 1;
}

float binomial(int n, int r)
{
	int numer = fact(n);
	int denom = fact(n-r);
	return numer/denom;
}


int main()
{

cout<<binomial(4,2);

}

