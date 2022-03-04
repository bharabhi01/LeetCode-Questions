class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double glass[101][101] = {0.0};
        
        glass[0][0] = poured;
        
        for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < 100;j++)
            {
                if(glass[i][j] >= 1)
                {
                    glass[i + 1][j] += (glass[i][j] - 1) / 2.0;
                    glass[i + 1][j + 1] += (glass[i][j] - 1) / 2.0;
                    glass[i][j] = 1;
                }
            }
        }
        
        return glass[query_row][query_glass];
    }
};