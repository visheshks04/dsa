class Solution {
    public void rotate(int[][] ar) {

        int n = ar.length;

        // Transpose
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++){
                if(i>j){
                    int temp = ar[i][j];
                    ar[i][j] = ar[j][i];
                    ar[j][i] = temp;
                }
            }
        } 

        // Flip horizontally
        for(int i=0; i<n;i++){
            for(int j=0;j<n/2;j++){
                int temp = ar[i][j];
                ar[i][j] = ar[i][n-j-1];
                ar[i][n-j-1] = temp;
            }
        }
    }
}

/*

Transpose->

[
    [1,4,7]
    [2,5,8]
    [3,6,9]
]

Flip horizontal->

[
    [7,4,1]
    [8,5,2]
    [9,6,3]
]

*/
