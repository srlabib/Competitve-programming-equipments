#include<bits/stdc++.h>

using namespace std;

class PriorityQueue{
	private:
		int current_size=0;
		vector<long long> heap;
		void max_heapify(vector<long long> &H,int heap_size,int i){
			int l = i*2, r = i*2+1, max = i;
			if(l<=heap_size && H[l]>H[max]) max = l;
			if(r<=heap_size && H[r]>H[max]) max = r;
			if(max != i){
				swap(H[max],H[i]);
				max_heapify(H,heap_size,max);
			}
		}

	public:
		PriorityQueue(int max_size){
			heap.resize(max_size+1);
		}
		long long get_maximum(){
			if(current_size<1)return -0;
			return heap[1];
		}
		long long pop(){
			if(current_size<1)return -0;
			int max_item = heap[1];
			heap[1] = heap[current_size];
			current_size--;
			max_heapify(heap,current_size,1);
			return max_item;
		}

		void insert(long long node){
			int i  = current_size, p, t;

			i++;
			heap[i] = node;
			current_size++;

			while(i>1 && heap[i]>heap[i/2]){
				swap(heap[i],heap[i/2]);
				i/=2;
			}
		}
};

const int max_size = 1e5;

int main()
{
	PriorityQueue pq(max_size);
	while (1)	
	{
		char command; cin>>command;
		if(command == 'g'){
			long long x = pq.get_maximum();
			cout<<"The maximum element is : "<<x<<endl;
		}
		else if(command == 'p'){
			long long x = pq.pop();
			cout<<"The maximum element "<<x<<" is removed!\n";
		}
		else if(command == 'i'){
			long long x;
			cin>>x;
			pq.insert(x);
		}
		else 
			break;		
	}
	
}
