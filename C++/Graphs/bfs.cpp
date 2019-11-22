#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;
typedef long long int lli;


class Graph
{
	int V;
	list<int> *adj;

public:

	Graph(int V)
	{
		this -> V = V;
		adj = new list<int>[V];
		
	}
	
	void addEdge(int v1, int v2)
	{
		adj[v1].push_back(v2);
	}
	
	void BFS(int s)
	{
		list<int> queue;
		vector<bool> visited(V,0);
		
		visited[s] = 1;
		queue.push_back(s);
		
		while(!queue.empty())
		{
			s = queue.front();
			cout<<s<<" ";
			queue.pop_front();
			
			for(auto i = adj[s].begin(); i != adj[s].end(); i++)
				{
				if (!visited[*i])
					queue.push_back(*i);
					visited[*i] = 1;
			    }
			
		}
	}
};

int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Breadth First Traversal ";
    g.BFS(0); 
  
    return 0; 
} 
