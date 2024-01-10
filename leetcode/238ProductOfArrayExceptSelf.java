class Solution {
    public int[] productExceptSelf(int[] nums) {
        boolean oneZeroPresent = false;
        boolean zeroResult = false;

        int product = 1;

        for (int i=0; i<nums.length; i++){
            if (nums[i] == 0){
                if (!oneZeroPresent) oneZeroPresent = true;
                else zeroResult = true;
            }
            if(zeroResult) break;

            if(nums[i] != 0) product *= nums[i];
        }

        int[] result = new int[nums.length];

        if (zeroResult){
            Arrays.fill(result, 0);
            return result;
        } 

        for(int i=0; i<nums.length; i++){
            if (nums[i] == 0) result[i] = product;
            else if (oneZeroPresent) result[i] = 0;
            else result[i] = product / nums[i];
        }

        return result;
    }
}
