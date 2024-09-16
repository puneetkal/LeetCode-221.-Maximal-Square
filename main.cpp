class Solution {
public:
/*
    int solve(vector<vector<char>>& matrix, int i, int j, int& ans){
        if(i>=matrix.size()) return 0;
        if(j>=matrix[0].size()) return 0;

        int r = solve(matrix, i, j+1,ans);
        int dia= solve(matrix, i+1, j+1,ans);
        int down = solve(matrix, i+1, j,ans);

        if(matrix[i][j]=='1'){
            int len= 1+min(r, min(dia , down));
            ans = max(ans, len);
            return len;
        }
        else{
            return 0;
        }
    }

*/
    int maximalSquare(vector<vector<char>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        // base case is already zero dp[n-1][m-1]=0;
        // Loop from n-1 to 0
        int maxi=0;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int right=dp[i+1][j];
                int diagonal=dp[i+1][j+1];
                int down=dp[i][j+1];

                if(matrix[i][j]=='1'){
                    dp[i][j]=1+min(right,min(diagonal,down));
                    maxi=max(maxi,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return maxi*maxi;
    }
};