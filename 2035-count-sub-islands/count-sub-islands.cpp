void dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int m, int n, bool& isSubIsland) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] != 1) {
        return;
    }

    // Mark the current cell as visited in grid2
    grid2[i][j] = 0;

    // If the corresponding cell in grid1 is not land, mark the flag as false
    if (grid1[i][j] == 0) {
        isSubIsland = false;
    }

    // 4 possible directions
    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {-1, 0, 1, 0};

    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];

        dfs(nx, ny, grid1, grid2, m, n, isSubIsland);
    }
}

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();

        int count = 0;

        // Iterate over each cell in grid2
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Start DFS only if we find a land cell in grid2
                if (grid2[i][j] == 1) {
                    bool isSubIsland = true;  // Initialize flag to true

                    // Perform DFS to check if this is a sub-island
                    dfs(i, j, grid1, grid2, m, n, isSubIsland);

                    // If it is a sub-island, increment the count
                    if (isSubIsland) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
