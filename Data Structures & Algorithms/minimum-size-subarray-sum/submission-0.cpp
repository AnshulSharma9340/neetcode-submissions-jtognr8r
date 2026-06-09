class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i<n ; i++){
            int sum = 0;
            for(int j = i ; j <n ; j++){
                sum+= nums[j];

                if(sum >= target){
                    ans = min(ans , j-i+1);
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};