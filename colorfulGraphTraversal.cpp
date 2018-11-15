#include "colorfulGraphTraversal.h"
#include <queue>
#include <graphics.h>

void BFS(binaryTree tree, graphImage image) {
	for (int i = 1; i < tree.numNodes; i++) {
		tree.nodes[i].color = WHITE;
	}
	image.draw(BLACK, WHITE);
	getch();
	
	tree.nodes[0].color = DARKGRAY;
	image.recolorNode(0, BLACK, DARKGRAY);
	getch();
	
	queue<int> Q;
	Q.push(0);
	int u;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		int *neighbors = tree.nodes[u].neighbors;
		for (int i = 0; neighbors[i] != END_OF_ARRAY; i++) {
			if (tree.nodes[neighbors[i]].color == WHITE) {
				tree.nodes[neighbors[i]].color == DARKGRAY;
				image.recolorNode(neighbors[i], BLACK, DARKGRAY);
				getch();
				Q.push(neighbors[i]);
			}
		}
		tree.nodes[u].color = BLACK;
		image.recolorNode(u, BLACK, BLACK);
		getch();
	}
}

void DFSVisit(binaryTree tree, graphImage image, int u) {
	tree.nodes[u].color = DARKGRAY;
	image.recolorNode(u, BLACK, DARKGRAY);
	getch();
	
	int *neighbors = tree.nodes[u].neighbors;
	for (int i = 0; neighbors[i] != END_OF_ARRAY; i++) {
		if (tree.nodes[neighbors[i]].color == WHITE) {
			DFSVisit(tree, image, neighbors[i]);
		}
	}
	
	tree.nodes[u].color = BLACK;
	image.recolorNode(u, BLACK, BLACK);
	getch();
}

void DFS(binaryTree tree, graphImage image) {
	for (int i = 1; i < tree.numNodes; i++) {
		tree.nodes[i].color = WHITE;
	}
	image.draw(BLACK, WHITE);
	getch();
	
	DFSVisit(tree, image, 0);
}
