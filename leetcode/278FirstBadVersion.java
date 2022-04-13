/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int hi = n;
        int lo = 1;
        int mid;
        
        while(hi >= lo){
            mid = lo + (hi-lo)/2;
            
            if(isBadVersion(mid) && !isBadVersion(mid-1))
                return mid;
            
            else if(isBadVersion(mid))
                hi = mid-1;
            
            else
                lo = mid+1;
        }
        return 1;
    }
}
