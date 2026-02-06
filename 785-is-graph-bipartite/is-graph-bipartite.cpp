class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for (int i = 0; i < n; ++i) {
            if (colors[i] != -1) continue;
            //int color = 1;
            queue<int> q;
            q.push(i);
            colors[i] = 1;
            //color ^= 1;
            while (!q.empty()) {
                int SIZE = q.size();
                while(SIZE--) {
                    int curr = q.front();
                    q.pop();
                    for (auto& nxt : graph[curr]) {
                        if (colors[nxt] == colors[curr]) {
                            return false;
                        }
                        if (colors[nxt] == -1) {
                            colors[nxt] = colors[curr] ^ 1;
                            q.push(nxt);
                        }
                    }
                }
                //color ^= 1;
            }
        }
        return true;
    }
};