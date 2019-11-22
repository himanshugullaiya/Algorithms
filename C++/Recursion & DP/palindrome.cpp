#include <iostream>
#include <string>
using namespace std;

void check(string s)
{
	int len = s.length();
	
	if (len <= 1)
	{
		cout<<"A palindrome";
	}
	
	else if (s[0] == s[len-1])
		return check(s.substr(1,len-2));
	
	else
		cout<<"Not a Palindrome";
	
		
}

int main()
{
	string s = "abbcbba";
	check(s);
}
