class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        HashSet set = new HashSet();
        for(String w:words)
        {
            String s="";
            int len = w.length();
            for(int j = 0;j<len;j++)
            {
                int i = w.charAt(j) - 'a';
                s+=code[i];
            }
            set.add(s);
        }
        int tot = set.size();
        return tot;
    }
}
