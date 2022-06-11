class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int minDiff = Integer.MAX_VALUE;
        
        for(int i=0;i<arr.length-1;i++){
            if(minDiff > Math.abs(arr[i] - arr[i+1]))
                minDiff = Math.abs(arr[i] - arr[i+1]);
        }
        
        List<List<Integer>> pairs = new ArrayList<List<Integer>>();
        
        for(int i=0;i<arr.length-1;i++){
            if(Math.abs(arr[i] - arr[i+1]) == minDiff){
                ArrayList<Integer> temp = new ArrayList<Integer>();
                temp.add(arr[i]);
                temp.add(arr[i+1]);
                pairs.add(temp);
            }
        }
        
        return pairs;
    }
}
