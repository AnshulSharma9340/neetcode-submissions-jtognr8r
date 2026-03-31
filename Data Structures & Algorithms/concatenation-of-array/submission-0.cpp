class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int original_size = nums.size();

        for (int i =0 ; i < original_size ; i++){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};