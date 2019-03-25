#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"GraphInterface.h"
int main()
{
FILE *f = fopen("file.txt", "r");
	int a,b,v,c,g,j=0,k,l,w=0,o=0,x=0,y=0,z=0,h=0,V=0,s=0,n;
	int **ptr;
	int *i;
	char str1[30],str2[30],str3[20],str4[20];
	V=60;
	ptr=malloc(V*sizeof(char*));
for(o=0;o<V;o++){
	ptr[o]=malloc(100*sizeof(char));
}
	i=malloc(100*sizeof(int));
    Graph *graph = InitializeGraph(V); 
	o=0;

	while(c != EOF){

		while((c = getc(f)) != '-' && c != EOF){
			if(c=='\n'){s=4;break;}
   			ptr[j][i[j]]=c;
			i[j]++;
		}
		if((o && c!=EOF)|| (s && c!=EOF)){
			for(y=0;y<j;y++){
				for(x=0;x<i[j];x++){
					if(ptr[y][x]!=ptr[j][x]){
						z=3;
						break;
					}
					z=2;
					h=y;
				}
				if(z==2){break;}
			}
			if(z==2){
				for(o=0;o<i[j];o++){
					ptr[j][o]='\0';
				}
				i[j]=0;
				addEdge(graph,w,y);
				w=y;

			}

			else{ if(o && c!=EOF && j<=V)addEdge(graph,w,j);
				w=j;
				j++;
			}


		}
		else{
		w=j;
		o++;
		j++;
		}
		z=0;
		if(s==4){
			o=0;
		}
		s=0;
	}
    for(v=0;v<V;v++){
		choice(&(graph->firstedge[v]));}
printf("Give me the starting station\n");
	scanf ("%s", str1);
	if(strcmp(str1,"Agios")==0 || strcmp(str1,"Ano")==0 || strcmp(str1,"Kato")==0 || strcmp(str1,"Agia")==0 || strcmp(str1,"Nea")==0){
		scanf("%s",str3);
		strcat(str1," ");
		strcat(str1,str3);
	}
printf("Give me the destination\n");
	scanf ("%s", str2);
	if(strcmp(str2,"Agios")==0 || strcmp(str2,"Ano")==0 || strcmp(str2,"Kato")==0 || strcmp(str2,"Agia")==0 || strcmp(str2,"Nea")==0){
		scanf("%s",str4);
		strcat(str2," ");
		strcat(str2,str4);
	}
n=strlen(str1);
k=n;
n=strlen(str2);
l=n;
	y=0;
	z=0;
	for(j=0;j<V;j++){
		if(i[j]==k){
			for(o=0;o<i[j];o++){
				if(z==1){break;}
				if(str1[o]==ptr[j][o]){
					a=j;
					z=0;
				}
				else{z=3;
					break;
				}
			}
			if(z==0){
				z=1;
			}
		}
		if(i[j]==l){
			for(w=0;w<i[j];w++){
				if(y==1){break;}
				if(str2[w]==ptr[j][w]){
					y=2;
					b=j;
				}
				else{y=3;
					break;
				}
			}
			if(y==2){
				y=1;
			}
		}
	}
	if(z==3){
		printf("\nStarting Station not found\n");
		return 1;
	}
	if(y==3){
		printf("\nDestination station not found\n");
		return 1;
	}
 DepthFirst(*graph,Visit,a,b,ptr,i);
	printf("\n");
	free(i);
	for(j=0;j<V;j++)
		free(ptr[j]);
		free(ptr);
    return 0;
}
