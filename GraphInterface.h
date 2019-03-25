#include"GraphTypes.h"
void choice(Edge **L);
Edge *newANode(int dest);
Graph* InitializeGraph(int V);
void addEdge(Graph* graph, int src, int dest);
void Visit(Vertex x);
void PrintElement(int v,int w,int k);
void DepthFirst(Graph G, void (*Visit)(Vertex x),int start,int dest,int **ptr,int *i);
