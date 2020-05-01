// Heap - A datastructure implemented by trees eg. - max_heap (all parent nodes are > than child nodes)
// make_heap() - able to convert any container into heap Eg: make_heap(vec.begin(), vec.end())
// front() - Highest number in heap
// push_heap() - insert elements in heap
// pop_head() -  Outputs the first code ee every day
// sort_heap() - sort that heap (no longer a heap) Eg: sort_heap(v1.begin(), v1.end()); 
// is_heap() - This function is used to check whether the container is heap or not.



#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm> // also contains heap

using namespace std;
typedef long long int lli;

int main()
{
 vector<int> vec = {15,10,2,9,3,7,3,1,20};
 make_heap(vec.begin(),vec.end()); // convert container to heap | By default max_heap is implemented
// cout<<vec.front();
 for(auto i : vec)
 	cout<<i<<" ";

cout<<endl;

// sort_heap(vec.begin(), vec.end()); cout<<endl;
	pop_heap(vec.begin(),vec.end()); 
	vec.pop_back();
	
 for(auto i : vec)
 	cout<<i<<" ";


}

