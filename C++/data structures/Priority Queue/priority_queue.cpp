// empty()
// size()
// top()
// push()
// pop()
// swap()
// emplace()

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
typedef long long int lli;

void show(priority_queue <int> pq)
{
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
}
int main()
{
	priority_queue <int> pq;
	pq.push(30);
	pq.push(10);
	pq.push(20);
	pq.push(50);
	pq.push(40);
	show(pq);
}

