/*
1. init que; with starting color
2. BFS using que; 
3. explore the childrens 
    3.1 change startingColor -> finalColor
    3.2 push children into que; 
*/


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int m = image.size(); 
        int n = image[0].size(); 

        int startingColor = image[sr][sc]; 
        if( startingColor == color) 
            return image; 

        //1. init que; with starting color
        queue<tuple<int,int>> que; 
        que.push({sr, sc}); 
        image[sr][sc] = color; 

        vector<int> dt = {-1, 0, 1, 0, -1}; 
        //2. BFS using que; 
        while( !que.empty()){
            auto [r, c] = que.front(); 
            que.pop(); 

            //3. explore the childrens 
            for(int i = 0 ; i < 4 ; i++){
                int nr = r + dt[i] ; 
                int nc = c + dt[i+1];    
                bool boundryCheck = nr >= 0 && nr < m && nc >= 0 && nc < n ; 
                if( boundryCheck && image[nr][nc] == startingColor){
                    //3.1 change startingColor -> finalColor
                    image[nr][nc] = color; 
                    //3.2 push children into que; 
                    que.push({nr, nc});
                }
            }
        }
        return image;
    }
};