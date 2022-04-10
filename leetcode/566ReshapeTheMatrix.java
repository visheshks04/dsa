class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        
        if(mat.length*mat[0].length != r*c)
            return mat;
        
        int[][] reshaped = new int[r][c];
        
        int matI=0, matJ=0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                reshaped[i][j] = mat[matI][matJ];
                if(matJ == mat[0].length - 1){
                    matJ = 0;
                    matI++;
                }
                else
                    matJ++;
            }
        }
        
        return reshaped;
    }
}
