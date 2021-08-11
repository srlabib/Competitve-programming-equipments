#include<bits/stdc++.h>

using namespace std;

bool is_heap(vector<int>H,int heap_size)
{
	for(int i=heap_size; i>1;i--){
		if(H[i]>H[i/2])return 0;
	}
	return 1;
}

void max_heapify(vector<int> &H,int heap_size,int i){
	int l = i*2, r = i*2+1, max = i;
	if(l<=heap_size && H[l]>H[max]) max = l;
	if(r<=heap_size && H[r]>H[max]) max = r;
	if(max != i){
		swap(H[max],H[i]);
		max_heapify(H,heap_size,max);
	}
}

void build_max_heap(vector<int> &H, int heap_size)
{
	for(int i = heap_size/2; i>0;i--){
		max_heapify(H,heap_size,i);
	}
}

void heap_sort(vector<int>&H,int heap_size){
	int i;
	build_max_heap(H,heap_size);
	for(int i = heap_size; i>1; i--){
		swap(H[i],H[1]);
		heap_size--;
		max_heapify(H,heap_size,1);
	}
}

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		vector<int>a(n+1);
		for(int i=1;i<=n;i++)cin>>a[i];
		heap_sort(a,n);
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}cout<<endl;
	}
}
