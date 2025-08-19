vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = min(r - i, p[l + (r - i)]);
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p), end(p));
}


vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

/*
  for string abcbcba
  it converts the string to #a#b#c#b#c#b#a# and returns 
  a vector res where res[j] is the number of odd palindrom
  centered at j.
  (res[2i+1])/2 = length of the odd palindrom centered at i of the strng
  (res[2i]-1)/2 = length of the even palindrom centered at (i-1,i)
*/



/*
  1. Find All Palindromic Substrings
  2. Find the Longest Palindromic Substring
  3. Count the Number of Palindromic Substrings
  4. Check if a Substring is a Palindrome in O(1)
  5. Find All Even and Odd Length Palindromes
  6. Palindrome Queries
*/
