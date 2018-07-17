#include<iostream>
#include<list>
#include<vector>
#include "main.h"
#include "test.h"

using namespace std;

Graph::Graph(int num_of_vertexes)
{
	this->num_of_vertexes = num_of_vertexes;
	edges = new list<pair<int,int>>[num_of_vertexes];
}

void Graph::addEdge(int v, int w, int weight)
{
	edges[v].push_back(make_pair(w,weight)); // add edge (v,w) with weight 
}

int Graph::find_distance(vector<int>& route)
{
	int distance = 0;
	list<pair<int,int>>::iterator it;
	bool found = true;

	for (unsigned int i = 0; i < route.size()-1; i++)
	{
		if (found)
		{
			found = false;
			for (it = edges[route[i]].begin(); it != edges[route[i]].end(); ++it)
			{
				int end_vertex = it->first;
				if (route[i + 1] == end_vertex)
				{
					int weight = it->second;
					distance = distance + weight;
					found = true;
					break;
				}
			}
		}
	}
	if (!found)
	{
		distance = -1;
	}

	return distance;
}


int Graph::number_of_trips(int s, int d, int bound,bool exact)
{

	int count = 0;

	int path_length = -1; 

	vector<int> path;

	number_of_trips(s, d, path, path_length, count,bound,exact);

	return count;

}


void Graph::number_of_trips(int u, int d, vector<int>& path,int& path_length, int& count, int bound, bool exact)
{

	path_length++;

	if (path_length > bound)
	{
		path_length--;
		return;
	}

	list<pair<int, int>>::iterator it;

	if (u == d)
	{
		if (path_length > 0 && ((path_length==bound && exact) || (path_length<= bound && !exact))) {
			count++;
		}
	}

	for (it = edges[u].begin(); it != edges[u].end(); ++it) {

		number_of_trips(it->first, d, path, path_length, count, bound, exact);

	}

	path_length--;
	
}

int Graph::minDistance(vector<int> dist, vector<bool> used_set, int s)
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < num_of_vertexes ; v++)
		if (used_set[v] == false && dist[v] <= min) {
			min = dist[v]; 
			min_index = v;
		}

	return min_index;
}

vector<int> Graph::find_all_minimal_distances(int s)
{
	vector<int> dist(num_of_vertexes);     //shortest distance to i
					 

	vector<bool> used_set(num_of_vertexes); 

    // Initialize all distances as INF and used_set[] as false
	for (int i = 0; i < num_of_vertexes; i++)
		dist[i] = INT_MAX, used_set[i] = false;

	dist[s] = 0;

	list<pair<int, int>>::iterator it;
	
	
	// Find shortest path for all vertices
	for (int count = 0; count < num_of_vertexes-1; count++)
	{
		//Pick vertex with minimal distance (at the beginning it is always s) 
		int u = minDistance(dist, used_set,s);

		// Mark the picked vertex 
		
		used_set[u] = true;

		// Update dist value of the neigbouring vertices of the picked vertex.
		
		for (it = edges[u].begin(); it != edges[u].end(); it++)
			{

				if (!used_set[it->first] && dist[u] != INT_MAX
					&& dist[u] + it->second < dist[it->first])
					dist[it->first] = dist[u] + it->second;
			}
	}

	return dist;
}

int Graph::find_shortest_cycle(vector<int>& dist, int s)
{
	dist[s] = INT_MAX;
	for (int v = 0; v < num_of_vertexes; v++)
	{
		if (v != s)
		{
			list<pair<int, int>>::iterator it;
			for (it = edges[v].begin(); it != edges[v].end(); it++)
			{
				if (it->first == s) {
					if (dist[v] != INT_MAX
						&& dist[v] + it->second < dist[it->first])
						dist[it->first] = dist[v] + it->second;
					break;
				}
				
			}
		}
	}
	return dist[s];

}

int Graph::number_of_trips_distance(int s, int d, int bound)
{

	int count = 0;

	int weight = 0;
	int distance = 0;

	number_of_trips_distance(s, d, weight,distance, count, bound);

	return count;

}


void Graph::number_of_trips_distance(int u, int d, int weight,int& distance, int& count, int bound)
{
	
	distance = distance + weight;
	if (distance >= bound)
	{
		distance = distance - weight;
		return;
	}

	list<pair<int, int>>::iterator it;

	if (u == d)
	{
		if (distance > 0) {
			count++;
		}
	}

	for (it = edges[u].begin(); it != edges[u].end(); ++it) {

		number_of_trips_distance(it->first, d, it->second,distance, count, bound);

	}

	distance = distance - weight;

}


int main()
{
	//Start testing

	Test* t = new Test();

	t->print_distance( 1);
	t->print_distance( 2);
	t->print_distance( 3);
	t->print_distance( 4);
	t->print_distance( 5);

	t->print_number_of_trips(2, 2, 3, false, 6);
	t->print_number_of_trips(0,2,4,true, 7);

	t->print_minimal_distance(0, 2,  8);
	t->print_minimal_distance(1, 1,  9);

	t->print_number_of_trips_by_distance(2, 2, 30, 10);
	delete t;

	return 0;
}