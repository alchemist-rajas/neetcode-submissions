class NumMatrix {
private:
        vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty() ||matrix[0].empty()) return;

        int rows= matrix.size();
        int cols=matrix[0].size();

        //size it to (Rows+1) X (cols+1) filled with 0s to make the math clean
        prefix.assign(rows+1,vector<int>(cols+1,0));


        //build prefix sum matrix
        for(int r=0; r<rows;++r){
            for(int c=0; c< cols; ++c){
                prefix[r+1][c+1] = matrix[r][c]
                                  + prefix[r][c+1]
                                  + prefix[r+1][c]
                                  -prefix[r][c];
            }
        }   
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        //evaluate the regions instantly in O(1) using our precomputed formula
        return  prefix[row2 +1][col2 +1]
                -prefix[row1][col2+1]
                -prefix[row2 +1 ][col1]
                +prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */