class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int curr_size = 0;
        for(int i=0;i<n;i++){
            if(nums[i] != 0){
                int temp = nums[i];
                nums[i] = nums[curr_size];
                nums[curr_size] = temp;
                curr_size++;
            }
        }
    }
}
