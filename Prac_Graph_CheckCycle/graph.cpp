/*
 * Question 2
Cycle detection: write a C++ function that for a directed graph, given a starting vertex, detects
whether that vertex is a part of a cycle. A vertex is a part of a cycle if a path exists that will
eventually return to the starting vertex. Below is a visual example. Your function should return
TRUE for vertices 3, 4, or 5. It should return FALSE for 1 or 2. Your function should be named
detectCycleHelper() and be called by detectCycle(), as shown below in the class definition.
 */

#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

int Graph::insertVertex(int k) {
	Vertex *newVertex = new Vertex;
	newVertex->key = k;
	vertices.push_back(newVertex);
	return 0;
}

int Graph::insertEdge(int start, int end) {
	adjVertex         *newEdge = new adjVertex;
	for (unsigned int i        = 0; i < vertices.size(); i++) {
		if (vertices[i]->key == start) { // find start @ index 'i'
			for (unsigned int j = 0; j < vertices.size(); j++) {
				if (vertices[j]->key == end) { // find end @ index 'j'
					newEdge->v = vertices[j];
					vertices[i]->adjList.push_back(*newEdge);
					return 0;
				}
			}
			cout << "End node not found :(\n";
			return -1;
		}
	}
	cout << "Start node not found :(\n";
	return -1;
	//newEdge->v = ??; // Vertex reference containing the 'end' value;
}

Vertex *Graph::search(int k) {
	for (unsigned int i = 0; i < vertices.size(); i++) {
		if (vertices[i]->key == k) {
			//cout << "Found it!\n";
			return vertices[i];
		}
	}
	cout << "Didn't find the key :(\n";
	return NULL;
}

bool detectCycleHelper(Vertex *start, Vertex *next) {
	if (start == next && next->visited) {
		return true;
	}
	else if (next->visited) {
		return false;
	}
	else {
		next->visited = true;
		if (next->adjList.size() <= 0) { return false; }
		else {
			for (int i = 0; i < next->adjList.size(); i++) {
				if (detectCycleHelper(start, next->adjList[i].v)) { return true; }
			}
		}
	}
	return false;
}

bool Graph::detectCycle(int k) {
	Vertex *startV = search(k);
	int    index   = 0;

	for (int indx = 0; indx < vertices.size(); ++indx) {
		vertices[indx]->visited = false;
		if (vertices[indx] == startV) {
			index = indx;
		}
	}

	if (startV) {
		startV->visited = true;
		for (int i = 0; i < startV->adjList.size(); i++) {
			if (detectCycleHelper(startV, startV->adjList[i].v)) { return true; }
		}
	}
	return false;
}
