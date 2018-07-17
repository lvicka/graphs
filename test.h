
#include "main.h"

class Test {
	Graph* g;
public:

	Test();
	~Test();

	Graph* create_test_graph();
	void print_distance( int n);
	void print_number_of_trips(int s, int d, int bound, bool exact, int n);
	void print_minimal_distance(int s, int d, int n);
	void print_number_of_trips_by_distance(int s, int d, int bound, int n);

private:
	vector<int>  create_test_route1();
	vector<int>  create_test_route2();
	vector<int>  create_test_route3();
	vector<int>  create_test_route4();
	vector<int>  create_test_route5();
};

