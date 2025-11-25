#include<bits/stdc++.h>

using namespace std; 

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define resetbit(x,n) (x=(x&(~(1LL<<n))))

#define All(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i=a;i<b;i++)
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}

const int inf = INT_MAX;
const int INF = 1e18;

// modify as needed
struct item{
    int x;
};
item NUTRAL_ITEM = {0};// merge(a , NUTRAL_ITEM) = a
item merge(item a, item b){
    return {a.x+b.x};
}
item single(int v){
    return {v};
}


const int N = 2e5+5;
struct node{
    item v;
    int left;
    int right;
}t[N*22];  // size = Q⋅log2​(N)+N

class PersistentSegmentTree{
    vector<int>roots;
    int n;
    int id = 0;
    int newParent(int l, int r){ 
        int p = ++id;
        t[p].left = l;
        t[p].right = r;
        t[p].v = merge(t[l].v,t[r].v);  
        return p;
    }
    int newNode(int v){
        int p = ++id;
        t[p].left = t[p].right = 0; //null
        t[p].v = single(v);
        return p;
    }
    int build(vector<int> &a,int b, int e){
        if(b == e) return newNode(a[b]);
        int mid = (b+e)>>1;
        return newParent(build(a,b,mid),build(a,mid+1,e));
    }
    int update(int at,int b, int e, int i,int v){
        if (b == e && b == i) return newNode(v);
        int mid = (b+e)>>1;
        if(i<=mid)return newParent(update(t[at].left,b,mid,i,v),t[at].right);
        else return newParent(t[at].left,update(t[at].right,mid+1,e,i,v));
    }
    item query(int at, int b, int e, int l, int r) {
        if (at == 0 || b > r || e < l)  return NUTRAL_ITEM; 
        if (l <= b && e <= r)  return t[at].v;
        int mid = (b + e) >> 1;
        item left = query(t[at].left, b, mid, l, r);
        item right = query(t[at].right, mid + 1, e, l, r);
        return merge(left, right);
    }

    public:
    PersistentSegmentTree(vector<int>&a){
        n = a.size();
        roots.push_back(build(a,0,n-1));
    }
    item query(int version,int l,int r){
        return query(roots[version],0,n-1,l,r);
    }
    int update(int version,int i, int v){           // return the version (index of the new root) 
        int newRoot = update(roots[version],0,n-1,i,v);
        roots.push_back(newRoot);
        return roots.size()-1;  // new version
    }
};
// initial verison = 0

void solve(){
    int n,q;
    cin>>n>>q;
    vi a(n);
    get_vector(a);
    PersistentSegmentTree pst(a);
    vi arrs = {0};
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int k,a,x;
            cin>>k>>a>>x;
            k--;a--;
            arrs[k] = pst.update(arrs[k],a,x);
        }else if(t==2){
            int k,a,b;
            cin>>k>>a>>b;
            k--;a--;b--;
            cout << pst.query(arrs[k],a,b).x << endl;
        }else{
            int k;
            cin>>k;
            k--;
            arrs.push_back(arrs[k]);
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
