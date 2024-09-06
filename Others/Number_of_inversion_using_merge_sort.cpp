#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
#define All(a) a.begin(),a.end()

const int mod  = 1e9+7;

ll merge_sort(int l, int r, vl &a){

    if(l >= r)return 0;
    int m = (l+r)/2;
    ll res = 0;
    res+=merge_sort(l,m,a);
    res+=merge_sort(m+1,r,a);
    int sz = (r-l+1);
    vl temp(sz);
    int i = l,j = m+1,x = 0;
    

    while(i<=m && j<=r){
        if(a[i]>a[j]){
            res+=(m-i+1);
            temp[x++] = a[j];
            j++;
        }else{
            temp[x++] = a[i];
            i++;
        }
    }
    while(i<=m){
        temp[x++] = a[i];
        i++;
    }
    while(j<=r){
        temp[x++] = a[j];
        j++;
    }
    for(int i = l; i<=r; i++)a[i] = temp[i-l];
    return res;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vl a(n);
        for(auto &e:a)cin>>e;
        cout << merge_sort(0,n-1,a) << endl;

    }
}
