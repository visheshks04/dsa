//https://leetcode.com/problems/find-smallest-letter-greater-than-target/submissions/

class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int hi = letters.length-1;
        int lo = 0;
        int mid = lo + (hi-lo)/2;

        while(hi>=lo){
            mid = lo + (hi-lo)/2;

            if(letters[mid] > target){
                    hi = mid-1;
            }

            else{
                    lo = mid+1;
            }
        }

        return letters[(lo)%(letters.length)];
    }
}



/***
 * BINARY SEARCH
 * No equal condition because we want the one that is strictly greater
 * The modulo is because the letters 'wrap around'.
 * /
