class Solution {
    public int maxArea(int[] height) {
        int head=0, tail=height.length-1;
        int max = Integer.MIN_VALUE;
        while(head < tail){
            if(max < (tail-head)*Math.min(height[head], height[tail]))
                max = (tail-head)*Math.min(height[head], height[tail]);
            
            if(height[tail] < height[head])
                tail--;
            else
                head++;
        }
        
        return max;
    }
}
