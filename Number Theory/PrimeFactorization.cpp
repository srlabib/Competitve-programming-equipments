#include <bits/stdc++.h>
 
using namespace std;
 
#define abs_val(a)       (((a)>0)?(a):-(a))
typedef long long        ll;

map <ll, ll> MAP;
ll mulMod(ll a, ll b, ll c)
{
    ll x = 0, y = a%c;
    while (b > 0)
    {
        if (b%2 == 1)
            x = (x+y)%c;
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
 
ll gcd(ll a, ll b)
{
     return !b ? a : gcd(b, a%b);
}
 
ll Mod(ll a, ll b, ll p)
{
    ll res = 1;
    ll x = a%p;
 
    while (b)
    {
        if (b&1)
        {
            res = mulMod(res, x, p);
        }
        x = mulMod(x, x, p);
        b /= 2;
    }
    return res%p;
}
 
 
bool millerTest(ll d, ll s, ll n)
{
    ll a = rand() % (n-4) + 2;
    ll x = Mod(a, s, n);
 
    if (x==1 or x==n-1)
        return true;
 
    for (int r = 1; r < d; r++)
    {
        x = mulMod(x, x, n);
 
        if (x==1)
            return false;
        if (x==n-1)
            return true;
    }
    return false;
}
 
 
 
bool isPrime(ll n, int k = 20)
{
    if (n <= 1 || n==4)
        return false;
    if (n<=3)
        return true;
    if (n%2==0)
        return false;
 
    ll s = n-1, d = 0;
    while (s%2==0)
    {
        s/=2;
        d++;
    }
    for (int i = 0; i < k; i++)
    {
        if (millerTest(d, s, n)==false)
            return false;
    }
    return true;
}
 
 
ll pollard_rho(ll n)
{
    if(n%2==0)
        return 2;
 
    ll x = rand()%n+1;
    ll c = rand()%n+1;
    ll y = x;
    ll g = 1;
 
    while(g==1)
    {
        x = (mulMod(x, x, n) + c)%n;
        y = (mulMod(y, y, n) + c)%n;
        y = (mulMod(y, y, n) + c)%n;
        g = gcd(abs_val(x-y),n);
    }
    return g;
}

void factorize(ll n)
{
    if(n == 1)
        return;
 
    ll divisor = pollard_rho(n);
	if(isPrime(n))      
    {
        MAP[n]++;
        return;
    }   
    factorize(divisor);
    factorize(n/divisor);
}
 
int main()
{
	ll n;
    cin >> n;
	factorize(n);
    for(auto e:MAP)
    {
        cout << e.first<<" " <<e.second<<endl;
    }
}
 
