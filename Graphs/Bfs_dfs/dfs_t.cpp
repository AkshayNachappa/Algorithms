// DFS
//Akshay Nachappa c++ assignment 23/04/2020
/*
DFS implemented for the graph with adjacency list:
0 -> |1|/
1 -> |2|->|3|/
2 -> |4|->|3|/
3 -> |5|/
4 -> |5|/
5 -> /

*/

#include<iostream>
#include<list>                              // list header 
using namespace std;

class Graph                                 // DS of graph
{
    int N;                                  // No. of nodes
    list<int> *adj;                         //Adjacency list
    void DFSStack(int n,bool visited []);   //stack initialization for back tracking
    
public: 
    Graph(int N);                           // constructor to initialize N and adj
    void DFS();                             // func for traversal
    void addEdge(int a, int b);             // func to add edge from a->b
};
Graph::Graph(int N)
{
    this->N = N;                            // initalizing N and adjacency matrix
    adj = new list<int>[N]; 
}
void Graph::addEdge(int a,int b)
{
    adj[a].push_back(b);                    //making linked list for a th node and pushing b to the queue
}
void Graph::DFSStack(int n,bool visited[])
{
    visited[n] = true;                      // mark node as visited and put it on the stack and print it
    cout << n <<" ";
    
   list<int>:: iterator i;                  // iterator to iterate through the adjacency list
   for(i=adj[n].begin();i!=adj[n].end();i++)    
          if(!visited[*i])                  // recursive function to check if node is visited or not
            DFSStack(*i,visited);
   
}
void Graph::DFS()
{
    bool *visited = new bool[N];
    for(int i=0;i<N;i++)                    // initializing all nodes as not visited
        visited[i]=false;
    
    for(int i=0;i<N;i++)                    // traversing through the depth
        if(visited[i]== false)
            DFSStack(i,visited); 
}

int main()
{   cout <<"Traversing from Node 0 \n";
    Graph g(6);                             // graph ds with 6 nodes
    g.addEdge(0, 1);                        // unidirectional edge from 0->1
    g.addEdge(1, 2);                        // 1-> 2 and so on
    g.addEdge(1, 3); 
    g.addEdge(2, 4); 
    g.addEdge(2, 3); 
    g.addEdge(4, 5);
    g.addEdge(3, 5); 
    g.addEdge(5, 5);
    g.DFS();                                // calling the traversal function
    return 0;                               // to traverse from a specific node, pass it a parameter and iterate from there
    
}