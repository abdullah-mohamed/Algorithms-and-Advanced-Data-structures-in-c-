#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
 * Must clear heap if you are willing to use it again after removing all the elements
 */
class MinHeap{
private:
	vector<int> heap;
	int size;				//	n when heap contains n elements

	void makeHeap(vector<int> &v){
		for(int i = 0; i < (int)v.size(); i++) this->insertElement(v[i]);
	}
	
	void adjustElementUpUtil(int ind){
		if(this->size == 1) return;

		int par = floor(ind-1)/2;
		if(this->heap[ind] < this->heap[par]){
			int tmp = this->heap[ind];
			this->heap[ind] = this->heap[par];
			this->heap[par] = tmp;
			this->adjustElementUpUtil(par);
		}
	}
	
	void adjustElementDownUtil(int ind){
		if(2 * ind + 1 >= this->size) return;
		
	int firChild = this->heap[2 * ind + 1], secChild, maxChild;
		// one child only
		if(this->size == 2 *ind + 2){
			int tmp = this->heap[ind];
			this->heap[ind] = this->heap[2 * ind + 1];
			this->heap[2 * ind + 1] = tmp;
			return;
		}
		
		// 2 children
		secChild = this->heap[2 * ind + 2];
		if(firChild < secChild){
			// firstChild goes up
			int tmp = this->heap[ind];
			this->heap[ind] = this->heap[2 * ind + 1];
			this->heap[2 * ind + 1] = tmp;
			adjustElementDownUtil(2 * ind + 1);
		}else{
			// secondChild goes up
			int tmp = this->heap[ind];
			this->heap[ind] = this->heap[2 * ind + 2];
			this->heap[2 * ind + 2] = tmp;
			adjustElementDownUtil(2 * ind + 2);
		}
		
		/*if(firChild < secChild) maxChild = 2 * ind + 1;
		else maxChild = 2 * ind + 2;
		int tmp = this->heap[ind];
		this->heap[ind] = this->heap[maxChild];
		this->heap[maxChild] = tmp;
		adjustElementDownUtil(maxChild);*/
	}
public:
	MinHeap(vector<int> &v){
		this->size = 0;
		this->makeHeap(v);
	}
	
	MinHeap(){
		this->heap.clear();
		this->size = 0;
	}

	void insertElement(int el){
		this->heap.push_back(el);
		this->size++;
		this->adjustElementUpUtil(this->size-1);
	}
	
	void printHeap(){
		for(int i = 0 ; i < this->size; i++)
			cout << heap[i] << " ";
		cout << "\n";
	}

	void deleteElement(){
		if(this->size == 0) return ;		// This should throw an error instead to support neg numbers
		
		this->heap[0] = this->heap[this->size-1];
		this->heap.pop_back();
		this->size--;
		adjustElementDownUtil(0);
	}
	
	int getMin(){
		return this->heap[0];
	}
};

void heapify(vector<int> &v, vector<int> &minHeap){
		
}

int main(){
	vector<int> v{9, 10, 20, 6, 5, 8};
	MinHeap *obj = new MinHeap(v);
	obj->printHeap();
	cout << "\n" << obj->getMin() << "\n";
	obj->deleteElement();
	cout << "\n" << obj->getMin() << "\n";
	obj->printHeap();
	return 0;
}
