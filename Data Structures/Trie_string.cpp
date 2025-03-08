#include <bits/stdc++.h>
using namespace std;


struct trie{
    struct node{
        node * next[26] = {NULL};
        int PrefCount = 0;
        int wordCount = 0;
    }*root;

    trie(){
        root = new node();
    }

    void insert(string s){
        node * cur = root;
        for(int i = 0; i<s.length(); i++){
            if(cur->next[s[i]-'a'] == NULL){
                cur->next[s[i] - 'a'] = new node();
            }
            cur = cur->next[s[i]-'a'];
            cur->PrefCount++;
        }
        cur->wordCount++;
    }


    int countWord(string s){
        node *cur = root;
        for(int i = 0; i<s.length(); i++){
            if(cur->next[s[i]-'a'] == NULL)return 0;
            cur = cur->next[s[i]-'a'];
        }
        return cur->wordCount;
    }

    int countPref(string s){
        node *cur = root;
        for(int i = 0; i<s.length(); i++){
            if(cur->next[s[i]-'a'] == NULL)return 0;
            cur = cur->next[s[i]-'a'];
        }
        return cur->PrefCount;
    }


};

int main(){
    int n,m;
    cin>>n>>m;
    trie t;
    while(n--){
        string s;
        cin>>s;
        t.insert(s);
    }

    while(m--){
        string s;
        cin>>s;
        cout << t.countPref(s) << endl;
    }
}
