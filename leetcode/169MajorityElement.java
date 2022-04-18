class Solution {
    public int majorityElement(int[] nums) {
        
        HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
        
        for(int i=0;i<nums.length;i++){
            if(freq.containsKey(nums[i])){
                freq.put(nums[i], freq.get(nums[i]) + 1);
            }
            else{
                freq.put(nums[i], 1);
            }
        }
        
        int max_val = Collections.max(freq.values());
        
        for(int i:freq.keySet()){
            if(freq.get(i) == max_val)
                return i;
        }
        
        return 1;
    }
}


/*
Approach 1:
    Sort the array
    go to the mid
    majority element will cover atleast either from 0-n/2 or n/2-n
    
    O(nlogn) time and O(1) space
    
    
Approach 2:
    Store the elements against the frequency in a hashmap
    fetch the maximum
    
    O(n) but space will be O(n)
*/
