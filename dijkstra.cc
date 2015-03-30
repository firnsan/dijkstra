#include <iostream>
#include <vector>


#include "my_heap.h"
#include "my_graph.h"


vector<int> d;
vector<int> pi;

int compare(int lhs, int rhs) {
	return d[lhs] <= d[rhs];
}

void initSource(vector<int> &d, vector<int> &pi, int num, int start) {
	for (int i=0; i<num; i++) {
		d[i] = INFNITY;
		pi[i] = -1;
	}

	d[start] = 0;
}

void relax(vector<int> &d, vector<int> &pi, int head, int tail, int weight) {
	if (d[tail] > d[head]+weight) {
		d[tail] = d[head]+weight;
		pi[tail] = head; 
	}
}

void dijkstra(MyGraph &G, int start) {
	int num = G.size();
	d = vector<int>(num);
	pi = vector<int>(num);
	
	initSource(d, pi, num, start);
	
	//用heap储存vex序号
	MyHeap Q(compare);
	for (int i=0; i<num; i++) {
		Q.push(i);
	}

	int u,v;
	ArcNode *arc;
	
	while(Q.size()) {
		Q.build();
		u = Q.pop();
		cout << u << endl;
		while (arc=G.getAdj(u)) {
			relax(d, pi, u, arc->vex, arc->weight);
		}
	}

	for (int i=0; i<num; i++) {
		cout << "vex" << start << " to vex" << i << " legth: " << d[i] <<endl;
		int parent = pi[i];
		cout << i;
		while (parent>-1) {
			cout <<  "<---" << parent;
			if (parent==start)
				break;
			parent = pi[parent];
		}
		cout << endl;
	}
}

int main(int argc, char *argv[])
{
	MyGraph graph(10);
    
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

	dijkstra(graph, 0);

	
    return 0;
}


