/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peak(MountainArray &arr, int low, int high) {
        if(low == high){
            return low;
        }
        int mid = low + (high - low) / 2;
        if (arr.get(mid + 1) > arr.get(mid)) {
            return peak(arr, mid + 1, high);
        } else {
            return peak(arr, low, mid);
        }
    }

    int binarySearch(MountainArray &mountainArr, int left, int right, int target, bool isAscending) {
        while(left<=right){
            int mid = left+(right-left)/2;
            int value = mountainArr.get(mid);
            if(value == target){
                return mid;
            }
            else{
                if(isAscending){
                    if(value < target){
                        left = mid+1;

                    }
                    else{
                        right=mid-1;
                    }
                }
                else{
                    if(value < target){
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peakIndex = peak(mountainArr, 0, n - 1);
        int ans = binarySearch(mountainArr , 0, peakIndex, target,true);
        if(ans != -1){
            return ans;
        }
        else{
            return binarySearch(mountainArr, peakIndex + 1, n - 1, target, false);
        }
    }
};