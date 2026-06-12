class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> need(128, 0);
        vector<int> window(128, 0);

        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int formed = 0;
        int required = t.size();

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            char ch = s[right];
            window[ch]++;

            if (window[ch] <= need[ch]) {
                formed++;
            }

            while (formed == required) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char remove = s[left];
                window[remove]--;

                if (window[remove] < need[remove]) {
                    formed--;
                }

                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};