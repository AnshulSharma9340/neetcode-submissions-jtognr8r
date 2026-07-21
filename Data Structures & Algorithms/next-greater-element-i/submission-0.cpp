class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n =  nums2.size();
        vector<int> ans;
        for(int i = 0 ; i<nums1.size(); i++){
            int j =0;
            for(;j<nums2.size() ; j++){
                if(nums2[j] == nums1[i]) {
                    break;
                }  
            }
            bool found = false;
            for(int k =j+1; k<nums2.size(); k++){
                if(nums2[k] > nums1[i]){
                    ans.push_back(nums2[k]);
                    found = true;
                    break;
                }
            }
            if(! found){
                ans.push_back(-1);
            }
        }
        return ans;

    }
};