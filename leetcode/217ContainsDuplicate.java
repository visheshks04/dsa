class Solution {
    public boolean containsDuplicate(int[] nums) {
        
        HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
        
        for(int i=0;i<nums.length;i++){
            if(freq.containsKey(nums[i]))
                freq.put(nums[i], freq.get(nums[i]) + 1);
            else
                freq.put(nums[i], 1);
        }
        
        for(int i:freq.values()){
            if(i > 1)
                return true;
        }
        
        return false;
    }
}

/*
Approach 1:
    Sort the array
    Duplicates will be found at adjacent posititions
    Iterate over the array doing n-1 comparisons
    If found equal return true
    else return false ultimately
    
    O(nlogn)
    
    
Approach 2:
    Get a Hashmap
    Fill if with frequencies
    If any of the values is !=1 return true
    Else return false, ultimately
*/
