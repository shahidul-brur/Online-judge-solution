int solution(int A, int B, int K) {
   int lft = 0;
   if (A>0) lft = (A-1)/K + 1;
   int rgt = B/K + 1 ;
   return rgt-lft;
}
