class Solution {
    public int oddCells(int m, int n, int[][] indices){
        HashMap<Integer, Integer> rows = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> columns = new HashMap<Integer, Integer>();

        for(int i=0;i<indices.length;i++){
            if(rows.containsKey(indices[i][0]))
                rows.put(indices[i][0], rows.get(indices[i][0])+1);
            else
                rows.put(indices[i][0], 1);

            if(columns.containsKey(indices[i][1]))
                columns.put(indices[i][1], columns.get(indices[i][1])+1);
            else
                columns.put(indices[i][1], 1);
        }
        
        int count = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int value = 0;
                if(rows.containsKey(i)){
                    value += rows.get(i);
                }
                if(columns.containsKey(j)){
                    value+= columns.get(j);
                }
                
                if(value%2 != 0)
                    count++;
            }
        }

        return count;
    }
}

//This is O(m*n + L)
//There exists another O(m+n+L) solution using Boolean arrays
//And a O(L) solution using BitSet, check discussion most voted top comment
