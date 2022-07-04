class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        
        HashMap<Character, Integer> ransomNoteFreq = new HashMap<>();
        int rLen = ransomNote.length();
        
        // Getting frequencies for ransomNote string
        for(int i=0;i<rLen;i++){
            if(ransomNoteFreq.containsKey(ransomNote.charAt(i)))
                ransomNoteFreq.put(ransomNote.charAt(i), ransomNoteFreq.get(ransomNote.charAt(i))+1);
            else
                ransomNoteFreq.put(ransomNote.charAt(i), 1);
        }
        
        HashMap<Character, Integer> magazineFreq = new HashMap<>();
        int mLen = magazine.length();
        
        // Getting frequencies for ransomNote string
        for(int i=0;i<mLen;i++){
            if(magazineFreq.containsKey(magazine.charAt(i)))
                magazineFreq.put(magazine.charAt(i), magazineFreq.get(magazine.charAt(i))+1);
            else
                magazineFreq.put(magazine.charAt(i), 1);
        }
        
        
        // Now check if any ransomNoteFreq entry is greater than magazineFreq
        for(Map.Entry entry:ransomNoteFreq.entrySet()){
            
            if(!magazineFreq.containsKey((char)entry.getKey())) // check for if key is not present in magazine
                return false;
            
            else if((int)entry.getValue() > magazineFreq.get((char)entry.getKey()))
                return false;
        }
        
        return true;
    }
}
