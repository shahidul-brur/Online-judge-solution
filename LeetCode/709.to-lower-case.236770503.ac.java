class Solution {
    public String toLowerCase(String str) {
        StringBuilder sb = new StringBuilder();
        int n=str.length();
        for(int i=0;i<n;i++) if(str.charAt(i)>='A' && str.charAt(i)<='Z')
            sb.append((char)(str.charAt(i)-'A'+'a'));
        else sb.append(str.charAt(i));
        return sb.toString();
    }
}
