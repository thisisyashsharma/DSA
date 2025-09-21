class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // 1.  intitialize the ans - matrix which stores INT_MAX;
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));

        // 2.  initialize the que - with all zeros
        queue<tuple<int, int, int>> que;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    que.push({i, j, 0});
                    ans[i][j] = 0;
                }
            }
        }

        vector<int> dt = {-1, 0, 1, 0, -1};

        // 3.  BFS - using iterative method - que;
        while (!que.empty()) {
            auto [r, c, dist] = que.front();
            que.pop();

            //  3.1 exploring the childrens  - using delta array method
            for (int i = 0; i < 4; i++) {
                int nr = r + dt[i];
                int nc = c + dt[i + 1];
                bool boundryCheck = nr >= 0 && nr < m && nc >= 0 && nc < n;
                if (boundryCheck && ans[nr][nc] > dist + 1) {
                    ans[nr][nc] = dist + 1;
                    que.push({nr, nc, dist + 1});
                }
            }
        }

        return ans; 
    }
};