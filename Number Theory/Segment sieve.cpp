#include<bits/stdc++.h>

using namespace std;

void segment_sieve(long long a, long long b){
    int N = sqrt(b+1);
    vector<long long> primes;
    vector<bool> check(N+1,1);
    check[1] = 0;
    primes.push_back(2);
    for(int i = 4; i<=N; i+=2)check[i] = 0;
    for(int i = 3; i<=N; i+=2){
        if(check[i]){
            primes.push_back(i);
            if(i*i>N)continue;
            for(int j = i*i; j<=N; j+=2*i){
                check[j] = 0;
            }
        }
    }
    int n2 = primes.size();
    
    vector<bool>check2(b-a+1,1);
    for(int i = 0; i<n2; i++){
        int f = a%primes[i]==0?a/primes[i]:a/primes[i]+1;
        for(int j = f*primes[i]-a; j<=b-a; j+=primes[i]){
            check2[j] = 0;
        }
    }
    int cnt = 0;
    for(int i = 0; i<=b-a; i++){
        if(check2[i]){
            cout<<i+a<<" ";
            cnt++;
        }
    }
    cout<<endl<<endl<<cnt<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--)
    {
        int a,b;
        cin>>a>>b;
        segment_sieve(a,b);
    }
    return 0;
}
