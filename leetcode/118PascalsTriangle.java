class Solution {
    public List<List<Integer>> generate(int numRows) {
        ArrayList<List<Integer>> triangle = new ArrayList<List<Integer>>();
        ArrayList<Integer> firstRow = new ArrayList<Integer>();
        
        firstRow.add(1);
        triangle.add(firstRow);
        
        for(int i=1;i<numRows;i++){
            ArrayList<Integer> row = new ArrayList<Integer>();
            int lastRowSize = triangle.get(i-1).size();
            
            row.add(1);
            for(int j=0;j<lastRowSize-1;j++){
                row.add(triangle.get(i-1).get(j)+triangle.get(i-1).get(j+1));
            }
            row.add(1);
            triangle.add(row);
        }
        
        return triangle;
    }
}
