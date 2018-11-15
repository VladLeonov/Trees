#include "graphImage.h"

#ifndef A_STAR_H
#define A_STAR_H

bool operator==(const priorityPoint& point1, const priorityPoint& point2);

int heuristicEstimateOfDistance(priorityPoint point1, priorityPoint point2);
bool aStar(priorityPoint** graph, priorityPoint* start, priorityPoint* goal, gridImage grid);

#endif //A_STAR_H
