#ifndef MY_HEAP_H
#define MY_HEAP_H

#include <vector>

using namespace std;

/**
如果设计的数据结构是
struct Node {
	int v;
	int dv;
};
然后用vector<Node> 保存heap，那么dijkstra无法根据v，修改dv.
需要在dijkstra内部用数组保存dv,数组的索引就是v;
而heap中用vector<int>保存v。比较的时候，使用dijkstra提供的比较操作。
 **/


typedef int (*compareFn_t)(int lhs, int rhs);

int defaultCompareFn(int lhs, int rhs) {
	return lhs<=rhs;
}

class MyHeap {
public:
	MyHeap(compareFn_t comp = defaultCompareFn);

	void build(); //建立堆 
	void push(int); //不会自动调整
	int pop(); //不会自动调整
	int size();
	
private:
	void sift(int k, int n);
	
	vector<int> vec_;
	compareFn_t comp_;
	int num_;
};

MyHeap::MyHeap(compareFn_t comp)
:comp_(comp), num_(0) {
	vec_.push_back(0); //第一个位置不存元素
}

void MyHeap::build() {
	for (int i=num_/2; i>0; i--)
		sift(i, num_);
}

void MyHeap::push(int v) {
	vec_.push_back(v);
	num_++;
}

int MyHeap::pop() {
	int ret = vec_[1];
	vec_[1] = vec_[num_--];
	return ret;
}

int MyHeap::size() {
	return num_;
}

void MyHeap::sift(int k, int n) {
	int i = k;
	int temp = vec_[i];
	int j = 2*i;
	
	while (j <= n) {
		if (j<n && comp_(vec_[j+1], vec_[j])) //找较小的一个
			j++;
		if (comp_(temp, vec_[j]))
			break;
		vec_[i] = vec_[j];
		i = j;
		j = 2*i;
	}
	vec_[i] = temp;
}
#endif