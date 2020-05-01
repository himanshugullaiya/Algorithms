// LIFO
// Functions of Stack are:
// 1. top()  - Show the top element
// 2. empty() - bool if stack is empty
// 3. push() - push the element on top
// 4. pop() - removes element from top
// 4. swap() - swapes entire stack with other
// 5. emplace() - insert a new element into the stack container | 
//                While push() function inserts a copy of the value or the parameter passed to the function into the container at the top, 
//                the emplace() function constructs a new element as the value of the parameter and then adds it to the top of the container.

#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std;

void show(stack<int> s)
{
	while (!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}
int main()
{
	stack <int> s;
	s.push(10);
	s.push(15);
	show(s);
}
