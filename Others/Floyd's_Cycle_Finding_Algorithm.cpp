#/****Bismillahir rahmanir rahim****/

#include<bits/stdc++.h>

using namespace std;

typedef long long            ll;
typedef long double          ld;
typedef vector<int>          vi;
typedef vector<long long>    vl;
typedef vector<double>       vd;

#define All(a) a.begin(),a.end()

template <typename T>
void get_vector(T &a)
{
    for(auto &e: a) cin >> e;
}

template <typename T>
void put_vector(T a)
{
    for(auto e :a)cout << e << " ";
    cout << endl;
}
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
