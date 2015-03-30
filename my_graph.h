#ifndef MY_GRAPH_H
#define MY_GRAPH_H

#include <iostream>
#include <vector>
using namespace std;

#define INFNITY 10000

struct ArcNode {
	int vex;
	ArcNode *nextarc;
	int weight; //权重
};


struct VexNode {
	ArcNode *firstarc;
};


class MyGraph {
public:
	MyGraph(int vexnum=5);
	void addArc(int head, int tail, int weight); //增加弧
	int getWeight(int head, int tail); //获取权重
	void displayGraph(); //打印各个节点的弧
	int size();
	ArcNode *getAdj(int head); //获取head的弧，自动递增
	
private:
	vector<VexNode> vexs_;
	int vexnum_;
	int arcnum_;
};

MyGraph::MyGraph(int vexnum)
:vexnum_(vexnum), arcnum_(0) {
	vexs_ = vector<VexNode>(vexnum);
	for (int i=0; i<vexnum; i++)
		vexs_[i].firstarc = nullptr;
}

void MyGraph::addArc(int head, int tail, int weight) {
	ArcNode *new_arc = new ArcNode;
	new_arc->nextarc = nullptr;
	new_arc->vex = tail;
	new_arc->weight = weight;

	ArcNode *last_arc = vexs_[head].firstarc;
	if (!last_arc) {
		vexs_[head].firstarc = new_arc;
	} else {
		while(last_arc->nextarc) {
			last_arc = last_arc->nextarc;
		}
		last_arc->nextarc = new_arc;
	}
	arcnum_++;
}
int MyGraph::getWeight(int head, int tail) {
	int ret = -INFNITY;
	ArcNode *arc = vexs_[head].firstarc;
	while (arc) {
		if (arc->vex == tail) {
			ret = arc->weight;
			break;
		}
		arc = arc->nextarc;
	}
	return ret;
		
}

void MyGraph::displayGraph() {
	for (int i=0; i<vexnum_; i++) {
		ArcNode *arc = vexs_[i].firstarc;
		cout << "head: " << i << endl;
		while (arc) {
			cout << "tail: " << arc->vex << "  weigth: " << arc->weight << endl;
			arc = arc->nextarc;
		}
	}
		
}

int MyGraph::size() {
	return vexnum_;
}

ArcNode *MyGraph::getAdj(int head) {
	static int last_head = -1;
	static ArcNode *last_arc = nullptr;
	if (head != last_head || !last_arc) {
		last_arc = vexs_[head].firstarc;
		last_head = head;
		return last_arc;
	}
	return last_arc = last_arc->nextarc;
}
#endif