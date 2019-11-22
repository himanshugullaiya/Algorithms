#include <iostream>
#define I INT_MAX

using namespace std;

int cost[][8]=  {{I,I,I,I,I,I,I,I},
				 {I,I,25,I,I,I,5,I},
				 {I,25,I,12,I,I,I,10},
				 {I,I,12,I,8,I,I,I},
				 {I,I,I,8,I,16,I,14},
				 {I,I,I,I,16,I,20,18},
				 {I,5,I,I,I,20,I,I},
				 {I,I,10,I,14,18,I,I}};

int near[8] = {I,I,I,I,I,I,I,I};

int edges[2][7];




int main()
{

	int x,y,u,v,min = I;                // u - row , v - column (Used to fill Near Array)
	int vertex_in_use;
	
	
	//...............................INTIAL STEPS...........................//
	for(int i = 0; i < 8; i++)
		for(int j = i; j < 8; j++)
			{
				if (cost[i][j] <= min)
				{
					u = i;
					v = j;
					min = cost[i][j];
				}
			}	
			
			
	x = 0, y = 0;
	edges[x][y] = u;                  // x - row ,  y - column  (Used to fill edges array)
	edges[x+1][y] = v;  y++;
	
	near[u] = 0;
	near[v] = 0;


	
	for(int i = 1; i < 8; i++)
		{
			if (near[i] != 0)
				{
					if (cost[i][u] < cost[i][v])
						near[i] = u;
					else
						near[i] = v;
				}
				
		}
	//...........................*.*...................................//
	
	for(int i = 1; i < 8; i++)
	cout<<near[i]<<" ";
cout<<endl;

	
	while(y < 6)
	{	min = I;
		
		for(int i = 1; i < 8; i++)      // Find Minimum Edge using near array from cost matrix
			if (near[i] != 0)
			{		
			if (cost[i][near[i]] < min)
				{
					min = cost[i][near[i]];
					vertex_in_use = i;
					
					edges[x][y] = i;
					edges[x+1][y] = near[i]; 
				}
			}
		y++;
		near[vertex_in_use] = 0;
		
		for(int i = 1; i < 8; i++)                               // Update Near Array
			if (near[i] != 0)
			{		
				if (cost[i][vertex_in_use] <= cost[i][near[i]])
					{
						near[i] = vertex_in_use;
					}
			}
	}
		

for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 6; j++)
			cout<<edges[i][j];
		cout<<endl;
	}
	
	
}
