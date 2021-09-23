#include<bits/stdc++.h>
using namespace std;

vector<int> position = {0};

void move(int tower, int destination)
{
    if(tower==0)return;
    move(tower-1,6-position[tower]-destination);
    cout<<"Move "<<tower<<" to position "<<destination<<endl; //printing moves
    position[tower] = destination;//moved
    move(tower-1,destination);
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i<n;i++){
        position.push_back(1);
    }
    move(n,3);
    cout<<"Done!;-)"<<endl;
}