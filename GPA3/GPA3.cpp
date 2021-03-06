﻿// GPA3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <list>
using namespace std;

class SafeMap
{
	int V;
	list <int> *adj;
public:
	SafeMap(int V);
	void addSafeRoute(int v, int w);
	int isReachable(int s, int d);

};


SafeMap::SafeMap(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void SafeMap::addSafeRoute(int v, int w)
{
	adj[v].push_back(w); // Add w to v's list.
}

// Function to check if S is safely reachable from D
int SafeMap::isReachable(int s, int d)
{


	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	// it will be used to get all adjacent vertices of a vertex accesible thru
	// a safe route
	list<int>::iterator i;

	//Write your code below this line
	int path = 0;
	if (s == d)
		return path;
	while (!queue.empty())

	{

		// Dequeue a vertex from queue and print it

		s = queue.front();

		queue.pop_front();



		// Get all adjacent vertices of the dequeued vertex s

		// If a adjacent has not been visited, then mark it visited

		// and enqueue it

		for (i = adj[s].begin(); i != adj[s].end(); ++i)

		{

			// If this adjacent node is the destination node, then return true

			if (*i == d) {
				path++;
				return path;
			}


			// Else, continue to do BFS

			if (!visited[*i])

			{

				visited[*i] = true;
				path++;
				queue.push_back(*i);

			}

		}

	}



	return -1;

}




int main()
{
	int pathResult = 0;
	SafeMap g(4);
	g.addSafeRoute(0, 1);
	g.addSafeRoute(0, 2);
	g.addSafeRoute(1, 2);
	//g.addSafeRoute(3, 0);
	g.addSafeRoute(2, 0);
	g.addSafeRoute(2, 3);
	
	pathResult = g.isReachable(0,3);
	if (pathResult == -1)
		cout << "There is no Safe Path" << '\n';
	else
		cout << "There is a Safe Path with length " << pathResult << '\n';

	return 0;
}
