class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[i].size();j++)
            {
                ans[i][j] = matrix[i][j];
            }        
        }
        
        //now we need to iterate over each and every column of the matrix
        for(int col = 0; col < m;col++){
            int maxi = -1;
            int element = -1;
            for(int row = 0; row < n;row++){
                element = matrix[row][col];
                maxi = max(element,maxi);
            }
            // cout<<maxi<<" "<<endl;
            // break;
            for(int row = 0;row < n;row++){
                if(matrix[row][col] == -1){
                    matrix[row][col] = maxi;
                }
            }
        }
        
        return matrix;
        
    }
};