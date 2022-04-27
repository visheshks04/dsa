class Solution {
    public boolean checkIfPangram(String sentence) {
        
        char[] alpha = "abcedefghijklmnopqrstuvwxyz".toCharArray();
        boolean found;
        for(int i=0;i<alpha.length;i++){
            found = false;
            for(int j=0;j<sentence.length();j++){
                if(alpha[i] == sentence.charAt(j)){
                    found = true;
                    break;
                }
            }
            if(!found){
                return false;
            }
        }
        return true;
    }
}

/*
    Go to each letter in the alphabet and search for it in the given string.
    Time complexity: O(n)
*/
