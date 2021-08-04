#include <iostream>
using namespace std;

int egcd(int a,int b,int &x,int &y)
{
    if(a==0)
    {
        x =0; y=1;
        return b;
    }
    int x1,y1;
    int d=egcd(b%a,a,x1,y1);
    x = y1 - (b/a)*x1;
    y = x1;
    
    return d;
}

int main(){

    int x,y;
    cout<< egcd(82,36,x,y)<<endl;
    cout << x << " " << y << endl;

    return 0;
}
