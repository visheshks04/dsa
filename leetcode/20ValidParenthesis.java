class Solution {
    
    private boolean bracketsPairUp(char a, char b){
        if(a == '[' && b == ']')
            return true;
        else if(a == '(' && b == ')')
            return true;
        else if(a == '{' && b == '}')
            return true;
        
        return false;
    }
    
    public boolean isValid(String s) {
        Stack<Character> stk = new Stack<>();
        int n = s.length();
        
        for(int i=0;i<n;i++){
            if(s.charAt(i) == '[' || s.charAt(i) == '(' || s.charAt(i) == '{')
                stk.push(s.charAt(i));
            else{
                if(stk.size() == 0)
                    return false;
                else if(bracketsPairUp(stk.peek(), s.charAt(i)))
                    stk.pop();
                else
                    return false;
            }
        }
        
        if(stk.size() > 0)
            return false;
        
        return true;
    }
}
