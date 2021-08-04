/****Bismillahir rahmanir rahim****/

#include<bits/stdc++.h>

using namespace std;

int egcd(int a,int b, int &x,int &y)
{
    if(a==0){
        x = 0;
        y = 1;
        return b;
    }
    int x1,y1;
    int d = egcd(b%a,a,x1,y1);

    x = y1 - (b/a) * x1;
    y = x1;

    return d;
}

//returns a^-1 mod n
int modularInverse(int a,int n)
{
    int x,y,ret = egcd(a,n,x,y);
    return (x%n+n)%n;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout << modularInverse(a,b) << endl;
    return 0;
}
