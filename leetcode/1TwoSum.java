class Solution {
    public int[] twoSum(int[] nums, int target) {
        int head, tail;
        int[] result = new int[2];
        int[] nums2 = new int[nums.length];
        
        for(int i=0;i<nums.length;i++){
            nums2[i] = nums[i];
        }
        
        boolean same = true;
        
        for(int i=0;i<nums.length-1;i++){
            int nextIndex = i+1;
            if(nums[i] != nums[nextIndex]){
                same = false;
                break;
            }
        }
        
        if(!same)
            Arrays.sort(nums);
        
        head = 0;
        tail = nums.length - 1;
        
        while(tail > head){
            if(nums[head]+nums[tail] == target){
                for(int i=0;i<nums.length;i++){
                    if(nums[head] == nums2[i]){
                        result[0] = i;
                        break;
                    }
                }
                
                for(int i=nums.length-1;i>=0;i--){
                    if(nums[tail] == nums2[i]){
                        result[1] = i;
                        break;
                    }
                }
                
                break;
            }
            else if(nums[head] + nums[tail] > target){
                tail--;
            }
            else{
                head++;
            }
        }
        
        return result;
    }
}
