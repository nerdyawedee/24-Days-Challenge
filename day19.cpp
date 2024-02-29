class Solution {
public:
bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false}, col[9][9] = {false}, grid_3x3[9][9] = {false}; 
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == '.') {
                    continue;
                }
                int num = board[i][j] - '1', k = 3 * (i / 3) + (j  / 3);
                if(row[i][num] || col[j][num] || grid_3x3[k][num]) {
                    return false;
                }
                row[i][num] = col[j][num] = grid_3x3[k][num] = true;
            }
        return true;
    }
};

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> m;
        for(int i = 0; i < 9; i++) {
            unordered_set<char> r;
            for(int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }
                int index = 3 * (i / 3) + (j  / 3);
                if(r.count(c) || m[index].count(c) || m[9 + j].count(c)) {
                    return false;
                }
                r.insert(c);
                m[index].insert(c);
                m[9 + j].insert(c);
            }
        }
        return true; 
    }    
    
