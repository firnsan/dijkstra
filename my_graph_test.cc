#include <iostream>


#include "my_graph.h"

using namespace std;

int main(int argc, char *argv[])
{
    MyGraph graph;

	cout << graph.size() << endl;

	graph.addArc(0, 1, 10);
	graph.addArc(0, 3, 5);
	graph.addArc(1, 2, 1);
	graph.addArc(1, 3, 2);
	graph.addArc(2, 4, 4);
	graph.addArc(3, 1, 3);
	graph.addArc(3, 2, 9);
	graph.addArc(3, 4, 2);
	graph.addArc(4, 2, 4);
	graph.addArc(4, 0, 7);

	graph.displayGraph();

	cout << "weight of (3,2) is : " << graph.getWeight(3, 2) << "  except:9" << endl;
	
    return 0;
}

