#include <iostream>
#include <vector>

using namespace std;

// Function to check if a bubble at given position can explode
bool canExplode(vector<vector<int> >& bubbles, int row, int col, int target) {
    int count = 0;
    int rows = bubbles.size();
    int cols = bubbles[0].size();

    // Check top neighbor
    if (row > 0 && bubbles[row - 1][col] == target)
        count++;
    // Check bottom neighbor
    if (row < rows - 1 && bubbles[row + 1][col] == target)
        count++;
    // Check left neighbor
    if (col > 0 && bubbles[row][col - 1] == target)
        count++;
    // Check right neighbor
    if (col < cols - 1 && bubbles[row][col + 1] == target)
        count++;

    // Bubble can explode if count is >= 2
    return count >= 2;
}

// Function to perform bubble explosion
void bubbleExplosion(vector<vector<int> >& bubbles) {
    int rows = bubbles.size();
    int cols = bubbles[0].size();
    bool exploded = true;

    while (exploded) {
        exploded = false;

        // Mark bubbles for explosion
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (bubbles[i][j] != 0 && canExplode(bubbles, i, j, bubbles[i][j])) {
                    bubbles[i][j] = 0;
                    exploded = true;
                }
            }
        }

        // Remove exploded bubbles and shift down remaining bubbles
        for (int j = 0; j < cols; ++j) {
            int k = rows - 1;
            for (int i = rows - 1; i >= 0; --i) {
                if (bubbles[i][j] != 0) {
                    bubbles[k--][j] = bubbles[i][j];
                }
            }
            while (k >= 0) {
                bubbles[k--][j] = 0;
            }
        }
    }
}

int main() {
    // Manually initialize the vector of vectors
    vector<vector<int> > bubbles;
    vector<int> row1;
    row1.push_back(3);
    row1.push_back(1);
    row1.push_back(2);
    row1.push_back(1);
    bubbles.push_back(row1);

    vector<int> row2;
    row2.push_back(1);
    row2.push_back(1);
    row2.push_back(1);
    row2.push_back(4);
    bubbles.push_back(row2);

    vector<int> row3;
    row3.push_back(13);
    row3.push_back(1);
    row3.push_back(2);
    row3.push_back(2);
    bubbles.push_back(row3);

    vector<int> row4;
    row4.push_back(3);
    row4.push_back(3);
    row4.push_back(3);
    row4.push_back(4);
    bubbles.push_back(row4);

    bubbleExplosion(bubbles);

    // Output the result
    for (const auto& row : bubbles) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
