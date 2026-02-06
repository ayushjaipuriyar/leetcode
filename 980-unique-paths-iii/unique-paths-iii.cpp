class Solution {
public:
    vector<vector<int>> directions {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

    int f(int i, int j, vector<vector<int>>& grid, int targetCount, int cnt) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
            return 0;

        if (grid[i][j] == 2) {
            cnt -= 1; // -1 since we have also included the start cell
            return (cnt == targetCount) ? 1 : 0; // if all empty cells visited, return 1; otherwise, return 0
        }

        grid[i][j] = -1;
        int sum = 0;

        for (auto& direction : directions) {
            int ni = i + direction[0];
            int nj = j + direction[1];
            sum += f(ni, nj, grid, targetCount, cnt + 1);
        }

        grid[i][j] = 0;
        return sum;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        pair<int, int> start;
        int targetCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    start = {i, j}; // store the starting index
                } else if (grid[i][j] == 0) {
                    targetCount++; // count the number of empty cells
                }
            }
        }

        return f(start.first, start.second, grid, targetCount, 0);
    }
};
