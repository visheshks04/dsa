class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int hiRow = matrix.length-1;
        int loRow = 0;
        int midRow;
        
        while(hiRow >= loRow){
            
            midRow = loRow + (hiRow-loRow)/2;
            
            if(matrix[midRow][0] == target){
                return true;
            }
            
            else if(matrix[midRow][0] > target){
                hiRow = midRow-1;
            }
            
            else{
                loRow = midRow+1;
            }
        }
        
        int floorRow = hiRow;
        System.out.println(floorRow);
        if(floorRow < 0) floorRow = 0;

        
        int hiCol=matrix[floorRow].length-1;
        int loCol = 0;
        int midCol;
        
        while(hiCol >= loCol){
            
            midCol = loCol + (hiCol-loCol)/2;
            
            if(matrix[floorRow][midCol] == target){
                return true;
            }
            
            else if(matrix[floorRow][midCol] > target){
                hiCol = midCol-1;
            }
            else{
                loCol = midCol+1;
            }
        }
        
        return false;
        
    }
}
