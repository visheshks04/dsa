class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character, Integer> sFreq = new HashMap<>();
        int rLen = s.length();
        
        // Getting frequencies for s string
        for(int i=0;i<rLen;i++){
            if(sFreq.containsKey(s.charAt(i)))
                sFreq.put(s.charAt(i), sFreq.get(s.charAt(i))+1);
            else
                sFreq.put(s.charAt(i), 1);
        }
        
        HashMap<Character, Integer> tFreq = new HashMap<>();
        int mLen = t.length();
        
        // Getting frequencies for t string
        for(int i=0;i<mLen;i++){
            if(tFreq.containsKey(t.charAt(i)))
                tFreq.put(t.charAt(i), tFreq.get(t.charAt(i))+1);
            else
                tFreq.put(t.charAt(i), 1);
        }
        
        
        // Now check if any sFreq entry is greater than tFreq
        for(Map.Entry entry:sFreq.entrySet()){
            
            if(!tFreq.containsKey((char)entry.getKey())) // check for if key is not present in magazine
                return false;
            
            else if((int)entry.getValue() != tFreq.get((char)entry.getKey()))
                return false;
        }
        
        return true;
    }
}
