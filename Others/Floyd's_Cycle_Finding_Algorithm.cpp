#include<bits/stdc++.h>

using namespace std;

const int mod = 11;

//a function that generates a repeated series
int f(int n){
    return (3*n*n+7*n+5)%97;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int begin = 62;
    int hare = begin,tortoise= begin;
    hare  = f(f(hare));
    tortoise = f(tortoise);
    while(hare!=tortoise){
        hare=f(f(hare));
        tortoise=f(tortoise);
    }
    int period = 1;
    tortoise = f(begin);
    while(tortoise!=hare){
        tortoise = f(tortoise);
        period++;
    }
    hare = begin;
    int start = 0;
    while(hare!=tortoise){
        hare = f(hare);
        tortoise = f(tortoise);
        start++;
    }
    cout<<start<<" "<<period<<endl;
    

    return 0;
}
