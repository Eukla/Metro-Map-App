#define MAXVERTEX 100

typedef enum {FALSE, TRUE} Boolean;

typedef int Vertex;

typedef struct edge {
   Vertex endpoint;
   struct edge *nextedge;
} Edge;

typedef struct graph {
   int n;     /* number of vertices in the graph */
   Edge *firstedge[MAXVERTEX];
} Graph;
typedef struct AdjList
{
	Edge *head; // pointer to head node of list
} List;

