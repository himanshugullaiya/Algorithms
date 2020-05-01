// randomised insertion | all unordered set ops takes O(1) average time, &  O(n) worst


#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef long long int lli;

int main()
{
	unordered_set <string> stringset;
	stringset.insert("ajay");
	stringset.insert("lalit");
	stringset.insert("jaat");
	
	
//	for(string i : stringset)
//		cout<<i<<" ";
		
	// Given a set of integers, find all the duplicates among them.
	// Input  : arr[] = {1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5}
	// Output : Duplicate item are : 5 2 1 
	
	int arr[] = {1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5};
	int n = 12;
	unordered_set <int> intset;
	unordered_set <int> duplicate;

// gfg approach	
	for(int i = 0; i < n; i++)
		{
			if (intset.find(arr[i]) == intset.end())
			{
				intset.insert(arr[i]);
			}
			else
				duplicate.insert(arr[i]);
		}
	
//	for(auto i = duplicate.begin(); i != duplicate.end(); i++)
//		cout<<*i<<" ";

//  my approach
	unordered_set <int> insertelems;
	unordered_set <int> dups;
	int size1 = insertelems.size();
	for(int i = 0; i < n; i++)
		{
			
			insertelems.insert(arr[i]);
			
			if (insertelems.size() == size1)
				dups.insert(arr[i]);
			else
				size1++;
			
		}
	
		for(auto i = dups.begin(); i != dups.end(); i++)
			cout<<*i<<" ";
	
	///////////////////
	
	cout<<"\nBucket No of 2 is : "<<dups.bucket(2);
}
// The bucket is a slot in the unordered_set’s internal hash table where elements are stored.

//insert()– Insert a new {element} in the unordered_set container.
//begin()– Return an iterator pointing to the first element in the unordered_set container.
//end()– Returns an iterator pointing to the past-the-end-element.
//count()– Count occurrences of a particular element in an unordered_set container.
//find()– Search for an element in the container.
//clear()– Removes all of the elements from an unordered_set and em pties it.
//cbegin()– Return a const_iterator pointing to the first element in the unordered_set container.
//cend()– Return a const_iterator pointing to past-the-end element in the unordered_set container or in one of it’s bucket.
//bucket_size()– Returns the total number of elements present in a specific bucket in an unordered_set container.
//erase()– Remove either a single element of a range of elements ranging from start(inclusive) to end(exclusive).
//size()– Return the number of elements in the unordered_set container.
//swap()– Exchange values of two unordered_set containers.
//emplace()– Insert an element in an unordered_set container.
//max_size()– Returns maximum number of elements that an unordered_set container can hold.
//empty()– Check if an unordered_set container is empty or not.
//equal_range– Returns range that includes all elements equal to given value.
//operator= – Copies (or moves) an unordered_set to another unordered_set and unordered_set::operator= is the corresponding operator function.
//hash_function() – This hash function is a unary function which takes asingle argument only and returns a unique value of type size_t based on it.
//reserve()– Used to request capacity change of unordered_set.
//bucket()– Returns the bucket number of a specific element.
//bucket_count() – Returns the total number of buckets present in an unordered_set container.
//load_factor()– Returns the current load factor in the unordered_set container.
//rehash()– Set the number of buckets in the container of unordered_set to given size or more.
//max_load_factor()– Returns(Or sets) the current maximum load factor of the unordered set container.	

