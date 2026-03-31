class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int>s(nums.begin() , nums.end());
       int maxlen = 0;
       for(int num: nums) {
            if(s.find(num-1) == s.end()){
                int curnum = num;
                int length =1;

            

            while(s.find(curnum+1) != s.end()){
                curnum++;
                length++;
            }

            maxlen = max(maxlen , length);
       } 
       }
       return maxlen;
    }
};
