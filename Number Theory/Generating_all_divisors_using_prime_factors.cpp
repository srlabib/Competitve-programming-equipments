vector<int>primes;

//a sieve function must be placed here to generate all primes

int main(){
    sieve();
    ll n;
    cin>>n;
    ll N = n;
    set<ll>divisors = {1};
    for(auto e:primes){
        if(1LL*e*e>N)break;
        while(N%e == 0){
            set<ll>newset(All(divisors));  
            for(auto d:newset){
                divisors.insert(d*e);
            }
            N/=e;
        }
    }

    if(N>1){
        set<ll>newset(All(divisors));
        for(auto d: newset)divisors.insert(d*N);
    }
}

// little bit efficient that sqrt(n) complexity
