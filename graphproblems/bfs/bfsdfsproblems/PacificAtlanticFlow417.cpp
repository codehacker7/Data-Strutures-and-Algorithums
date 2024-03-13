class Solution {
public:

    void func(std::vector<std::vector<int>>& heights, int row, int col, int prev, std::vector<std::vector<int>>& ocean) {
        if (row < 0 || col < 0 || row >= heights.size() || col >= heights[0].size()) return;

        if (ocean[row][col] == 1) return;

        if (heights[row][col] < prev) return;

        ocean[row][col] = 1;

        func(heights, row + 1, col, heights[row][col], ocean);
        func(heights, row - 1, col, heights[row][col], ocean);
        func(heights, row, col + 1, heights[row][col], ocean);
        func(heights, row, col - 1, heights[row][col], ocean);
    }

    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        std::vector<std::vector<int>> ans;

        if (heights.size() < 1) return ans;

        std::vector<std::vector<int>> pacific(heights.size(), std::vector<int>(heights[0].size(), 0));
        std::vector<std::vector<int>> atlantic(heights.size(), std::vector<int>(heights[0].size(), 0));

        for (int i = 0; i < heights[0].size(); i++) {
            func(heights, 0, i, INT_MIN, pacific);
            func(heights, heights.size() - 1, i, INT_MIN, atlantic);
        }

        for (int j = 0; j < heights.size(); j++) {
            func(heights, j, 0, INT_MIN, pacific);
            func(heights, j, heights[0].size() - 1, INT_MIN, atlantic);
        }

        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    std::vector<int> v(2);
                    v[0] = i;
                    v[1] = j;
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};
