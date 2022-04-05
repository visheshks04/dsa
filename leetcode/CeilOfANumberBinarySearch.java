import java.util.Scanner;

public class CeilOfANumberBinarySearch{

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");

        int n = sc.nextInt();
        int[] ar = new int[n];
        
        System.out.print("Enter the array: ");

        for(int i=0;i<ar.length;i++){
            ar[i] = sc.nextInt();
        }
        
        System.err.print("Enter the target: ");
        int target = sc.nextInt();

        int ceil = ceil_value(ar, target);
        int floor = floor_value(ar, target);
        System.out.println("Ceil: " + ceil);
        System.out.println("Floor: " + floor);
    }

    // Smallest number greater than or equal to target
    static int ceil_value(int[] ar, int target){
	int hi=ar.length-1, lo = 0, mid=lo+(hi-lo)/2;

	while(hi>lo){
		mid = lo + (hi-lo)/2;

	 	if(ar[mid] == target){
			return mid;
		}

		else if(ar[mid] > target){
			hi = mid-1;
		}

		else{
			lo = mid+1;
		}
	}
	return lo;
    }

    // Largest number smaller than or equal to target
    static int floor_value(int[] ar, int target){
	int hi = ar.length-1, lo = 0, mid = lo+(hi-lo)/2;

	while(hi>lo){
		mid = lo + (hi-lo)/2;

		if(ar[mid] == target){
			return mid;
		}

		else if(ar[mid] > target){
			hi = mid-1;
		}

		else{
			lo = mid+1;
		}
	}
	return hi;
    }
}
