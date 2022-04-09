class Solution {
    public int[][] transpose(int[][] matrix) {
        int[][] transpose = new int[matrix[0].length][matrix.length];
        
        for(int i=0;i<transpose.length;i++){
            for(int j=0;j<transpose[i].length;j++){
                transpose[i][j] = matrix[j][i];
            }
        }
        
        return transpose;
    }
}
