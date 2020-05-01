// priority_queue <Type, vector<Type>, ComparisonType > min_heap;	
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
typedef long long int lli;

int main()
{
	priority_queue <int, vector<int>, greater<int>> pq;
	pq.push(5);
	pq.push(1);
	pq.push(10);
	pq.push(30);
	pq.push(20);
	
	while (!pq.empty())
	{
		cout<<pq.top() <<" ";
		pq.pop();
	}
	cout<<endl;
}

