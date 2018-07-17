#pragma once
#include<vector>
#include<list>

using namespace std;

class Graph
{
	int num_of_vertexes;

	list<pair<int, int>>* edges;

	void number_of_trips(int, int, vector<int>&, int &, int&, int, bool);

	int minDistance(vector<int> dist, vector<bool> used_set, int s);

	void number_of_trips_distance(int u, int d, int weight, int& distance, int& count, int bound);

public:

	Graph(int num_of_vertexes);
	//add edge (v,w) to the graph with weight
	void addEdge(int v, int w, int weight);

	// find distance of a route
	int find_distance(vector<int>& route);

	//find number of trips between s and d bounded by given length (bound)
	int number_of_trips(int s, int d, int bound, bool exact);

	//Dijkstra algorith for minimal paths
	vector<int> find_all_minimal_distances(int s);

	//if needs to find a minimal distance for circle to find_all_minimal_distances add find_shortest_cycle
	int find_shortest_cycle(vector<int>& dist, int s);

	//Number of trips by distance bounded by given distance
	int number_of_trips_distance(int s, int d, int bound);
};