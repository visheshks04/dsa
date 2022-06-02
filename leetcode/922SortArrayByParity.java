class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        int even = 0;
        int odd = 0;
        
        while(even<nums.length){
            if(even%2 == 0 && nums[even]%2 != 0)
                break;
            even++;
        }

        while(odd<nums.length){
            if(odd%2 != 0 && nums[odd]%2 == 0)
                break;
            odd++;
        }
        
        while(even<nums.length && odd<nums.length){
            int temp = nums[even];
            nums[even] = nums[odd];
            nums[odd] = temp;
            
            while(even<nums.length){
                if(even%2 == 0 && nums[even]%2 != 0)
                    break;
                even++;
            }

            while(odd<nums.length){
                if(odd%2 != 0 && nums[odd]%2 == 0)
                    break;
                odd++;
            }
            
        }

        return nums;
        
    }
}
