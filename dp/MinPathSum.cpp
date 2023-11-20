class Solution {
public:
  int helper(vector<vector<int>>& grid, int currrow, int currcol, int totalrows, int totalcols, vector<vector<int>>& memo) {
        if (currrow == totalrows - 1 && currcol == totalcols - 1) {
            return grid[currrow][currcol];
        }
        if (memo[currrow][currcol] != -1) {
            return memo[currrow][currcol];
        }


    int right = currcol + 1 < totalcols ? grid[currrow][currcol] + helper(grid, currrow, currcol + 1, totalrows, totalcols, memo) : INT_MAX;
        int down = currrow + 1 < totalrows ? grid[currrow][currcol] + helper(grid, currrow + 1, currcol, totalrows, totalcols, memo) : INT_MAX;

        // Memoize the result for the current cell
        memo[currrow][currcol] = min(right, down);

        return  min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {

               int totalrows = grid.size();
        int totalcols = grid[0].size();

        // Create a memoization table and initialize with -1
        vector<vector<int>> memo(totalrows, vector<int>(totalcols, -1));

        // Start the recursive calculation
        return helper(grid, 0, 0, totalrows, totalcols, memo);

        
    }
};