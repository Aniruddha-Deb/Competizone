#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define INITIAL_SIZE 1
#define MULTIPLIER 2

typedef struct Node {
	struct Node **children;
	int num;
	int nchildren;
	int size;
} Node;

Node* new_node(int num) {
	Node *n = calloc(sizeof(Node), 1);
	n->nchildren = 0;
	n->num = num;
	n->children = calloc(sizeof(Node), INITIAL_SIZE);
	n->size = INITIAL_SIZE;
	return n;
}

void add_child(Node *n, Node *child) {
	if (n->nchildren+1 >= n->size && n->children != NULL) {
		n->size *= MULTIPLIER;
		printf("Attempting to reallocate %d to size %d\n", n->num, n->size);
		n->children = realloc(n->children, n->size);
	}
	n->children[n->nchildren++] = child;
}

int count(Node *root) {
	int nleaves = 0;
	int nnodes = 0;
	for (int i=0; i<root->nchildren; i++) {
		if (root->children[i]->nchildren != 0) {
			nnodes += count(root->children[i]);
		}	
	}
	int nch = root->nchildren;
	for (int i=0; i<nch; i++) {
		if (root->children[i]->nchildren == 0) nleaves++;
		else nnodes++;
	}
	nleaves %= 3;
	nnodes += nleaves;
	return nnodes;
}


int main() {
	int t;
	scanf("%d\n", &t);
	while (t-- > 0) {
		int n, p;
		scanf("%d\n", &n);
		Node **nodes = malloc(sizeof(Node)*n);
		nodes[0] = new_node(1);
		for (int i=1; i<n; i++) {
			scanf("%d", &p);
			printf("Input node %d\n", i+1);
			nodes[i] = new_node(i+1);
			add_child(nodes[p-1], nodes[i]);
		}

		Node *root = nodes[0];
		// DFS
		int nnodes = count(root);
		printf("%d\n", nnodes);
	}
	return 0;
}
