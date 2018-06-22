// A C++ Program to detect cycle in a graph
#include<bits/stdc++.h>
#include <list>
#include <limits.h>

using namespace std;
bool visited[100];
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
	bool isCyclicUtil(int v,int, int &t); // used by isCyclic()
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	bool isCyclic(); // returns true if there is a cycle in this graph
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// This function is a variation of DFSUytil() in https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclicUtil(int v, int parent,int &t)
{
	visited[v]=true;
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
	{
	    if(t || (visited[*i]==true && v!=parent))
	   {
	       t=1;
	       return true;
	   }
	   else if(visited[*i]==false)
	        isCyclicUtil(*i,v,t);

	}
	return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclic()
{
	// Mark all the vertices as not visited and not part of recursion
	// stack
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	// Call the recursive helper function to detect cycle in different
	// DFS trees
	int p=0;
	for(int i = 0; i < V; i++)
		if (visited[i]==false && isCyclicUtil(i,i,p))
			return true;

	return false;
}

int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	//g.addEdge(2, 1);
	g.addEdge(2, 3);

	if(g.isCyclic())
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";
	return 0;
}
