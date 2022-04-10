class Solution {
    public int[] plusOne(int[] digits) {
        
        for(int i=digits.length-1;i>=0;i--){
            digits[i] += 1;
            if (digits[i] != 10)
                break;
            
            digits[i] = 0;
        }
        
        
        if(digits[0] == 0){
            int[] new_num = new int[digits.length+1];
            new_num[0] = 1;
            
            for(int i=1;i<new_num.length;i++){
                new_num[i] = digits[i-1];
            }
            return new_num;
        }
        
        return digits;
    }
}
