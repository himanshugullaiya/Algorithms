#include <iostream>
#include <vector>
using namespace std;

int dp_power(int num , int pow)
{
	vector<int> v1;
	v1.push_back(1);
	
	for(int i = 1; i <= pow ; i++)
		v1.push_back(v1[i-1]*num);
	
	
	return v1[pow];
}

int recursion_power(int num, int pow)
{
	if (pow == 0)
		return 1;
	
	else
		return recursion_power(num, pow-1)*num;
}

int main()
{
	int a = dp_power(3,3);
	int b = recursion_power(3,3);
	cout<<a;
	cout<<endl<<b;
}

