import java.util.Arrays;

public class MatSearch{
	static int[] search(int[][] matrix, int target){
		int row = 0;
		int col = matrix.length - 1;

		while(row < matrix.length-1 && col >= 0){
			
			if(matrix[row][col] == target){
				return new int[]{row, col};
			}

			else if(matrix[row][col] > target){
				col--;
			}

			else{
				row++;
			}
		}

		return new int[] {-1,-1};
	}

	public static void main(String args[]){
		int ar[][] = {
			{1,2,3},
			{4,5,6},
			{7,8,9},
		};

		int target = 6;

		System.out.println(Arrays.toString(search(ar, target)));
	}
}	
