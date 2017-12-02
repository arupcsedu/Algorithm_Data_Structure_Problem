/*
 * Author : Arup Kumar Sarker
 * url: http://www.geeksforgeeks.org/graph-and-its-representations/
 * Date: 02-12-2017
 * Description : Implementation of adjacency list using link list
 */

#include<stdio.h>
#include<malloc.h>


struct AdjacencyListNode
{
	int node;
	struct AdjacencyListNode *next;
};

struct AdjacencyList
{
	struct AdjacencyListNode *head;
};

struct NewGraph
{
	int vertex;
	struct AdjacencyList *array;
};
struct AdjacencyListNode* add_new_node(int dest)
{
	struct AdjacencyListNode *node = (struct AdjacencyListNode*) malloc(sizeof(struct AdjacencyListNode));
	node->node = dest;
	node->next = NULL;
	return node;

}
void add_new_edge(struct NewGraph *graph, int src, int dst)
{
	struct AdjacencyListNode *lNode = add_new_node(dst);
	lNode->next = graph->array[src].head;
	graph->array[src].head = lNode;

	lNode = add_new_node(src);
	lNode->next = graph->array[dst].head;
	graph->array[dst].head = lNode;
}
struct NewGraph* create_graph(int v)
{
	struct NewGraph *ngraph = (struct NewGraph*)malloc(sizeof(struct NewGraph));
	ngraph->vertex = v;

	ngraph->array = (struct AdjacencyList*) malloc(v*sizeof(struct AdjacencyList));

	int i = 0;
	for(i = 0;i < v; i++)
	{
		ngraph->array[i].head = NULL;
	}
	return ngraph;
}

void print_graph(struct NewGraph *graph)
{
	int v = graph->vertex;
	for(int i = 0; i < v; i++)
	{
		printf("Source: %d",i);
		while(graph->array[i].head)
		{
			printf("-> %d", graph->array[i].head->node );
			graph->array[i].head = graph->array[i].head->next;
		}
		printf("\n");
	}
}
int main()
{
	int v = 5;
	struct NewGraph *graph = create_graph(v);

	add_new_edge(graph, 0, 4);
	add_new_edge(graph, 1, 2);
	add_new_edge(graph, 1, 3);
	add_new_edge(graph, 1, 4);
	add_new_edge(graph, 2, 3);
	add_new_edge(graph, 3, 4);

	print_graph(graph);

	return 0;
}
