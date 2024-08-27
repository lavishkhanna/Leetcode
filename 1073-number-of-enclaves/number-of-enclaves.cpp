class Solution {
public:
    int res=0;
    
    void traverse(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        // get row and column length
        int m = grid.size();
        int n = grid[0].size();
        
        // return if crossing bounds
        if (i<0 || j<0 || i>=m || j>=n)
            return;
        
        // return if visited
        if (visited[i][j])
            return;
        
        // visit node[i][j]
        visited[i][j] = true;
        
        // if node[i][j] is ocean, skip
        if (grid[i][j] == 0)
            return;
        
        // if node[i][j] is land, recursively floodfill all adjacent lands
        if (grid[i][j] == 1)
            grid[i][j] = 0;
            res++;
        
        traverse(grid, i-1, j, visited); //up
        traverse(grid, i+1, j, visited); //down
        traverse(grid, i, j-1, visited); //left
        traverse(grid, i, j+1, visited); //right
    }
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        int m = grid.size();
        int n = grid[0].size();
        
        // calculate number of lands on the boundaries
        for (int j=0; j<n; j++)
            traverse(grid, 0, j, visited);
        for (int j=0; j<n; j++)
            traverse(grid, m-1, j, visited);
        for (int i=0; i<m; i++)
            traverse(grid, i, 0, visited);
        for (int i=0; i<m; i++)
            traverse(grid, i, n-1, visited);
        
        // reset result to 0
        res = 0;
        // calculate number of inner lands
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                traverse(grid, i, j, visited);
        return res;
    }
};