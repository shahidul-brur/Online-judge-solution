 #include <stdio.h>
  #include <string.h>
 int main()
 {
     int n ,k ,i;
     char ch[110] ;
     while(scanf("%d %d",&n,&k)==2)
     {
         scanf("%s",ch) ;
         if(k == n)
         {
             printf("PRINT %c\n",ch[n-1]) ;
             for(i = n-2 ; i >= 0 ; i--)
             {
                 printf("LEFT\n") ;
                 printf("PRINT %c\n",ch[i]) ;
             }
         }
         else if(k == 1)
         {
             printf("PRINT %c\n",ch[0]) ;
             for(i = 1 ; i < n ; i++)
             {
                 printf("RIGHT\n") ;
                 printf("PRINT %c\n",ch[i]) ;
             }
         }
        else
         {
             if(n-k <= k-1)
             {
                 for(i = k+1 ; i <= n ; i++)
                     printf("RIGHT\n") ;
                 printf("PRINT %c\n",ch[n-1]) ;
                 for(i = n-2 ; i >= 0 ; i --)
                 {
                     printf("LEFT\n") ;
                     printf("PRINT %c\n",ch[i]) ;
                }
             }
             else
             {
                 for(i = 1 ; i < k ; i++)
                     printf("LEFT\n") ;
                 printf("PRINT %c\n",ch[0]) ;
                 for(i = 1 ; i < n ; i++)
                 {
                    printf("RIGHT\n") ;
                    printf("PRINT %c\n",ch[i]) ;
                }
            }
        }
     }
     return 0 ;
 }