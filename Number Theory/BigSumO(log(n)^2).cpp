#include <iostream>
using namespace std;

//return a^p mod b
int mod(int a,int p,int b)
{
    if(p==0)return 1%b;
    int x = mod(a,p/2,b);
    x = (x*x) % b;
    if(p%2==1)x=(x*a)%b;
    return x;
}


// O((log(n))^2) complexity 
//return (1+a+a^2+a^3+....a^b-1) mod m
int bigsum(int a,int b,int m)
{
    if(b==1)return 1;
    int x = (bigsum(a,b/2,m)%m)*(mod(a,b/2,m)+1);
    if(b%2==1)x = (x+mod(a,b-1,m))%m;
    return x%m;
}

int main(){

    cout<<bigsum(3,102,5)<<endl;

    return 0;
}
