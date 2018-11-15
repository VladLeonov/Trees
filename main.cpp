#include <graphics.h>
#include <math.h>
#include <iostream>
#include "graph.h"
#include "graphImage.h"
#include "colorfulGraphTraversal.h"
#include "aStar.h"

using namespace std;

priorityPoint** createTestGraph(int size) {
	priorityPoint** graph = new priorityPoint*[size];
	for (int i = 0; i < size; i++) {
		graph[i] = new priorityPoint[size];
		for (int j = 0; j < size; j++) {
			graph[i][j].x = i;
			graph[i][j].y = j;
			graph[i][j].isWall = false;
			graph[i][j].g = 0;
		}
	}
	for (int i = 0; i < size; i++) {
		graph[i][0].isWall = true;
		graph[i][size - 1].isWall = true;
		graph[0][i].isWall = true;
		graph[size - 1][i].isWall = true;
	}
	for (int i = 0; i <= size / 2; i++) {
		graph[i][size / 2].isWall = true;
	}
	
	return graph;
}

int main () {
	
	char choise;
	cout << "Enter '1' for BFS, '2' for DFS or any other symbol for A*." << endl;
	cin >> choise;
	
	int maxX = 1000, maxY = 600;
	initwindow(maxX, maxY);
	setbkcolor(LIGHTGRAY);
	cleardevice();
	
	int treeHeight = 3;
	binaryTree tree = binaryTree(treeHeight);
	int nodeRadius = maxX / (pow(2, treeHeight) + 1) / 4;
	graphImage image = graphImage(tree, getmaxx(), getmaxy(), nodeRadius);
	
	int gridSize = 11;
	priorityPoint** graph = createTestGraph(gridSize);
	gridImage grid = gridImage(gridSize, gridSize, getmaxx(), getmaxy());
	
	switch (choise) {
		case '1':
			BFS(tree, image);
			break;
		case '2':
			DFS(tree, image);
			break;
		default:
			grid.draw(DARKGRAY, WHITE);
			grid.drawWalls(graph, BLACK);
			aStar(graph, &graph[1][1], &graph[1][gridSize - 2], grid);
			getch();
			break;
	}
}
