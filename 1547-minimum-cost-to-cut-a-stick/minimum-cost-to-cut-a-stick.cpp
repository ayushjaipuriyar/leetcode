class Solution {
	int dp[101][101];
public:
    int minCost(int n, vector<int>& cuts) {
			ios::sync_with_stdio(false);
			cin.tie(nullptr);
			int m=cuts.size(), old=0, cur=1;
			sort(cuts.begin(), cuts.end());
			for(int i=0; i<m; ++i) {
					dp[i][i]=dp[m][i]=dp[i][m]=0;
			}
			for(int i=m-1, j, k, cost, lo; i>=0; --i) {
					for(j=i+1; j<=m; ++j) {
							cost=(j==m? n : cuts[j])-(!i? 0 : cuts[i-1]);
							lo=cost+dp[i+1][j];
							for(k=i+1; k<j; ++k) {
									lo=min(lo, cost+dp[i][k]+dp[k+1][j]);
							}
							dp[i][j]=lo;
							// cout<<"DP["<<i<<","<<j<<"]="<<lo<<"\n";
					}
			}
			return dp[0][m];
    }
};