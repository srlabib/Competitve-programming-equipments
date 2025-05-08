#include<bits/stdc++.h>

using namespace std; 

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key

#define int long long
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define resetbit(x,n) (x=(x&(~(1LL<<n))))

#define All(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i=a;i<b;i++)
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}

const int inf = INT_MAX;
const int INF = 1e18;

vi values;
int getKey(int v){
    return lower_bound(All(values),v)-values.begin();
}

const int N = 1e6 + 9, B = 440;

struct query {
    int l, r, id;
    bool operator < (const query &x) const {
        if(l / B == x.l / B) return ((l / B) & 1) ? r > x.r : r < x.r;
        return l / B < x.l / B;
    }
}Q[N];

int a[N];
int cnt[N];
long long sum = 0;

// adding and removing element from segment
inline void add_left(int i) { 
    cnt[a[i]]++;
    if(cnt[a[i]] == 1)sum++;
}
inline void add_right(int i) {
    cnt[a[i]]++;
    if(cnt[a[i]] == 1)sum++;
}
inline void rem_left(int i) {
    cnt[a[i]]--;
    if(cnt[a[i]] == 0)sum--;
}
inline void rem_right(int i) {
    cnt[a[i]]--;
    if(cnt[a[i]] == 0)sum--;
}
long long ans[N];



void solve(){
    int n,q;
    cin>>n>>q;  
    values.resize(n);
    FOR(i,1,n+1){
        cin>>a[i];
        values[i-1] = a[i];
    }
    sort(All(values));
    values.erase(unique(All(values)),values.end());
    for(int i = 1; i<=n; i++)a[i] = getKey(a[i]);
    vector<query>queries(q);
    
    FOR(i,1,q+1){
        int x,y;
        cin>>x>>y;
        Q[i].l = x;
        Q[i].r = y;
        Q[i].id = i;
    }

    sort(Q+1,Q+q+1);
    int l = 1,r = 0;

    for(int i = 1; i <= q; i++) {
        int L = Q[i].l, R = Q[i].r;
        if(R < l) {
            while (l > L) add_left(--l);
            while (l < L) rem_left(l++);
            while (r < R) add_right(++r);
            while (r > R) rem_right(r--);
        } else {
            while (r < R) add_right(++r);
            while (r > R) rem_right(r--);
            while (l > L) add_left(--l);
            while (l < L) rem_left(l++);
        }
        ans[Q[i].id] = sum;
    }

    FOR(i,1,q+1)cout << ans[i] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T = 1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
