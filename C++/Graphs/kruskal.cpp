#include<iostream>
#define I INT_MAX
using namespace std;

int edge[9][3]={{1,2,28},{1,6,10},{2,3,16},{2,7,14},{3,4,12},{4,5,22},{4,7,18},{5,6,25},{5,7,24}};
int set[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int included[9]={0,0,0,0,0,0,0,0,0};
int final_edges[2][6];


void join(int u, int v)
{
	if (set[u] < set[v])
		{
			set[u] += set[v];
			set[v] = u;
		}
	
	else
		{
			set[v] += set[u];
			set[u] = v;
		}
		
}

int find(int u)
{
	while(set[u] >= 0)
	{
		u = set[u];
	}
	
	return u;
	
}
int main()
{

	int u,v, y = 0, index_to_include, min = INT_MAX;
	int cost = 0;
	
	while (y < 6)
	{	min = INT_MAX;
		for(int i = 0; i < 9; i++)
			if (included[i] != 1 && included[i] != -1 && edge[i][2] < min)
			{
				min = edge[i][2];
				u = edge[i][0];           // vertex 1 of min. cost edge
				v = edge[i][1];			  // vertex 2 of min. cost edge
				index_to_include = i;
			}
				

//		cout<<"Find "<<u<<": "<<find(u)<<"  Find "<<v<<": "<<find(v)<<endl;
			
		if (find(u) != find(v))	
			{
				final_edges[0][y] = u;
				final_edges[1][y] = v;
				y++;
				join(find(u),find(v));
				included[index_to_include] = 1;	
			}
		
		else
			included[index_to_include] = -1;
	}
	
for(int i = 0; i < 9; i++)
	{
		if (included[i] == 1)
		{
			cost += edge[i][2];
		}
			
	}

cout<<"Kruskal's Algorithm"<<endl;
for(int i = 0; i < 2; i++)
{
	for(int j = 0; j < 6; j++)
		cout<<final_edges[i][j]<<" ";
	cout<<endl;
}

cout<<"Final Cost: "<<cost;
}
