class Solution:
    def mostPoints(self, q: List[List[int]]) -> int:
        memo = [None] * len(q)
        def dp(i):
            if i >= len(q):
                return 0
            if memo[i] is not None:
                return memo[i]
            points, jump = q[i][0],q[i][1]
            memo[i] = max(dp(i+1),points + dp(i+jump+1))
            return memo[i]
        return dp(0)