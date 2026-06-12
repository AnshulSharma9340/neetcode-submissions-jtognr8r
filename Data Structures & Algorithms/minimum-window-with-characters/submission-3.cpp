class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0;
        int cnt = 0;
        int minlen = INT_MAX;
        int st = -1;
        int hash[256] = {0};
        for (char c : t) {
            hash[c]++;
        }
        while (r < s.size()) {
            if (hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;
            r++;
            while (cnt == t.size()) {
                if (r - l < minlen) {
                    minlen = r - l;
                    st = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
        }
        if (st == -1) {
            return "";
        }
        return s.substr(st, minlen);
    }
};