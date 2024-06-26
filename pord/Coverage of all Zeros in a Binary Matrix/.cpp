

class Solution {
  public:
    int count(int i, int j, int n, int m, vector<vector<int>> mat)
    {
        int v=0;
        if(i+1<n && mat[i+1][j]==1)
            v++;
        if(i-1>=0 && mat[i-1][j]==1)
            v++;
        if(j+1<m && mat[i][j+1]==1)
            v++;
        if(j-1>=0 && mat[i][j-1]==1)
            v++;
        
        return v;
    }
    int findCoverage(vector<vector<int>>& mat) 
    {
        int ans=0;
        int n=mat.size(), m=mat[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==0)
                {
                    // ans+=count(i, j, n, m, mat);
                    if(i+1<n && mat[i+1][j]==1)
                        ans++;
                    if(i-1>=0 && mat[i-1][j]==1)
                        ans++;
                    if(j+1<m && mat[i][j+1]==1)
                        ans++;
                    if(j-1>=0 && mat[i][j-1]==1)
                        ans++;
                }
            }
        }
        return ans;
    }
};
