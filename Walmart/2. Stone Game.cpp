typedef pair<int, int> pii;
class Solution {
public:
    bool stoneGame(vector<int> &piles) {
        int n = piles.size();
        vector<vector<pii>> dp(n, vector<pii>(n));
        for (int left = n - 1; left >= 0; --left) {
            for (int right = left; right < n; ++right) {
                if (left == right) { // Base case
                    dp[left][right] = make_pair(piles[left], 0);
                    continue;
                }
                pii pickLeft = dp[left + 1][right];
                pii pickRight = dp[left][right - 1];
                if (piles[left] + pickLeft.second > piles[right] + pickRight.second) // If the left choice has higher score than the right choice
                    dp[left][right] = make_pair(piles[left] + pickLeft.second, pickLeft.first); // then pick left
                else
                    dp[left][right] = make_pair(piles[right] + pickRight.second, pickRight.first); // else pick right
            }
        }
        auto[aliceScore, leeScore] = dp[0][n - 1];
        return aliceScore > leeScore;
    }
};