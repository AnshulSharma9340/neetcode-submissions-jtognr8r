class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0 , right = height.size()-1 , max_left  = height[left] , max_right = height[right] , total_water = 0;
        while(left < right){
            if(max_left < max_right){
                left++;
                max_left = max(max_left , height[left]);
                total_water += max_left - height[left];
            } else{
                right--;
                max_right = max(max_right , height[right]);
                total_water += max_right - height[right];
            }
        }

            return total_water;
    }
};
