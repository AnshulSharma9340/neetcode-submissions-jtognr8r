class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        
        int cur = 0;
        freq[cur]++;
        int res = 0;
        for (int x : nums) {
            cur += x;
            int need = cur - k;
            res += freq[need];
            freq[cur]++;
        }
        return res;
    }
};