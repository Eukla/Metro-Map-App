#include<stdio.h>
#include<stdlib.h>
#include"GraphTypes.h"
/* global variable visited */
Boolean visited[MAXVERTEX];
Boolean cvisited[MAXVERTEX];

void choice(Edge **L)

{	int i;

	Edge *K,*M,*B;

	

	B=(*L);
	while( B!=NULL && B->nextedge!=NULL ){		/*while the nevt node is not null*/

		K=B;

		M=K->nextedge;

		while(M!=NULL){		/*we compare the two pointers and if the K points to a smaller int of a node than M trade their int part*/

			if((M->endpoint)<=(K->endpoint)){

				i=K->endpoint;

				K->endpoint=M->endpoint;

				M->endpoint=i;

			}

			M=M->nextedge;

		}

		B=B->nextedge;

	}

}
Edge *newANode(int dest)/*initializing a new edge*/
{
	Edge* newNode =malloc(sizeof(Edge));
	newNode->endpoint = dest;	/*the (v,_) of the edge*/
	newNode->nextedge = NULL;
	return newNode;
}
Graph* InitializeGraph(int V)   /*creating the new array of lists , the graph*/
{
	Graph* graph =malloc(sizeof(Graph));
	graph-> n = V;
	int i;
	for (i = 0; i < V; ++i)
		graph->firstedge[i] = NULL;

	return graph;
}
void addEdge(Graph* graph, int src, int dest)
{	Edge *newNode;
	Edge *p;
	newNode = newANode(dest);	/*initializing the new node as list node*/
	newNode->nextedge = graph->firstedge[src];/*the new node will be the first node in the list*/
	graph->firstedge[src] = newNode;
	newNode = newANode(src);		/*same thing but inthe opposite direction*/
   	 newNode->nextedge = graph->firstedge[dest];
    	graph->firstedge[dest] = newNode;
}
void Visit(Vertex x)
{
  printf("%d\n", x);
}
void PrintEdge(int v,int w,int k)/*print function for each type of edge*/
{		
  printf("(%d,%d) ",v,w);
  if(k==0){printf(":Tree edge\n");}
  if(k==1){printf(":Froward edge\n");}
  if(k==2){printf(":Cross edge\n");}
  if(k==3){printf(":Back edge\n");}
}
/* Traverse: recursive traversal of a graph
   Pre: v is a vertex of graph G
   Post: The depth first traversal, using function Visit, has been
   completed for v and for all vertices adjacent to v.
   Uses: Traverse recursively, Visit */

int Traverse(Graph G, Vertex v, void (*Visit)(Vertex x),int *dfnumber,int wanted,int *array,int *h)
{
  Vertex w;
  Edge *curedge;
static int count=0;
  /*visited[v]=TRUE;*/
  visited[v]=TRUE;
  cvisited[v]=TRUE;
  dfnumber[v]=count;
  count++;
  curedge=G.firstedge[v];      /* curedge is a pointer to the first edge (v,_) of V */
array[*h]=v;
  while (curedge){
    w=curedge->endpoint;        /* w is a successor of v and (v,w) is the current edge */
	if(wanted==w){(*h)++;array[(*h)]=w;return 1;}
    if (!visited[w]){
		(*h)++;
		if(Traverse(G, w, Visit,dfnumber,wanted,array,h)==0){
			array[(*h)]=-1;
			(*h)--;
		}
		else{return 1;}
    }
    
    /*else if(dfnumber[v]<dfnumber[w]){PrintElement(v,w,1);}
    else if(dfnumber[v]>=dfnumber[w]){if(!cvisited[w]){PrintElement(v,w,2);}else{PrintElement(v,w,3);}}*/cvisited[w]=FALSE;
    curedge=curedge->nextedge;  /*curedge is a pointer to the next edge (v,_) of V */
  }
	return 0;
}


/* DepthFirst: depth-first traversal of a graph
   Pre: The graph G has been created.
   Post: The function Visit has been performed at each vertex of G in depth-first order
   Uses: Function Traverse produces the recursive depth-first order */
void DepthFirst(Graph G, void (*Visit)(Vertex x),int start,int dest,int **ptr,int *i)
{
 int dfnumber[G.n];
 int array[G.n],k;
  Vertex v;
int h=0;
  for (v=0; v < G.n; v++){
    visited[v]=FALSE;
    cvisited[v]=FALSE;}
   if(Traverse(G, start, Visit,dfnumber,dest,array,&h)==1){
		printf("Path found! Here it is : ");
		for(v=0;v<=h;v++){/*printing the path*/
			if(array[v]<0){break;}
			for(k=0;k<i[array[v]];k++){
			printf("%c",ptr[array[v]][k]);
			}
	
		if(v!=h){
			printf(" -> ");
			}
		}
   }
   else{
	printf("Sorry, path not found");
   }
}



