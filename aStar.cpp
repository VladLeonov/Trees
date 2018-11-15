#include "aStar.h"
#include <math.h>
#include <algorithm>
#include <set>
#include <queue>
#include <graphics.h>
#include "graphImage.h"
#include <iostream>

using namespace std;


inline int heuristicEstimateOfDistance(priorityPoint point1, priorityPoint point2) {
	return max(abs(point1.x - point2.x), abs(point1.y - point2.y));
}

typedef bool(*compareFunc)(priorityPoint*, priorityPoint*);
bool compare(priorityPoint* left, priorityPoint* right) { 
	return left->f > right->f;
};
  
bool aStar(priorityPoint** graph, priorityPoint* start, priorityPoint* goal, gridImage grid) {
	set<priorityPoint*> U;
    priority_queue<priorityPoint*, vector<priorityPoint*>, compareFunc> Q(compare);
    set<priorityPoint*> QSet;
    
	start->g = 0;
    start->f = heuristicEstimateOfDistance(*start, *goal);
    start->parent = NULL;
    Q.push(start);
    QSet.insert(start);
    
    grid.recolorNode(start->x, start->y, GREEN);
    grid.recolorNode(goal->x, goal->y, RED);
    getch();
    
    priorityPoint *current;
    const point deltas[8] = {{-1, -1}, {0, -1}, {1, -1},
							 {-1, 0}, {1, 0},
							 {-1, 1}, {0, 1}, {1, 1}};
    while (!Q.empty()) {
    	current = Q.top();
    	if (*current == *goal) {
    		grid.recolorNode(start->x, start->y, GREEN);
    		grid.recolorNode(goal->x, goal->y, RED);
    		for (; current->parent != NULL; current = current->parent) {
    			grid.drawline(current->x, current->y, current->parent->x, current->parent->y, LIGHTGREEN);
			}
			return true;
		}
		
    	Q.pop();
    	QSet.erase(current);
    	U.insert(current);
    	grid.recolorNode(current->x, current->y, BLUE);
    	getch();
    	
    	for (int i = 0; i < 8; i++) {
    		priorityPoint *v = &graph[current->x + deltas[i].x][current->y + deltas[i].y];
    		int tentativeScore = current->g + 1;
    		if ((v->isWall) || ((U.find(v) != U.end()) && (tentativeScore >= v->g))) {
    			continue;
			}

			if ((QSet.find(v) == QSet.end()) || (tentativeScore < v->g)) {
				v->parent = current;
				v->g = tentativeScore;
				v->f = v->g + heuristicEstimateOfDistance(*goal, *v);
				if (QSet.find(v) == QSet.end()) {
					Q.push(v);
					QSet.insert(v);
				}
				grid.recolorNode(v->x, v->y, YELLOW);
				getch();
				grid.recolorNode(v->x, v->y, LIGHTBLUE);
				getch();
			}
		}
	}
	return false;
}

bool operator==(const priorityPoint& point1, const priorityPoint& point2)
{
    return (point1.x == point2.x) && (point1.y == point2.y);
}
