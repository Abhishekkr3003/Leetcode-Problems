class Solution {
public:
    int factOf5(int num) {
        int res = 0;
        while (num && num % 5 == 0) {
            res++;
            num /= 5;
        }
        return res;
    }
    int factOf2(int num) {
        int res = 0;
        while (num && num % 2 == 0) {
            res++;
            num /= 2;
        }
        return res;
    }

    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>fives(n, vector<int>(m));
        vector<vector<int>>twos(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                fives[i][j] = factOf5(grid[i][j]);
                twos[i][j] = factOf2(grid[i][j]);
            }
        }
        // cout<<"here\n";
        vector<vector<int>>prefvert5(n + 1, vector<int>(m + 1));
        vector<vector<int>>prefvert2(n + 1, vector<int>(m + 1));
        vector<vector<int>>prefhoriz5(n + 1, vector<int>(m + 1));
        vector<vector<int>>prefhoriz2(n + 1, vector<int>(m + 1));

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0) {
                    prefhoriz5[i][j] == 0;
                    prefhoriz2[i][j] == 0;
                }else{
                    prefhoriz5[i][j] = prefhoriz5[i][j - 1] + fives[i - 1][j - 1];
                    prefhoriz2[i][j] = prefhoriz2[i][j - 1] + twos[i - 1][j - 1];
                }
            }
        }
        // cout<<"here";

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0) {
                    prefvert5[j][i] == 0;
                    prefvert2[j][i] == 0;
                }else{
                    prefvert5[j][i] = prefvert5[j - 1][i] + fives[j - 1][i - 1];
                    prefvert2[j][i] = prefvert2[j - 1][i] + twos[j - 1][i - 1];
                }
            }
        }
        // for(auto v:prefvert5){
        //     for(int num:v) cout<<num<<" ";
        //     cout<<endl;
        // }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int vertdown2 = prefvert2[n][j+1] - prefvert2[i][j+1];
                int vertdown5 = prefvert5[n][j+1] - prefvert5[i][j+1];
                int vertup2 = prefvert2[i + 1][j + 1];
                int vertup5 = prefvert5[i + 1][j + 1];
                
                int horizleft2 = prefhoriz2[i + 1][j + 1];
                int horizleft5 = prefhoriz5[i + 1][j + 1];
                int horizRight2 = prefhoriz2[i + 1][m] - prefhoriz2[i + 1][j];
                int horizRight5 =  prefhoriz5[i + 1][m] - prefhoriz5[i + 1][j];
                
                int res1=min(horizleft2+vertup2-twos[i][j], horizleft5+vertup5-fives[i][j]);
                int res2=min(horizleft2+vertdown2-twos[i][j], horizleft5+vertdown5-fives[i][j]);
                int res3=min(horizRight2+vertup2-twos[i][j], horizRight5+vertup5-fives[i][j]);
                int res4=min(horizRight2+vertdown2-twos[i][j], horizRight5+vertdown5-fives[i][j]);
                res=max(res, max(res1,max(res2,max(res3,res4))));
                
                // res = max(res, max(vertdown + horizleft, max(vertdown + horizRight, max(vertup + horizRight, vertup + horizleft)))-sub);
                // // if(i==3 && j==2){
                //     cout<<i<<" "<<j<<" "<<vertdown<<" "<<vertup<<" "<<horizleft<<" "<<horizRight<<" "<<sub<<" "<<max(vertdown + horizleft, max(vertdown + horizRight, max(vertup + horizRight, vertup + horizleft)))-sub<<" "<<res<<endl;
                // }
            }


        }

        return res;



    }
};