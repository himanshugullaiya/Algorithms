// Queue - FIFO (First In First Out)
// empty()
// size()
// swap()
// emplace()
// front() 
// back()
// push()
// pop() - remove an element from back

#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

void show(queue <int> q)
{
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}
int main()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	show(q);
	cout<<"At Front: "<<q.front();
	cout<<"\nAt Back: "<<q.back();
	q.pop();
	cout<<"\nAfter Pop: ";
	show(q);
}
