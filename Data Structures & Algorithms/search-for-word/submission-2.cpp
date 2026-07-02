class Solution {

public:
    bool findWholeWord(vector<vector<char>>& board, string word, int idx, int  i, int j){

        if(idx == word.size()) return true;

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] != word[idx]) return false;
        char temp = board[i][j];
        board[i][j] = '#';
        
        // left
        bool left = findWholeWord(board, word, idx+1, i, j-1);
        if(left == true) return true;

        // right
        bool right = findWholeWord(board, word, idx+1, i, j+1);
        if(right == true) return true;

        // top
        bool top = findWholeWord(board, word, idx+1, i-1, j);
        if(top == true) return true;

        //bottom
        bool bottom = findWholeWord(board, word, idx+1, i+1, j);
        if(bottom == true) return true;

        board[i][j] = temp;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0] && findWholeWord(board, word, 0, i ,j)){
                    return true;
                }
            }
        }
        return false;
    }
};