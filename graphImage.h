#include "graph.h"
#include <cstdio>

#ifndef GRAPH_IMAGE_H
#define GRAPH_IMAGE_H

struct priorityPoint {
	int x, y;
	priorityPoint *parent = NULL;
	int g, f;
	bool isWall;
};

struct point {
	int x, y;
};

class graphImage {
		point *coords;
		int numNodes;
		int radius;
	public:
		graphImage(binaryTree tree, int maxX, int maxY, int radius);
		void draw(int lineColor, int nodeColor);
		void recolorNode(int index, int lineColor, int nodeColor);
};

class gridImage {
	int maxX, maxY;
	int sizeX, sizeY;
	public:
		gridImage(int sizeX, int sizeY, int maxX, int maxY);
		void draw(int lineColor, int nodeColor);
		void drawWalls(priorityPoint** graph, int nodeColor);
		void recolorNode(int pointX, int pointY, int nodeColor);
		void drawline(int point1X, int point1Y, int point2X, int point2Y, int lineColor);
};

#endif //GRAPH_IMAGE_H
