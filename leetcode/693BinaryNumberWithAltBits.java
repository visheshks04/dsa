class Solution {
    public boolean hasAlternatingBits(int n) {
        int s = n&1;
        n >>= 1;
        while(n > 0){
            if(s == 0)
                s = 1;
            else
                s = 0;
            
            if((n&1) != s)
                return false;
            
            n >>= 1;
        }
        
        return true;
    }
}
