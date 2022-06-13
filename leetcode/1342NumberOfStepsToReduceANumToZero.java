class Solution {
    public int numberOfSteps(int num) {
        return n_steps(num, 0);
    }
    
    public static int n_steps(int num, int count){
        if(num == 0)
            return count;
        else if(num%2 == 0)
            return n_steps(num/2, count+1);
        else
            return n_steps(num-1, count+1);
    }
}
