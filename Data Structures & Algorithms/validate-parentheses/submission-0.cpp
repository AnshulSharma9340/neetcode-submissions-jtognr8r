class Solution {
public:
    bool isValid(string s) {
        int n;
        do {
            n = s.length();

            for (int i = 0; i + 1 < s.length(); i++) {
                if ((s[i] == '(' && s[i+1] == ')') ||
                    (s[i] == '{' && s[i+1] == '}') ||
                    (s[i] == '[' && s[i+1] == ']')) {
                    
                    s.erase(i, 2);
                    break;
                }
            }

        } while (n != s.length());

        return s.empty();
    }
};
