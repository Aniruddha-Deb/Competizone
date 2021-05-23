#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>

typedef struct Node Node;

struct Node {
	char c;
	int ns;
	Node *parent;
	Node *children[26];
};

void add_child(Node *parent, Node *n) {
	int index = n->c - 97;
	parent->children[index] = n;
}

Node* new_node(char ch, Node *parent) {
	Node *n = malloc(sizeof(Node));
	n->c = ch;
	for (int i=0; i<26; i++) {
		n->children[i] = NULL;
	}
	n->parent = parent;
	if (parent != NULL) {
		parent->ns++;
		add_child(parent, n);
	}
	return n;
}

void trieify(Node *root, char *str, int index) {
	bool tried = false;
	for (int i=0; i<26; i++) {
		if (root->children[i] != NULL && root->children[i]->c == str[index]) {
			tried = true;
			root->ns++;
			trieify(root->children[i], str, index+1);
			break;
		}
	}

	if (!tried) {
		Node *prev = new_node(str[index], root);
		for (int i=index+1; i<strlen(str); i++) {
			Node *temp = new_node(str[i], prev);
			prev = temp;
		}
	}
}

void print_trie(Node *root, int depth) {
	char *padding = malloc(depth+1);
	memset(padding, ' ', depth);
	padding[depth] = '\0';
	printf("%s%c (%d)\n", padding, root->c, root->ns);
	for (int i=0; i<26; i++) {
		if (root->children[i] != NULL) print_trie(root->children[i], depth+1);
	}
}

uint64_t dfs_trie(Node *root, int num) {
	uint64_t sum = 0;
	for (int i=0; i<26; i++) {
		if (root->children[i] != NULL && (root->children[i]->ns>=num || (root->children[i]->ns==0 && num==1))) {
			sum++;
			sum += dfs_trie(root->children[i], num);
		}
	}
	return sum;
}

int main() {
	int t;
	scanf("%d\n", &t);

	Node* root = new_node('*', NULL);
	char str[50001];
	for (int i=0; i<t; i++) {
		scanf("%s", str);
		trieify(root, str, 0);
	}

	// print_trie(root, 0);
	uint64_t ans[50000];
	memset(ans, -1, 50000);

	scanf("%d\n", &t);
	int n;
	for (int i=0; i<t; i++) {
		scanf("%d\n", &n);
		if (ans[n] == -1) ans[n] = dfs_trie(root, n);
		printf("%" PRIu64 "\n", ans[n]);
	}
	return 0;
}
