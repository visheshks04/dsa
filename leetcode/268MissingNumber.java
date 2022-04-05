// https://leetcode.com/problems/missing-number/submissions/

class Solution {
    public int missingNumber(int[] nums) {
        int sum = 0;
        int n = nums.length;
        
        int required_sum = n*(n+1)/2;
        
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        
        return required_sum - sum;
    }
}



// For a range required sum should be n*(n+1)/2 so the missing number is (required_sum - actual_sum)
