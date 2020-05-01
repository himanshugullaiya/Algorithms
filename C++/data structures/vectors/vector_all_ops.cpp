#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
typedef long long int lli;

void show(vector<int> &v)
{
	for(int i : v)
		cout<<i<<" ";
	cout<<endl;
}

int main()
{
vector<int> vec = {3,4,1,2};
//cout<<"Size -  (no of elements): "<<vec.size();
//cout<<"\nmax_Size - (max no. of elments a vector can hold): "<<vec.max_size();
//cout<<"\ncapacity - (size of storage currently allocated): "<<vec.capacity();
//cout<<"\nresize(n) - (resize container so that it contains n elements) : "<<vec.size();
//cout<<"\nshrink_to_fit() - (reduce the capacity of container to fit it's size & destroy all elements beyond it's capacity: ";vec.shrink_to_fit();
//cout<<"\nreserve() - Requests that the vector capacity be at least enough to contain n elements. ";vec.reserve(15);


// 1. Insert
// 1a. 
vec.insert(vec.begin()+3,100);  // insert 100 at index 3
show(vec);
// 1b.
vec.insert(vec.begin()+4, 2, 50); // insert 50 at index 4 two times
show(vec);
// 1c.
vector<int> vec2 = {1,5,2,10};
vec.insert(vec.end(), vec2.begin(), vec2.end()); // insert vec2 in vec at position vec.end(). eg format (vec.insert(pos, 2binserted.begin(), 2b.inserted.end());
show(vec);

// 2. empty
cout<<vec.empty()<<endl;

// 3. erase
vec.erase(vec.begin()+3); // erase elements from vector using index iterator of vector type
show(vec);

// 4. clear
vec.clear();
cout<<"Cleared: ";show(vec);

// 5. Fill
vec.resize(5);
fill(vec.begin(), vec.end(), 4);
show(vec);

// 6. Sort
vec.insert(vec.end(), vec2.begin(), vec2.end());

// Ascending
sort(vec.begin(), vec.end());

// Descending
sort(vec.begin(), vec.end(), greater<int>());
show(vec);

// 7. at
cout<<vec.at(2)<<endl;

// 8. front
cout<<vec.front()<<endl;

// 9. back
cout<<vec.back()<<endl;

// 10. copy one vector to other
vector<int> v1 (vec);
show(v1);

// 11. lower_bound & upper bound
// lower-bound : lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’.
// upper-bound : upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’.
// works best in asceding sorted container

sort(vec.begin(),vec.end());
show(vec);
vector<int>::iterator lower,upper;
lower = lower_bound(vec.begin(), vec.end(), 4); // returns the iterator pointing index of first occurence of 4
upper = upper_bound(vec.begin(), vec.end(), 4); // returns the iterator pointing index +1 of last occurence of 4

cout << "lower_bound for 4 at position " << (lower- vec.begin()) << '\n'; 
cout << "upper_bound for 4 at position " << (upper - vec.begin()) << '\n'; 

// 11. search one sequence into another
vector<int> v2 = { 1, 2, 3, 4, 5, 6, 7 }; 	
vector<int> v3 = { 3, 4, 5 }; 
auto i1 = search(v2.begin(), v2.end(), v3.begin(), v3.end()); // if the sequence is found then i1 will point to the first element else to the end
cout<<"The sequence is found at: "<<i1 - v2.begin();

// 12. Sum of all elements
cout<<accumulate(v2.begin(), v2.end(), 0);
}

