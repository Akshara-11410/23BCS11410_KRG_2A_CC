#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int maxVal = 0;
            int best = 0;

            for (int j = i; j < min(n, i + k); j++) {
                maxVal = max(maxVal, arr[j]);
                int len = j - i + 1;
                best = max(best, maxVal * len + dp[j + 1]);
            }

            dp[i] = best;
        }

        return dp[0];
    }
};
