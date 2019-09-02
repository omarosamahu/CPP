#include <iostream>
#include <vector>

struct Edge
{
    int src,dst;
};

class Graph{
    public:
    std::vector<std::vector<int>> adjlist;
    //Graph constructor
    Graph(std::vector<Edge> const &edges,int N){
        adjlist.resize(N);

        for(auto &edge:edges){
            adjlist[edge.src].push_back(edge.dst);
        }
    }
};

void printGraph(Graph const& graph,int N){
    for (size_t i = 0; i < N; i++)
    {
        std::cout << i << "-->";
        for(auto v : graph.adjlist[i]){
            std::cout << v <<" ";
        }
        std::cout << std::endl;
    }
    
}

int main(int argc, char const *argv[])
{
    std::vector<Edge> nodes = {{0,1},
    {1,2},{2,0},{2,1},{2,3},{2,4},{3,0},{4,2}};
    Graph g(nodes,5);
    printGraph(g,5);
    return 0;
}






/*
#include <iostream>
#include <vector>

using vect = std::vector<int>;

void addEdge(vect adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vect adj[],int V){

    for(int v=0;v<V;v++){
        
        std::cout << "\n Adjacency list of vertex "
             << v << "\n head ";
             for (auto item : adj[v])
             {
                 std::cout <<"-> " << item;
             }
            std::cout << std::endl;
    }
}
int main(int argc, char const *argv[])
{   
    
    int v = 5;
    vect adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,4);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    printGraph(adj,v); 
    return 0;
}

*/