class Solution {
public:
    int numberOfDays(int y, int m) {
        int leap = (y%400==0 || (y%4==0 && y%100!=0));
        int d[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(m==2){
            if(leap) return 29;
            else return 28;
        }
        return d[m];
    }
};
