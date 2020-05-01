#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
typedef long long int lli;

int main()
{
	map <int, int> student_marks;
	student_marks.insert(pair<int,int> (1,100));
	student_marks.insert(pair<int,int> (2,40));
	student_marks[3] = 40; 
	student_marks[4] = 112;
	
	map<int, int> mp2(student_marks.begin(), student_marks.end()); 
	cout<<student_marks[2]<<endl;
	
	
	map<int,int>::iterator i1;
	
	for(i1 = student_marks.begin(); i1 != student_marks.end(); i1++)
		{
			cout<<i1->first<<" "<<i1->second;
			cout<<endl;
		}
	
	// lower_bound : find the key of the element which has the same value
	// upper_bound : find the key of the element which has the 
	
	cout<<endl<<student_marks.lower_bound(40)->first;
	cout<<endl<<student_marks.lower_bound(40)->second;
	
	///////////////////////////////////////////////////
	cout<<endl<<"\nErase Function : erase all till key 3\n";
	map<int,int>::iterator i2;
	
	student_marks.erase(student_marks.begin(), student_marks.find(3));
	
		for(i1 = student_marks.begin(); i1 != student_marks.end(); i1++)
		{
			cout<<i1->first<<" "<<i1->second;
			cout<<endl;
		}
	
}

