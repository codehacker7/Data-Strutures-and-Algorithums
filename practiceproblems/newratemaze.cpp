#include <iostream>
using namespace std;

bool rateinMaze(int grid[5][4], int path[5][4], int rows, int columns, int currRow, int currCol) {
    if (currRow == rows - 1 && currCol == columns - 1) {
        path[currRow][currCol] = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << path[i][j];
            }
            cout << endl;
        }
        return true;
    }

    path[currRow][currCol] = 1;

    if (currCol + 1 < columns && grid[currRow][currCol + 1] == 0 && path[currRow][currCol + 1] == 0) {
        bool canreach = rateinMaze(grid, path, rows, columns, currRow, currCol + 1);
        if (canreach) {
            return true;
        }
    }

    if (currRow + 1 < rows && grid[currRow + 1][currCol] == 0 && path[currRow + 1][currCol] == 0) {
        bool canreach = rateinMaze(grid, path, rows, columns, currRow + 1, currCol);
        if (canreach) {
            return true;
        }
    }

    if (currRow - 1 >= 0 && grid[currRow - 1][currCol] == 0 && path[currRow - 1][currCol] == 0) {
        bool canReach = rateinMaze(grid, path, rows, columns, currRow - 1, currCol);
        if (canReach)
            return true;
    }

    if (currCol - 1 >= 0 && grid[currRow][currCol - 1] == 0 && path[currRow][currCol - 1] == 0) {
        bool canReach = rateinMaze(grid, path, rows, columns, currRow, currCol - 1);
        if (canReach)
            return true;
    }

    path[currRow][currCol] = 0;
    return false;
}

int main() {
    int n = 5;
    int m = 4;

    int grid[5][4] = {
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {1, 0, 1, 0},
        {1, 0, 0, 1},
        {1, 1, 0, 0}
    };

    int path[5][4] = {0};

    rateinMaze(grid, path, 5, 4, 0, 0);

    return 0;
}
