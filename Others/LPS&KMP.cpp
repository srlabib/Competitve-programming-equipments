#include<bits/stdc++.h>
using namespace std;
/*
LPS function creates a vector for a string where for every index i it calculates the maximum lenth (lps[i]+1) of suffix of the subarray [1..i] 
which is also a prefix of the subarray

here lps[i] is a index of the string such that s[0...lps[i]] == the suffix of same length of subarray s[1...i]

lps[i] = -1 means the length of the suffix is 0

//concept from shafayets planet
//code from competitive programmng (mahbubul hasan)
*/
void LPS(vector<int> &a, string s){
    int n = a.size();
    a[0] = -1;
    int now = -1;
    for(int i =  1; i<n; i++){
        while(now != -1  && s[now+1] != s[i]){
            now  = a[now];
        }

        if(s[now+1]==s[i])now++;

        a[i] = now;

    }
}

vector<int>kmp(string s, string t){
    vector<int>lps(t.size());
    LPS(lps,t);
    int n = s.size();
    int m = t.size();
    for(auto e:lps)cout << e << " ";cout << endl;
    vector<int>res;
    int i = -1;
    for(int j = 0; j<n; j++){

        while(i != -1 && t[i+1]!=s[j]){
            i = lps[i];
        }
        if(t[i+1]==s[j]){
            i++;
            if(i == m-1){
                res.push_back(j-m+1);
                i = lps[i];
            }
        }
        
    }
    return res;
}

int main(){
    string s,t;
    cin>>s>>t;

    vector<int>res = kmp(s,t);

    for(auto e:res)cout << e << " ";
    cout << endl;

}
