#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &A) {
        const int MOD = 1e9 + 7;
        int n = A.size();
        long long ans = 0;

        for(int bit = 0; bit < 32; bit++) {
            long long count1 = 0;
            for(int i = 0; i < n; i++) {
                if(A[i] & (1LL << bit)) count1++;
            }
            long long count0 = n - count1;
            ans = (ans + (count1 * count0 % MOD) * 2 % MOD) % MOD;
        }

        return (int)ans;
    }
};
