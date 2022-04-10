class Solution {
    public int[] sumZero(int n) {
        int[] ar = new int[n];
        
        if(n%2 != 0){
            ar[n-1] = 0;
        }
        
        for(int i=0;i<n-1;i+=2){
            ar[i] = i+1;
            ar[i+1] = -1*(i+1);
        }
        
        return ar;
    }
}
