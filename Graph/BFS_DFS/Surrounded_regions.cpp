/*
Intuition 

1. initialize ans with 'X' 
2. initialize queue with all the edge 'O', put 'O' in ans , also mark then visited in board
3. BFS -  iterative - using que; 
				3.1 exploring the childrens 
						- push the child if they are 'O' 
			
4. push all the value of ans in board; 
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(); 
        int n = board[0].size(); 

        //1. initialize ans with 'X' 
        vector<vector<char>> ans(m, vector<char>(n, 'X'));

        //2. initialize queue with all the edge 'O', put 'O' in ans , also mark then visited in board
        queue<pair<int,int>> que; 
        for(int i = 0 ; i < m ;i++){
            for(int j = 0 ; j < n ; j++){
                bool edge = i == 0 || i == m -1 || j == 0 || j == n - 1; 
                if( edge && board[i][j] == 'O'){
                    que.push({i, j});
                    ans[i][j] = 'O';

                    //mark then visited in board; 
                    board[i][j] = 'X'; 
                }
            }
        }

        vector<int> dt = {-1, 0, 1, 0, -1};

        //3. BFS -  iterative - using que; 
        while( !que.empty()){
            auto[ r, c ] = que.front(); 
            que.pop();

            //3.1 explore the childrens - using delta array method 
            for(int i = 0 ; i < 4 ; i++ ){
                int nr = r + dt[i]; 
                int nc = c + dt[i+1]; 
                bool boundryCheck = nr >= 0 && nr < m && nc >= 0 && nc < n; 
                if( boundryCheck && board[nr][nc] == 'O'){
                    ans[nr][nc] = 'O';
                    que.push({nr, nc}); 

                    //mark children visited in board; 
                    board[nr][nc] = 'X'; 
                }
            }
        }


        //4. push all the value of ans in board; 
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                board[i][j]  = ans[i][j]; 
            }
        }
    }
};