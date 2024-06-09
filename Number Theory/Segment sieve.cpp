#include<bits/stdc++.h>
 
 using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
#define All(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i=a;i<b;i++)
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}
const int MAX = 46500; //max value is the squar root of the maxumum value of b
bool isprime[MAX+5];
vi primes;


void sieve(){ // getting all the primes up to sqrt(b)
    for(int i = 3; i<MAX; i+=2)isprime[i] = 1;
    isprime[2] = 1;
    primes.push_back(2);
    for(ll i = 3; i<MAX; i+=2){
        if(isprime[i])primes.push_back(i);
        if(i*i>MAX)continue;
        for(ll j = i*i; j<MAX; j+=i)isprime[j] = 0;
    }
}
void solve()
{
    ll a,b;
    static int cs = 0;
    cin>>a>>b;

    vector<bool>P(b-a+5);
    for(ll i = a+(a%2==0); i<=b; i+=2)P[i-a] = 1;
    if(2-a>=0)P[2-a] = 1; //if 2 is in the range setting 2 as prime
    if(1-a>=0)P[1-a] = 0;  //if 1 is in the range setting 1 as not prime 
    for(ll e: primes){
        if(e>b)break;
        ll x;
        if(e>=a)x = e+e; // if prime is in the range, we should not mark it as not prime in the loop
        else if(a%e==0)x = a;
        else x = (a/e+1)*e; 
        for(ll i = x; i<=b; i+=e){
            P[i-a]=0;
        }
    }
    int res = 0;

    for(ll i = a; i<=b; i++)res+=P[i-a];
    cout << "Case "<<++cs<<": "<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();


    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}
