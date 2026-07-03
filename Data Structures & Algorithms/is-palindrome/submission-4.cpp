class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left < right ) {
            if(!((s[left] >= 'a' && s[left] <= 'z') ||
                 (s[left] >= 'A' && s[left] <= 'Z') ||
                 (s[left] >= '0' && s[left] <= '9'))) {
                    left ++;
                    continue;
                 }
            if(!((s[right] >= 'a' && s[right] <= 'z') ||
                 (s[right] >= 'A' && s[right] <= 'Z') ||
                 (s[right] >= '0' && s[right] <= '9'))) {
                    right --;
                    continue;
                 }

            char l = s[left];
            char r = s[right];
            if(l >= 'A' && l<= 'Z') l = l+32;
            if(r >= 'A' && r<= 'Z') r = r+32;
            if(l!= r) return false;
            left ++;
            right --;     
        }
        return true;

    }
};
