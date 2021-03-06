// GPA3.cpp : Defines the entry point for the console application.
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
	static int path = 0;
	static bool found = false;
	static int finalpath = INT_MAX;
	for (int i = 0; i < V; i++)
		visited[i] = false;

	list<int> Q;
	// Mark the current node as visited and enQ it
	visited[s] = true;
	Q.push_back(s);

	// it will be used to get all adjacent vertices of a vertex accesible thru
	// a safe route
	list<int>::iterator i;

	//Write your code below this line
	path++;
	while (!Q.empty()) {

		s = Q.front();
		cout << s << " ";
		Q.pop_front();


		for (i = adj[s].begin(); i != adj[s].end(); ++i) {
			if (*i == d) {
				visited[*i] = true;
				Q.push_back(*i);
				found = true;
				cout << d << " found after" << path << '\n';
				if (finalpath>path) {
					finalpath = path;
				}
				path = 1;
				return finalpath;
			}
		}
	}

	if (!found) {

		for (i = adj[s].begin(); i != adj[s].end(); ++i) {
			this->isReachable(*i, d);
		}
	}
	if (!found) {
		cout << d << " not found after" << path << '\n';
		return -1;
	}
	return finalpath;
}




int main()
{
	int pathResult = 0;
	SafeMap g(6);
	g.addSafeRoute(0,3);
	//g.addSafeRoute(3,5);
	//g.addSafeRoute(4,3);
	//g.addSafeRoute(3,1);
	//g.addSafeRoute(1,0);
	//g.addSafeRoute(0,1);
	//g.addSafeRoute(2,1);
	
	pathResult = g.isReachable(2,1);
	if (pathResult == -1)
		cout << "There is no Safe Path" << '\n';
	else
		cout << "There is a Safe Path with length " << pathResult << '\n';

	return 0;
}
