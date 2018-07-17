#include <iostream>
#include "test.h"
Test::Test() {
	g = create_test_graph();
};

Test::~Test() {
	delete g;
};

Graph* Test::create_test_graph()
{
	Graph* g = new Graph(5);
	g->addEdge(0, 1, 5);
	g->addEdge(1, 2, 4);
	g->addEdge(2, 3, 8);
	g->addEdge(3, 2, 8);
	g->addEdge(3, 4, 6);
	g->addEdge(0, 3, 5);
	g->addEdge(2, 4, 2);
	g->addEdge(4, 1, 3);
	g->addEdge(0, 4, 7);

	return g;
}

vector<int>  Test::create_test_route1()
{
	vector<int> route(3);
	route[0] = 0;
	route[1] = 1;
	route[2] = 2;

	return route;
}

vector<int>  Test::create_test_route2()
{
	vector<int> route(2);
	route[0] = 0;
	route[1] = 3;

	return route;
}
vector<int>  Test::create_test_route3()
{
	vector<int> route(3);
	route[0] = 0;
	route[1] = 3;
	route[2] = 2;


	return route;
}

vector<int>  Test::create_test_route4()
{
	vector<int> route(5);
	route[0] = 0;
	route[1] = 4;
	route[2] = 1;
	route[3] = 2;
	route[4] = 3;


	return route;
}

vector<int>  Test::create_test_route5()
{
	vector<int> route(3);
	route[0] = 0;
	route[1] = 4;
	route[2] = 3;

	return route;
}

void Test::print_distance(int n)
{
	vector<int> route;
	switch (n) {
	case 1:
		route = create_test_route1();
		break;
	case 2:
		route = create_test_route2();
		break;
	case 3:
		route = create_test_route3();
		break;
	case 4:
		route = create_test_route4();
		break;
	case 5:
		route = create_test_route5();
		break;
	}
	int distance = g->find_distance(route);
	if (distance >= 0)
		cout << "Output #" << n << ": " << g->find_distance(route) << endl;
	else
		cout << "Output #" << n << ": " "NO SUCH ROUTE\n";
}

void Test::print_number_of_trips(int s,int d, int bound, bool exact, int n)
{
	std::cout << "Output #" << n << ": " << g->number_of_trips(s, d, bound, exact) << std::endl;
}

void Test::print_minimal_distance(int s, int d,  int n)
{
	if (s != d) {
		vector<int> dist = g->find_all_minimal_distances(s);
		std::cout << "Output #" << n << ": " << dist[d] << std::endl;
	}
	else {
		vector<int> dist2 = g->find_all_minimal_distances(s);
		std::cout << "Output #" << n << ": " << g->find_shortest_cycle(dist2, d) << std::endl;
	}
}

void Test::print_number_of_trips_by_distance(int s, int d, int bound, int n)
{
	std::cout << "Output #" << n << ": " << g->number_of_trips_distance(s, d, bound) << std::endl;
}