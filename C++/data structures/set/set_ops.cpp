// Set - Each element is unique| always in ascending order o(1) | value of element cannot be edited once entered | o(log n) ops
// begin
// end
// size
// max_size
// empty
// rbegin
// rend
// insert
// erase
// find
// count
// lower_bound
// upper_bound
// 
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
typedef long long int lli;

int main()
{
// storing elements in ascending order
set<int> a = {3,1,2,6};
a.insert(25);
a.insert(20);
set<int>::iterator i_asc;
for(i_asc = a.begin(); i_asc != a.end(); i_asc++)
	cout<<*i_asc<<" ";

cout<<endl;

// storing elements in descending order
set<int , greater<int>> a_2 = {3,1,2,6,25,1,1,20};
for(int i : a_2)
	cout<<i<<" ";

cout<<endl<<"The No of Occurences of 1 is : "<< count(a_2.begin(), a_2.end(), 1);
}

