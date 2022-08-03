class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        
        int hi = nums.length-1;
        int lo = 0;
        
        int max = -1;
        
        while(hi > lo){
            if(nums[hi] + nums[lo] > max)
                max = nums[hi] + nums[lo];
            hi--;
            lo++;
        }
        
        return max;
    }
}
