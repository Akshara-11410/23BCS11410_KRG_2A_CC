#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool possible(vector<int>& nums, int maxop, int penalty){
    int op = 0;

    for(int x : nums){
        op += (x - 1) / penalty;
    }

    return op <= maxop;
}

int main(){

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int maxop;
    cin >> maxop;

    int l = 1;
    int h = *max_element(nums.begin(), nums.end());
    int ans = h;

    while(l <= h){

        int mid = (l + h) / 2;

        if(possible(nums, maxop, mid)){
            ans = mid;
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << ans;
}
