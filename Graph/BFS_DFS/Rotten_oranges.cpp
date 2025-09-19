/*
Intuition 

1. init queue - which store i, j, distance 
2. bfs using  que;
  - explore childrens - using delta array method
  - rotten orange and push in que; 
3. if there any fresh orange remained then return -1

*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 1. init queue - which store i, j, distance 
        queue<tuple<int, int, int>> que;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    que.push({i, j, 0});
                }
            }
        }
        int time = 0;
        int maxi = 0;
        vector<int> dt = {-1, 0, 1, 0, -1};

        // 2. bfs using  que;
        while (!que.empty()) {
            auto [r, c, time] = que.front();
            que.pop();

            // explore childrens - using delta array method
            for (int i = 0; i < 4; i++) {
                int nr = r + dt[i];
                int nc = c + dt[i + 1];
                bool condition = nr >= 0 && nr < m && nc >= 0 && nc < n;
                if (condition && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;                 //same as mark visited
                    que.push({nr, nc, time + 1});
                }
            }

            maxi = max(maxi, time);
        }

        // 3. if there any fresh orange remained then return -1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return maxi;
    }
};