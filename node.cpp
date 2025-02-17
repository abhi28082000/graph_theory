// C++ Program to print 
// count of nodes 
// at given level. 
#include <iostream> 
#include <list> 

using namespace std; 

// This class represents 
// a directed graph 
// using adjacency 
// list representation 
class Graph { 
	// No. of vertices 
	int V; 

	// Pointer to an 
	// array containing 
	// adjacency lists 
	list<int>* adj; 

public: 
	// Constructor 
	Graph(int V); 

	// function to add 
	// an edge to graph 
	void addEdge(int v, int w); 

	// Returns count of nodes at 
	// level l from given source. 
	int BFS(int s, int l); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	
	adj[v].push_back(w); 

	
	adj[w].push_back(v); 
} 

int Graph::BFS(int s, int l) 
{ 
	
	bool* visited = new bool[V]; 
	int level[V]; 

	for (int i = 0; i < V; i++) { 
		visited[i] = false; 
		level[i] = 0; 
	} 

	 
	list<int> queue; 

	
	visited[s] = true; 
	queue.push_back(s); 
	level[s] = 0; 

	while (!queue.empty()) { 

		
		s = queue.front(); 
		queue.pop_front(); 

		
		for (auto i = adj[s].begin(); 
				i != adj[s].end(); ++i) { 
			if (!visited[*i]) { 

				
				level[*i] = level[s] + 1; 
				visited[*i] = true; 
				queue.push_back(*i); 
			} 
		} 
	} 

	int count = 0; 
	for (int i = 0; i < V; i++) 
		if (level[i] == l) 
			count++;	 
	return count; 
} 


int main() 
{ 
	
	Graph g(6); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 3); 
	g.addEdge(2, 4); 
	g.addEdge(2, 5); 

	int level = 2; 

	cout << g.BFS(0, level); 

	return 0; 
} 

