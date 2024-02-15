void bfs(int row, int col, vector<vector<int>> &visited, int M[][COL], int n, int m) {
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    visited[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty()) {
        int currRow = q.front().first;
        int currCol = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int newRow = currRow + dx[i];
            int newCol = currCol + dy[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol] && M[newRow][newCol] == 1) {
                visited[newRow][newCol] = 1;
                q.push({newRow, newCol});
            }
        }
    }
}

int numIslands(int M[][COL], int n, int m) {
    vector<vector<int>> visited(n, vector<int>(m, 0));

    int count = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (visited[row][col] == 0 && M[row][col] == 1) {
                bfs(row, col, visited, M, n, m);
                count++;
            }
        }
    }

    return count;
}
