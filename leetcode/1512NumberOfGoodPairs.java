class Solution {
    
	public static void main(String args[]){
		int[] nums = {1,2,3,1,1,3};
		System.out.println(numIdenticalPairs(nums));
	}

	public static int numIdenticalPairs(int[] nums) {
        	HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
        	for(int i=0; i<nums.length;i++){
			if(freq.containsKey(nums[i])){
				freq.put(nums[i], freq.get(nums[i]) + 1);
			}

			else{
				freq.put(nums[i], 1);
			}
		}

		int sum = 0;
        
		for(int i:freq.values()){
			sum += i*(i-1)/2;
		}

		return sum;
    }
}

/*
Approach 1:
    Two Nested loops brute force, time O(n^2)
    
    
Approach 2:

[1 2 3 1 1 3]

Make a hashmap for freq of all values
{
    1: 3, // 3(2)/2 = 3
    2: 1, // 1(0)/2 = 0
    3: 2, // 2(1)/2 = 1
}

Result = Sum of values = 4

time O(n)
*/
