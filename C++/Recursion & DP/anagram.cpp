#include <iostream>
#include <string>
using namespace std;

void check(string a, string b)
{
	int hashtable_1[26] = {0};
	int hashtable_2[26] = {0};
	
	int starting_no = 97;
	
	for(int i = 0; i < a.length(); i++)
		hashtable_1[a[i]-97] = 1;	
	
	for(int i = 0; i < b.length(); i++)
		hashtable_2[a[i]-97] = 1;
	
	for(int i = 0; i < 26; i++)
	{
		if (hashtable_1[i] != hashtable_2[i])
			{
				cout<<"Not an Anagram !";
				return;
			}
	}
	
	cout<<"An anagram!";
	return;	
}

int main()
{
	check("Decimal","Medical");
}
