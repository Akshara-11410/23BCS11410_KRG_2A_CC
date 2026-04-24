#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0), index(n);
        for(int i = 0; i < n; i++) index[i] = i;
        mergeSort(nums, index, counts, 0, n - 1);
        return counts;
    }
    
    void mergeSort(vector<int>& nums, vector<int>& index, vector<int>& counts, int left, int right) {
        if(left >= right) return;
        int mid = (left + right) / 2;
        mergeSort(nums, index, counts, left, mid);
        mergeSort(nums, index, counts, mid + 1, right);
        merge(nums, index, counts, left, mid, right);
    }
    
    void merge(vector<int>& nums, vector<int>& index, vector<int>& counts, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0, rightCount = 0;
        
        while(i <= mid && j <= right) {
            if(nums[index[j]] < nums[index[i]]) {
                temp[k++] = index[j++];
                rightCount++;
            } else {
                counts[index[i]] += rightCount;
                temp[k++] = index[i++];
            }
        }
        
        while(i <= mid) {
            counts[index[i]] += rightCount;
            temp[k++] = index[i++];
        }
        
        while(j <= right) {
            temp[k++] = index[j++];
        }
        
        for(int p = 0; p < temp.size(); p++) {
            index[left + p] = temp[p];
        }
    }
};
