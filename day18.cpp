class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (left <= right && top <= bottom) {
            // push top row :-
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            // increase top (so for next column iterations, the top
            // index will be one more than before)
            top++;
            // push right column
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            // decrease right(so for next row iterations, the right
            // index will be less than before)
            right--;
            // push bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            // push left column
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
