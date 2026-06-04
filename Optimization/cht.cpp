#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

struct CHT {
  vector<ll> m, b;
  int ptr = 0;

  bool bad(int l1, int l2, int l3) {
    /* * HOW TO CHOOSE THE INEQUALITY FOR 'bad()':
     * The condition determines when the middle line (l2) becomes useless and should be removed.
     */
     
    // OPTION 1: Use `<=` 
    // -> Use when: (Slopes DECREASING & Querying MINIMUM)
    // -> Use when: (Slopes INCREASING & Querying MAXIMUM)
    return 1.0 * (b[l3] - b[l1]) * (m[l1] - m[l2])  <= 1.0 * (b[l2] - b[l1]) * (m[l1] - m[l3]); 

    // OPTION 2: Use `>` 
    // -> Use when: (Slopes DECREASING & Querying MAXIMUM)
    // -> Use when: (Slopes INCREASING & Querying MINIMUM)
    // return 1.0 * (b[l3] - b[l1]) * (m[l1] - m[l2])  > 1.0 * (b[l2] - b[l1]) * (m[l1] - m[l3]); 
  }

  void add(ll _m, ll _b) {
    m.push_back(_m);
    b.push_back(_b);
    int s = m.size();
    while(s >= 3 && bad(s - 3, s - 2, s - 1)) {
      s--;
      m.erase(m.end() - 2);
      b.erase(b.end() - 2);
    }
  }

  ll f(int i, ll x) {
    return m[i] * x + b[i];
  }

  /*
   * O(1) AMORTIZED QUERY (Pointer Method)
   * WARNING: Only use this if your query values `x` are strictly INCREASING.
   * If your `x` queries are random/not sorted, use the `bs()` function below instead.
   */
  ll query(ll x) {
    if(ptr >= m.size()) ptr = m.size() - 1;
    
    // OPTION 1: For MINIMUM queries (Use `<`)
    // Move pointer forward if the next line yields a SMALLER value
    while(ptr < m.size() - 1 && f(ptr + 1, x) < f(ptr, x)) ptr++;
    
    // OPTION 2: For MAXIMUM queries (Use `>`)
    // Move pointer forward if the next line yields a LARGER value
    // while(ptr < m.size() - 1 && f(ptr + 1, x) > f(ptr, x)) ptr++;
    
    return f(ptr, x);
  }

  /*
   * O(log N) BINARY SEARCH QUERY
   * Use this when your `x` queries are NOT sorted (random order).
   * Call bs(0.cht.m.size()-1,x)
   */

  ll bs(int l, int r, ll x) {
    int mid = (l + r) / 2;
    
    // OPTION 1: For MINIMUM queries (Use `<`)
    // Search the side that yields a SMALLER value
    if(mid + 1 < m.size() && f(mid + 1, x) < f(mid, x)) return bs(mid + 1, r, x); 
    if(mid - 1 >= 0 && f(mid - 1, x) < f(mid, x)) return bs(l, mid - 1, x); 

    // OPTION 2: For MAXIMUM queries (Use `>`)
    // Search the side that yields a LARGER value
    // if(mid + 1 < m.size() && f(mid + 1, x) > f(mid, x)) return bs(mid + 1, r, x); 
    // if(mid - 1 >= 0 && f(mid - 1, x) > f(mid, x)) return bs(l, mid - 1, x); 
    
    return f(mid, x);
  }
};

ll a[N], b[N];
CHT cht;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  
  // Example initialization
  cht.add(b[0], 0);
  ll ans = 0;
  for(int i = 1; i < n; i++) {
    ans = cht.query(a[i]);
    cht.add(b[i], ans);
  }
  
  cout << ans << nl;
  return 0;
}
