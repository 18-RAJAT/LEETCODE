class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const int mod = 1000000007;
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0)));

        // Initialize dp[1][i][1] = 1 for 1 <= i <= m
        for (int i = 1; i <= m; ++i) {
            dp[1][i][1] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int l = 1; l <= k; ++l) {
                    for (int p = 1; p < j; ++p) {
                        dp[i][j][l] += dp[i - 1][p][l - 1];
                        dp[i][j][l] %= mod;
                    }
                    dp[i][j][l] += dp[i - 1][j][l] * j;
                    dp[i][j][l] %= mod;
                }
            }
        }

        long long ans = 0;
        for (int i = 1; i <= m; ++i) {
            ans += dp[n][i][k];
            ans %= mod;
        }

        return static_cast<int>(ans);
    }
};
