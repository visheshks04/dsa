class Solution {
    public int longestPalindrome(String s) {
        HashMap<Character, Integer> freq = new HashMap<>();
        int n = s.length();
        
        for(int i=0;i<n;i++){
            if(freq.containsKey(s.charAt(i))){
                freq.put(s.charAt(i), freq.get(s.charAt(i))+1);
            }
            else{
                freq.put(s.charAt(i), 1);
            }
        }
        
        boolean containsOdd = false;
        int sum = 0;
        
        for(Map.Entry entry:freq.entrySet()){
            if(((int)entry.getValue()) %2 != 0)
                containsOdd = true;
            sum += ((int)entry.getValue())/2;
        }
        
        sum *= 2;
        
        if(containsOdd)
            sum++;
        
        return sum;
    }
}
