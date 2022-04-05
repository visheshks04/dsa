import java.util.Arrays;

public class StrictlySortedMatSearch{
	public static void main(String args[]){
		int[][] ar = {
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12},
			{13,14,15,16},
		};

		int target = 10;

		System.out.println(Arrays.toString(search(ar, target)));
	}

	// Approach would be to first find the ceiling along the rows in column 0
	// Then apply binary search again in that row
	static int[] search(int[][] matrix, int target){
		int hi = matrix.length-1;
		int lo = 0;
		int mid;

		while(hi>=lo){
			mid = lo + (hi-lo)/2;

			if(matrix[mid][0] == target){
				return new int[] {mid, 0};
			}

			else if(matrix[mid][0] > target){
				hi = mid - 1;
			}

			else{
				lo = mid + 1;
			}
		}

		int floor = hi;

		hi = matrix.length - 1;
		lo = 0;

		while(hi>lo){
			mid = lo + (hi-lo)/2;

			if(matrix[floor][mid] == target){
				return new int[] {floor, mid};
			}

			else if(matrix[floor][mid] > target){
				hi = mid-1;
			}

			else{
				lo = mid+1;
			}
		}

		return new int[] {-1,-1};
	}
}
