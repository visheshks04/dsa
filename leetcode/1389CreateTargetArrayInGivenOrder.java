class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        
        ArrayList<Integer> ans = new ArrayList<Integer>();
        
        for(int i=0;i<nums.length;i++){
            ans.add(index[i], nums[i]);
        }
        
        int[] ansArray = new int[nums.length];
        
        for(int i=0;i<nums.length;i++){
            ansArray[i] = ans.get(i);
        }
        
        return ansArray;
    }
}
