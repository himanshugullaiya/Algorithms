#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <stack>
#define INF INT_MAX
using namespace std;

class Graph
{
	int nv;
	list <pair<int,int>> *adj;
	set<pair<int,int>> set_dist;
	set<pair<int,int>> done;
	list<int> visited;
	
	public:
		Graph(int nv)
		{
			this -> nv = nv;
			adj = new list<pair<int,int>> [nv];
			
		}
		
		void addEdge(int u, int v, int w)
		{
			adj[u].push_back(make_pair(v,w));
			adj[v].push_back(make_pair(u,w));
		}
		
		
		void chg_wt(int wt, int vertex)
		{
			for(auto i = set_dist.begin() ; i != set_dist.end(); ++i)
					if ((*i).second == vertex)
					{
						set_dist.erase(i);
						set_dist.insert(make_pair(wt, vertex));
						break;
					}
		}
		
		int get_wt(int vertex)
		{
			for(auto i = set_dist.begin() ; i != set_dist.end(); ++i)
				if ((*i).second == vertex)
					return (*i).first;                // Return current final weight
			return INF;
		}
		
		int get_minwt()
		{
			int vtx;
			for(auto i = set_dist.begin(); i != set_dist.end(); i++)
				{
					vtx = (*i).second;
					auto j = find(visited.begin(),visited.end(), vtx);
					if (j == visited.end())
					{
						return vtx;
					}
				}
			return -1;
		}

		
		void shortestpath(int src)
		{
			int u;
			for(int i = 0; i < nv; i++)
				set_dist.insert(make_pair(INF,i));   // initialize all vertex to INF
			
			u = src;
			chg_wt(0,src);    // Update src val in set
			visited.push_back(src);   // updated visited for src
		
			while(visited.size() < nv)
			{		
				for(auto i = adj[u].begin(); i != adj[u].end(); ++i)
					{
						int v = (*i).first;
						auto t = find(visited.begin(), visited.end(), v);
						
						if (t == visited.end()) 			// vertex is not found in the visited list
						{	
							int weight = (*i).second;
							int cwt_u = get_wt(u);
							int cwt_v = get_wt(v);
							
							if (cwt_u + weight < cwt_v)
								chg_wt((cwt_u + weight),v);
						}
					}
					
				u = get_minwt();
				visited.push_back(u);
			}
		
	 	}
	 	
	 	void show()
	 	{
	 		for(auto i = set_dist.begin(); i != set_dist.end(); i++)
  				cout<<"Vertex "<< (*i).second<<" : Distance "<<(*i).first<<endl;
		}


};




int main()
{

	int V = 9; 
    Graph g(V); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    g.shortestpath(0); 
  
  	g.show();
    
	
	return 0; 

	
}
