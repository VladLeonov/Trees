#include <math.h>
#include <graphics.h>
#include "graph.h"

binaryTree::binaryTree(int height) {
	numNodes = pow(2, height + 1) - 1;
	nodes = new node[numNodes];
	root = &nodes[0];
	this->height = height;
	
	for (int i = 0; i < numNodes / 2; i++) {
		nodes[i].color = WHITE;
		nodes[i].neighbors = new int[3];
		nodes[i].neighbors[0] = 2 * i + 1;
		nodes[i].neighbors[1] = 2 * i + 2;
		nodes[i].neighbors[2] = END_OF_ARRAY;
	}
	
	for (int i = numNodes / 2; i < numNodes; i++) {
		nodes[i].color = WHITE;
		nodes[i].neighbors = new int[1];
		nodes[i].neighbors[0] = END_OF_ARRAY;
	}
}
