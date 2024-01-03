class Solution {

    private static String sortString(String s){
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    } // klogk 

    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> ana = new HashMap<>();
        
        for(String str: strs){ // n
            String sorted = sortString(str); // klogk
            ana.putIfAbsent(sorted, new ArrayList<>());
            ana.get(sorted).add(str);
        }

        List<List<String>> result = new ArrayList<>();

        for(Map.Entry<String, List<String>> entry: ana.entrySet()){
            result.add(entry.getValue());
        }

        return result;
    }
}



/*
 The approach here would be to have a hashmap with key as the sorted string, whichever comes, and the value would be an array that contains all the anagrams, whichever comes

Time: n*klogk where n is 10^4 max and k is 10^2
 * */
