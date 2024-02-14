class Solution {
public:
    void helper(vector<vector<int>>& image, int sr, int sc, int newColor, int originalColor) {
        // Base case: check boundaries and whether the pixel has the original color or is already visited
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != originalColor ) {
            return;
        }

        // Mark the pixel as visited
        

        // Change the color of the current pixel
        image[sr][sc] = newColor;

        // Recursively call helper function for 4 neighboring pixels
        helper(image, sr - 1, sc, newColor, originalColor); // go up
        helper(image, sr + 1, sc, newColor, originalColor); // go down
        helper(image, sr, sc - 1, newColor, originalColor); // go left
        helper(image, sr, sc + 1, newColor, originalColor); // go right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Check if the new color is different from the original color to avoid unnecessary recursion
        if (image[sr][sc] != newColor) {
            int originalColor = image[sr][sc];
            vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
            helper(image, sr, sc, newColor, originalColor);
        }

        return image;
    }
};
