class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
		
		for( int i = 1; i < n;i++)
			grid[0][i] = grid[0][i] + grid[0][i-1];
		
		for(int i = 1;i < m;i++)
			grid[i][0] = grid[i][0] + grid[i-1][0];
		
		for(int ri = 1; ri < m; ri++)
        {
			for(int ci = 1; ci < n; ci++) 
            {
				grid[ri][ci] = min( grid[ri-1][ci],grid[ri][ci-1]) + grid[ri][ci];
            }
        }
		return grid[m-1][n-1];       
    }
};
