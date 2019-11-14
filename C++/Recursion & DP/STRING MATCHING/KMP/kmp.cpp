#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void computelps(string pat, int *lps)
{

lps[0] = 0;
int len = pat.length();
int j = 0;
int i = 1;

while( i < len)
{
	if (pat[j] == pat[i])	
	{
		lps[i] = j+1;
		j += 1;
		i += 1;
	}
	
	else if( j == 0 && (pat[j] != pat[i]))
	{
		lps[i] = 0;
		i += 1;
	}
	else
	
	{
		j = lps[j-1];
	}
}
}

void stringsearch(string text, string pat, int* lps)
{
	int len_txt = text.length();
	int len_pat = pat.length();
	
	int i = 0, j = 0, flag = -1;
	while ( i < len_txt)
	{
		if (text[i] == pat[j])
		{
			i += 1;
			j += 1;
			if (j == len_pat)
			{
				cout<<"Match Found at : "<<i-len_pat<<endl;
				j = lps[j-1];
				flag = 1;
			}
		}
		
		else if(j == 0 && pat[j] != text[i])
		{
			i += 1;
		}
		
		else
		{
			j = lps[j-1];
		}
	}
	
	if (flag == -1)
		cout<<"Match Not Found !";
}


int main()
{
	string pat = "AABA";
	string text = "ABABABCABABABCABABABC";
	int lps[pat.length()];
	computelps(pat, lps);
//	for (int i = 0; i < s.length(); i++)
//		cout<<lps[i]<<' ';
	stringsearch(text, pat ,lps);

}
