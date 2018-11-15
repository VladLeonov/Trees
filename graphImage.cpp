#include "graphImage.h"
#include <math.h>
#include <graphics.h>

graphImage::graphImage(binaryTree tree, int maxX, int maxY, int radius) {
	
	this->numNodes = tree.numNodes;
	int height = tree.height;
	coords = new point[numNodes];
	this->radius = radius;
	
	int firstInRow = numNodes / 2;
	int lastInRow = numNodes - 1;
	int divisor = numNodes / 2 + 2;
	for (int i = firstInRow, j = 1; i <= lastInRow; i++, j++) {
		coords[i].x = maxX * j / divisor;
	}
	
	for (int i = firstInRow - 1; i >= 0; i--) {
		coords[i].x = (coords[2 * i + 1].x + coords[2 * i + 2].x) / 2;
	}
	
	for (int i = 1; i <= height + 1; i++) {
		firstInRow = pow(2, i - 1) - 1;
		lastInRow = pow(2, i) - 2;
		for (int j = firstInRow; j <= lastInRow; j++) {
			coords[j].y = maxY * i / (height + 2);
		}
	}
}

void graphImage::draw(int lineColor, int nodeColor) {
	setcolor(lineColor);
	setlinestyle(SOLID_LINE, 1, THICK_WIDTH);
	setfillstyle(SOLID_FILL, nodeColor);
	
	for (int i = 0; i < numNodes / 2; i++) {
		line(coords[i].x, coords[i].y, coords[2 * i + 1].x, coords[2 * i + 1].y);//bad indeces
		line(coords[i].x, coords[i].y, coords[2 * i + 2].x, coords[2 * i + 2].y);//
	}
	
	for (int i = 0; i < numNodes; i++) {	
		fillellipse(coords[i].x, coords[i].y, radius, radius);
	}
}

void graphImage::recolorNode(int index, int lineColor, int nodeColor) {
	setcolor(lineColor);
	setlinestyle(SOLID_LINE, 1, THICK_WIDTH);
	setfillstyle(SOLID_FILL, nodeColor);
	fillellipse(coords[index].x, coords[index].y, radius, radius);
}

gridImage::gridImage(int sizeX, int sizeY, int maxX, int maxY) {
	this->maxX = maxX;
	this->maxY = maxY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

void gridImage::draw(int lineColor, int nodeColor) {
	setbkcolor(nodeColor);
	cleardevice();
	setcolor(lineColor);
	setlinestyle(SOLID_LINE, 1, THICK_WIDTH);
	
	int coord;
	for (int i = 0; i <= sizeX; i++) {
		coord = maxX * i / sizeX;
		line(coord, 0, coord, maxY);
	}
	for (int i = 0; i <= sizeY; i++) {
		coord = maxY * i / sizeY;
		line(0, coord, maxX, coord);
	}
}

void gridImage::drawWalls(priorityPoint** graph, int nodeColor) {
	setfillstyle(SOLID_FILL, nodeColor);
	
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			if (graph[i][j].isWall) {
				bar(maxX * i / sizeX + THICK_WIDTH - 1, maxY * j / sizeY + THICK_WIDTH / 2, 
				maxX * (i + 1) / sizeX - 1, maxY * (j + 1) / sizeY - 1);
			}
		}
	}
}

void gridImage::recolorNode(int pointX, int pointY, int nodeColor) {
	setfillstyle(SOLID_FILL, nodeColor);
	bar(maxX * pointX / sizeX + THICK_WIDTH - 1, maxY * pointY / sizeY + THICK_WIDTH - 1, 
		maxX * (pointX + 1) / sizeX - 1, maxY * (pointY + 1) / sizeY - 1);
}

void gridImage::drawline(int point1X, int point1Y, int point2X, int point2Y, int lineColor) {
	setlinestyle(SOLID_LINE, 1, THICK_WIDTH);
	setcolor(lineColor);
	line((maxX * point1X + maxX / 2) / sizeX, (maxY * point1Y + maxY / 2) / sizeY, 
		 (maxX * point2X + maxX / 2) / sizeX, (maxY * point2Y + maxY / 2) / sizeY);
}
