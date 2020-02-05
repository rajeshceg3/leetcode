class Solution {
public:
    int uniquePaths(int m, int n) {
      // Entire dp table filled with 1 
      vector<vector<int>> dp( m, vector<int>(n,1));
      // Fill all columns & rows in dp table based on 
      // first row and column data
      for( int i = 1; i < m ; i++ )
      {
        for( int j = 1; j < n ; j++ )
        {
          dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
      }
      return dp[m-1][n-1];        
    }
};	
