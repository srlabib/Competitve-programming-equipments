#include <iostream>
using namespace std;

// O(log(n)) complexity 
//return (1+a+a^2+a^3+....a^b-1) mod m
int bigsum(int a,int b,int m)
{
    if(b==1)return 1;
    int x = (bigsum(((a%m)*(a%m))%m,b/2,m)%m)*(a+1) %m;
    if(b%2==1)x = (1+a*x)%m;
    return x%m;
}

int main(){

    cout<<bigsum(3,10,5)<<endl;

  
