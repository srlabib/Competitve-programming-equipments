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


class SegmentTree{
    vector<int>values;
    vector<pair<int,bool>>lazy;// {value,1 if set 0 if update}

    int n;
    //function to combine two segment
    int merge(int a, int b){
        return a+b;
    }

    void build(vector<int> &a,int at, int b, int e){
        if(b == e){
            values[at] = a[b];
            return;
        }

        int mid = (b+e)>>1;
        build(a,at*2,b,mid);
        build(a,at*2+1,mid+1,e);
        values[at] = merge(values[at*2],values[at*2+1]);
    }

    // pushing pending updates to children. lazy propation
    void push(int at,int b, int e){
        if(lazy[at].first == 0)return;             // no pending update
        if(lazy[at].second == 1){
            values[at] = lazy[at].first*(e-b+1);
        }
        else {
            values[at] += lazy[at].first*(e-b+1);     //  for sum query
        }
        if(b != e){                   // propagating the update to the child when not on the leaf
            if(lazy[at].second == 1){   // if the type is set
                lazy[at*2] = lazy[at];
                lazy[at*2+1] = lazy[at];
            }        
            else{                   // if the type is update
                lazy[at*2].first += lazy[at].first;
                lazy[at*2+1].first += lazy[at].first;
            }                
        }
        lazy[at] = {0,0};           // clearing the pending update after propagating to child
    }

    void update(int at,int b, int e, int l, int r,int v){
        push(at,b,e);       // updating the sum at the node and propagating pending update to the children

        if (r < b || e < l) return;
        if (l <= b && e <= r) {
            lazy[at].first += v;
            push(at,b,e);
            return;
        }
        int mid = (b+e)>>1;
        update(at*2,b,mid,l,r,v);
        update(at*2+1,mid+1,e,l,r,v);
        values[at] = merge(values[at*2],values[at*2+1]);
    }

    void set(int at,int b, int e, int l, int r,int v){
        push(at,b,e);       // updating the sum at the node and propagating pending update to the children
        if (r < b || e < l) return;
        if (l <= b && e <= r) {
            lazy[at] = {v,1};
            push(at,b,e);
            return;
        }
        int mid = (b+e)>>1;
        set(at*2,b,mid,l,r,v);
        set(at*2+1,mid+1,e,l,r,v);
        values[at] = merge(values[at*2],values[at*2+1]);
    }
    //query(1,0,n-1,l,r)  *** (l,r are 0 indedxed)
    int query(int at, int b, int e, int l, int r) {
        push(at,b,e);           // updating the sum at the node and propagating pending update to the children
        if (b > r || e < l) {
            return 0; 
        }
        if (l <= b && e <= r) {
            return values[at];
        }

        int mid = (b + e) >> 1;
        int left = query(at * 2, b, mid, l, r);
        int right = query(at * 2 + 1, mid + 1, e, l, r);
        return merge(left, right);
    }

    public:
    SegmentTree(vector<int>&a){
        n = a.size();
        values.resize(n*4);
        lazy.resize(n*4);
        build(a,1,0,n-1);

    }
    int query(int l,int r){
        return query(1,0,n-1,l,r);
    }
    void update(int l,int r, int v){
        update(1,0,n-1,l,r,v);
    }
    void set(int l,int r,int v){
        set(1,0,n-1,l,r,v);
    }
};

void solve(){
    int n,m;
    cin>>n>>m;
    vi a(n+1);
    FOR(i,0,n)cin>>a[i];
    SegmentTree st(a);

    while(m--){
        int t;
        cin>>t;
        if(t == 1){
            int l,r,v;
            cin>>l>>r>>v;
            st.update(l-1,r-1,v);
        }
        else if(t == 2){
            int l,r,v;
            cin>>l>>r>>v;
            st.set(l-1,r-1,v);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout << st.query(l-1,r-1) << endl;
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
