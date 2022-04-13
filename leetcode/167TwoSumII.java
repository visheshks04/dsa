class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int head, tail;
        int[] result = new int[2];
        
        head = 0;
        tail = numbers.length - 1;
        
        while(tail > head){
            if(numbers[head] + numbers[tail] == target){
                result[0] = head+1;
                result[1] = tail+1;
                
                break;            
            }
            
            else if(numbers[head] + numbers[tail] > target)
                tail --;
            
            else
                head ++;
        }
        
        return result;
    }
}
