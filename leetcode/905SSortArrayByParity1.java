class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int head = 0;
        int tail = nums.length - 1;

        while(head<nums.length && nums[head]%2 == 0){
            head++;
        }

        while(tail>=0 && nums[tail]%2 != 0){
            tail--;
        }

        
        while(head<tail){

            int temp = nums[head];
            nums[head] = nums[tail];
            nums[tail] = temp;
            
            while(head<nums.length && nums[head]%2 == 0){
                head++;
            }

            while(tail>=0 && nums[tail]%2 != 0){
                tail--;
            }

            
        }
        
        return nums;
    }
}
