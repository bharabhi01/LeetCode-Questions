class Solution {
public:
    int dist[8][2]={{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    int countLive(vector<vector<int>>& board,int i,int j,int m,int n)
    {
        int count = 0;
        
        for(int k = 0; k < 8; k++)
        {
            int x = i + dist[k][0];
            int y = j + dist[k][1];
            
            if(x >= 0 and y >= 0 and x < m and y < n and abs(board[x][y]) == 1) 
                count++;
        }
        
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int ans = countLive(board, i, j, m, n);
                
                if(board[i][j] == 1)
                {
                    if(ans < 2 or ans > 3) 
                        board[i][j] = -board[i][j];   
                }
                else
                {
                    board[i][j] = 2; 
                    
                    if(ans != 3) 
                        board[i][j] = -board[i][j]; 
                }
            }
        }
        
        for(int i = 0; i < m; i++)
        {    
            for(int j = 0; j < n; j++) 
                board[i][j] = board[i][j] < 0 ? 0 : 1;
        }
    }
};