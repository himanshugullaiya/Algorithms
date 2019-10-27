#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int LCS(string a, string b, int m,int  n)   // m,n - lengths of a,b  (rows,columns)
{
    int arr[m + 1][n + 1];
    memset(arr, 0, sizeof(arr));
    string lcs;
    int longest_length;

    for (int x = 1; x <= m; x++) {
        for (int y = 1; y <= n; y++) {
            if (a[x - 1] == b[y - 1])
                arr[x][y] = (1 + arr[x - 1][y - 1]);

            else
                arr[x][y] = max(arr[x - 1][y], arr[x][y - 1]);

        }
    }
    longest_length = arr[m][n];
    return longest_length;
}

int min_edits(string a, string b, int len_a, int len_b,int  match)    // a -> b
{
    int insert = 0, remove = 0, replace = 0, total = 0;
    if (len_a > len_b) {
        insert = 0;
        remove = len_a - len_b;
        replace = len_a - (remove + match);
    }

    else if(len_a < len_b)
    {
        insert = len_b - len_a;
        remove = 0;
        replace = len_a - match;
    }
    else
    {
        insert = 0;
        remove = 0;
        replace = len_a - match;
    }
    total = replace + remove + insert;
    return total;
}


int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        string a,b;
        int match, result, len_a, len_b;
        cin>>len_a>>len_b;
        cin>>a>>b;
        match = LCS(a,b,len_a, len_b);
        result = min_edits(a,b,len_a,len_b,match);
        cout<<result<<endl<<endl;
    }
}
