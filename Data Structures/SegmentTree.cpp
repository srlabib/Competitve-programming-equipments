#include<bits/stdc++.h>

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key

using namespace std; 
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

struct SegmentTree{
    struct item{
        int x;
    };

    item NUTRAL_ITEM = {0};// merge(a , NUTRAL_ITEM) = a
    vector<item>values;

    SegmentTree(vector<int>&a){
        int n = a.size();
        values.resize(n*4);
        build(a,1,0,n-1);
    }

    item merge(item a, item b){
        return {a.x+b.x};
    }

    item single(int v){
        return {v};
    }

    void build(vector<int> &a,int at, int b, int e){
        if(b == e){
            values[at] = single(a[b]);
            return;
        }

        int mid = (b+e)>>1;
        build(a,at*2,b,mid);
        build(a,at*2+1,mid+1,e);
        values[at] = merge(values[at*2],values[at*2+1]);
    }
    //update(1,0,n-1,i,v)
    void update(int at,int b, int e, int i,int v){
        if (b > i || e < i) return;
        if (b == e && b == i) {
            values[at] = single(v);
            return;
        }

        int mid = (b+e)>>1;
        update(at*2,b,mid,i,v);
        update(at*2+1,mid+1,e,i,v);
        values[at] = merge(values[at*2],values[at*2+1]);
    }
    //query(1,0,n-1,l,r)  *** (l,r are 0 indedxed)
    item query(int at, int b, int e, int l, int r) {
        if (b > r || e < l) {
            return NUTRAL_ITEM; 
        }
        if (l <= b && e <= r) {
            return values[at];
        }

        int mid = (b + e) >> 1;
        item left = query(at * 2, b, mid, l, r);
        item right = query(at * 2 + 1, mid + 1, e, l, r);
        return merge(left, right);
    }
    
    
};


void solve(){
    int n,m;
    cin>>n>>m;
    vi a(n);
    get_vector(a);
    SegmentTree st(a);
    FOR(i,0,m){
        int t;
        cin>>t;
        if(t == 1){
            int i,v;
            cin>>i>>v;
            st.update(1,0,n-1,i,v);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout << st.query(1,0,n-1,l,r-1).x << endl;
        }
    }
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
