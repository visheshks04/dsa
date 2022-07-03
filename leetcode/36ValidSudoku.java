class Solution {
    public boolean isValidSudoku(char[][] board) {
        
        // Checking for rows
        for(int i=0;i<board.length;i++){            
            HashMap<Character, Integer> freq = new HashMap<>();
            
            for(int j=0;j<board[i].length;j++){
                if(board[i][j] == '.')
                    continue;
                else if(freq.containsKey(board[i][j])){
                    System.out.println("loop1");
                    return false;
                }
                else
                    freq.put(board[i][j], 1);
            }
        }
        
        // Checking for columns
        for(int i=0;i<board.length;i++){            
            HashMap<Character, Integer> freq = new HashMap<>();
            
            for(int j=0;j<board[i].length;j++){
                if(board[j][i] == '.')
                    continue;
                else if(freq.containsKey(board[j][i])){
                    System.out.println("loop2");
                    return false;
                }
                else
                    freq.put(board[j][i], 1);
            }
        }
        
        // Checking for blocks of 3x3
        for(int i=0;i<board.length;i+=3){
            for(int j=0;j<board[0].length;j+=3){
                
                HashMap<Character, Integer> freq = new HashMap<>();
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(board[k][l] == '.')
                            continue;
                        else if(freq.containsKey(board[k][l])){
                            System.out.println("loop3");
                            return false;
                        }
                        else
                            freq.put(board[k][l], 1);
                    }
                }
                
            }
        }
        
        
        return true;
    }
}
