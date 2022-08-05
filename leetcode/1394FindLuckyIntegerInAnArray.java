class Solution {
    public int findLucky(int[] arr) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        
        for(int i=0;i<arr.length;i++){
            if(freq.containsKey(arr[i]))
                freq.put(arr[i], freq.get(arr[i])+1);
            else
                freq.put(arr[i], 1);
        }
        
        int max = Integer.MIN_VALUE;
        boolean exists = false;
        
        for(Map.Entry entry:freq.entrySet()){
            if(entry.getKey() == entry.getValue()){
                if(max < (int)entry.getKey())
                    max = (int)entry.getKey();
                exists = true;
            }
        }
        
        if(!exists)
            return -1;
        
        return max;
    }
}
