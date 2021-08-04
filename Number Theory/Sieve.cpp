#include<bits/stdc++.h>

using namespace std;
#define RANGE 10000
vector < int > primes;
//if the index is prime true else false.
bool mark[RANGE + 2];

void sieve() {
    int i, j;
    mark[1] = false;
    mark[2] = true;
    for (i = 3; i <= RANGE; i += 2) mark[i] = true;
    int limit = sqrt(RANGE) + 2;
    for (i = 2; i <= RANGE; i++) {
        if (mark[i]) {
            primes.push_back(i);
            if (i < limit) {
                for (j = i * i; j <= RANGE; j += i * 2) {
                    mark[j] = false;
                }
            }
        }
    }
}
