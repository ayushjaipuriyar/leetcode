class Solution {
public:
    void dfs(vector<vector<int>>& k, int i, vector<bool>& visited) {
        visited[i] = true;
        int n = k.size();
        for (int j=0; j<n; j++) {
            if (k[i][j]==1 && visited[j]==false) {
                dfs(k, j, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& k) {
        int n = k.size();
        vector<bool> visited(n, false);
        int c = 0;
        for (int i=0; i<n; i++) {
            if (visited[i]==false) {
                c++;
                dfs(k, i, visited);
            }            
        }
        return c;
    }
};