#include<bits/stdc++.h>


using namespace std; 
#define int long long
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;


#define All(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i=a;i<b;i++)
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}

const int mod = 1000000007;

struct Matrix{
    vvi a;
    Matrix(vvi aa):a(aa){}

    Matrix operator*(const Matrix& other)const{
        assert(a[0].size() == other.a.size());
        vvi c(a.size(),vi(other.a[0].size()));
        for(int i = 0; i<c.size(); i++){
            for(int j = 0; j<c[0].size(); j++){
                for(int k = 0; k<a[0].size(); k++)
                c[i][j] = (c[i][j]+a[i][k]*other.a[k][j])%mod;
            }
        }
        return Matrix(c);
        
    }

};


signed main()
{
    vvi a = {
        {2,3,4},
        {1,2,3}
    };
    vvi b = {
        {1,1},
        {2,2},
        {3,3}
    };

    Matrix c = Matrix(a)*Matrix(b);

    /*
    Matrix A(a);
    Matrix B(b);

    Matrix c = A*B;
    */

    for(auto x:c.a){
        put_vector(x);
    }
    return 0;
}
