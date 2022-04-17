class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] ans = new int[nums.length];
        int[] fromLeft = new int[nums.length];
        int[] fromRight = new int[nums.length];
        
        int leftProd = 1, rightProd = 1;
        
        for(int i=0;i<nums.length;i++){
            leftProd = leftProd * nums[i];
            fromLeft[i] = leftProd;
            rightProd = rightProd * nums[nums.length-1-i];
            fromRight[nums.length-1-i] = rightProd;
        }
        
        for(int i=0;i<ans.length;i++){
            if(i == 0)
                ans[i] = fromRight[i+1];
            else if(i == ans.length - 1)
                ans[i] = fromLeft[i-1];
            else
                ans[i] = fromLeft[i-1] * fromRight[i+1];
        }
        
        return ans;
    }
}
