class Solution {
    public int removeDuplicates(int[] nums) {

        ArrayList<Integer> uniques = new ArrayList<Integer>();
        int count = 1;
        
        uniques.add(0);
        
        for(int i=1;i<nums.length;i++){
            
            if(nums[i] == nums[i-1])
                continue;
            
            count++;
            uniques.add(i);
        }
        
        for(int i=0;i<uniques.size();i++){
            int temp = nums[uniques.get(i)];
            nums[uniques.get(i)] = nums[i];
            nums[i] = temp;
        }
        
        return count;
    }
}
