class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;

        int rows = matrix.size();
        if (rows == 0)
            return answer;

        int cols = matrix[0].size();
        if (cols == 0)
            return answer;

        int startRow = 0, endRow = rows - 1;
        int startCol = 0, endCol = cols - 1;

        while (startRow <= endRow && startCol <= endCol) {
            // Traverse right
            for (int col = startCol; col <= endCol; col++) {
                answer.push_back(matrix[startRow][col]);
            }
            startRow++;

            // Traverse down
            for (int row = startRow; row <= endRow; row++) {
                answer.push_back(matrix[row][endCol]);
            }
            endCol--;

            // Traverse left
            if (startRow <= endRow && startCol <= endCol ) {
                for (int col = endCol; col >= startCol; col--) {
                    answer.push_back(matrix[endRow][col]);
                }
                endRow--;
            }

            // Traverse up
            if (startCol <= endCol && startRow <= endRow ) {
                for (int row = endRow; row >= startRow; row--) {
                    answer.push_back(matrix[row][startCol]);
                }

                startCol++;
            }
        }

        return answer;
    }
};