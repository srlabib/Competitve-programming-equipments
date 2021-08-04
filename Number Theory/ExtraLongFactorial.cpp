#include<bits/stdc++.h>
 
using namespace std;

string add(string a, string b){
    int carry = 0;;
    string ans;
    int i = a.size()-1, j = b.size()-1;
    while(i>=0||j>=0)
    {
        int x = 0,y = 0,z;
        if(i>=0)
        {
            x = a[i--]-'0';
        }
        if(j>=0)
        {
            y = b[j--]-'0';
        }
        z = x+y+carry;
        carry = z/10;
        char ch = (z%10) + '0';
        ans = ch + ans;
    }
    if(carry>0)ans = to_string(carry) + ans;
    return ans;
}

string multiply(string a,string b)
{
    string ans;
    string zero;
    for(int i = b.size()-1;i>=0;i--)
    {
        string temp;
        int carry = 0;
        for(int j = a.size()-1;j>=0;j--)
        {
            int x = (a[j]-'0')*(b[i]-'0')+carry;
            carry = x/10;
            temp = to_string(x%10)+temp;
        }
        if(carry>0)temp = to_string(carry)+temp;
        ans = add(ans,temp+zero);
        zero.push_back('0');
    }
    return ans;
}

void extraLongFactorials(int n) {
    string ans = "1";
    while(n--)
    {
        string x = to_string(n+1);
        ans = multiply(ans,x);
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        extraLongFactorials(n);
    }
    return 0;
}
