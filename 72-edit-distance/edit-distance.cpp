class Solution {
public:
    int minDistance(string word1, string word2) {
        long long int n=word1.size();
        long long int m=word2.size();
        long long int dp[n+1][m+1];
        for(long long int i=0; i<=n; i++) {
            for(long long int j=0; j<=m; j++) {
                if(i==0) dp[i][j]=j;
                else if(j==0) dp[i][j]=i;
                else if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min(dp[i][j-1], min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
        return dp[n][m];
    }
};