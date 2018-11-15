#ifndef GRAPH_H
#define GRAPH_H

#define END_OF_ARRAY -1

struct node {
	int color;
	int *neighbors;
};

class binaryTree {	
	public:
		node *nodes;
		node *root;
		int numNodes, height;
		binaryTree(int height);
};

#endif //GRAPH_H
