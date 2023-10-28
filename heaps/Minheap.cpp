#include <iostream>
#include <vector>
using namespace std;

class Minheap
{
	void heapify(int idx){
        int left = 2*idx;
        int right = (2*idx) +1;

        int min = idx;

        if(left < v.size() && v[left] < v[min]){
            min = idx;
        }
         if(right < v.size() && v[right] < v[min]){
            right = idx;
        }

        if(min != idx){
            swap(v[min],v[idx]);
            heapify(min);
        }
    }
public:
	vector<int> v;
    Minheap() {
		v.push_back(-1); // 0th index par kch random value daal do
		// taaki uspr data na jaaye koi bhi
	}

	void push(int data){
        v.push_back(data);
        int idx = v.size()-1;
        inr parent = idx/2;

        while(parent > 0 && v[parent] > v[idx]){
            swap(v[parent],v[idx]);
            idx = parent;
            parent = idx/2;
        }

    }

    int top(){
        return v[1];
    }

    void pop(){
        swap(v[1],v[v.size()-1]);
        v.pop_back();
        heapify(1);
    }

    bool empty(){
        return v.size() == 1;
    }
    
    
    };

int main() {

	Minheap h;

	h.push(9);
	h.push(2);
	h.push(1);
	h.push(0);
	h.push(3);
	h.push(5);

	while (!h.empty()) {
		cout << h.top() << " ";
		h.pop();
	}

	cout << endl;

	return 0;
}