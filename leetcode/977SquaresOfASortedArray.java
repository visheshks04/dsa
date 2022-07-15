class Solution {
    
    private int abs(int x){
        if (x<0)
            return -1*x;
        return x;
    }
    
    public int[] sortedSquares(int[] nums) {
        
        ArrayList<Integer> result = new ArrayList<>();
        
        int hi = nums.length-1;
        int lo = 0;
        
        while(hi>=lo){
            if(abs(nums[hi]) >= abs(nums[lo])){
                result.add(nums[hi]*nums[hi]);
                hi--;
            }
            else{
                result.add(nums[lo]*nums[lo]);
                lo++;
            }
        }
        
        int n = result.size();
        int[] ans = new int[n];
        
        for(int i=0;i<n;i++){
            ans[i] = result.get(n-i-1);
        }
        
        return ans;
    }
}

