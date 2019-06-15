//Accepted
#include <stdio.h>
int main()
{
    freopen("10894.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, L, i, j, k;
    while(scanf("%d", &N)!=EOF)
    {
        if(N==0)
            break;
        L=N;
        if(L<0) L=0-L;

        if(N>0)
        {
            /* ************** row 1 ************************** */

            for(j=1;j<=L;j++)
            {

            // S
            for(i=1;i<=5*L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // A
            for(i=1;i<=L;i++)
                printf(".");
            for(i=1;i<=3*L;i++)
                printf("*");
            for(i=1;i<=L;i++)
                printf(".");
            for(i=1;i<=L;i++)
            printf(".");

            // V
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=3*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // E
            for(i=1;i<=5*L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf("...");

            // H
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=3*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // R
            for(i=1;i<=5*L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // I
            for(i=1;i<=5*L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");


            // D
            for(i=1;i<=3*L;i++)
                printf("*");
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
            printf(".");

            // O
            for(i=1;i<=5*L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // Y
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=3*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");

            printf("\n");
            }
    /* ************** row 2 ******************************** */

            for(j=1;j<=L;j++)
            {
            // S
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=4*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
            printf(".");

            // A
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=3*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // V
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=3*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // E
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=4*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
            printf("...");

            // H
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=3*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // R
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=3*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // I
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
            printf(".");


            // D
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
                printf(".");
            for(i=1;i<=L;i++)
            printf(".");

            // O
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=3*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // Y
            for(i=1;i<=L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
                printf(".");
            printf("\n");
            }
    /* ************** row 3 ********************************* */
            for(j=1;j<=L;j++)
            {
            // S
            for(i=1;i<=5*L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // A
            for(i=1;i<=5*L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // V
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=3*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // E
            for(i=1;i<=3*L;i++)
                printf("*");
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
            printf("...");

            // H
            for(i=1;i<=5*L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // R
            for(i=1;i<=5*L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // I
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
            printf(".");


            // D
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=3*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // O
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=3*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // Y
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=2*L;i++)
                printf(".");

            printf("\n");
            }
        /* ************** row 4 ************************** */
            for(j=1;j<=L;j++)
            {
            // S
            for(i=1;i<=4*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // A
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=3*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // V
            for(i=1;i<=L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
                printf(".");
            for(i=1;i<=L;i++)
            printf(".");

            // E
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=4*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
            printf("...");

            // H
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=3*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // R
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
            printf(".");

            // I
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
            printf(".");


            // D
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
                printf(".");
            for(i=1;i<=L;i++)
            printf(".");

            // O
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=3*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
            printf(".");

            // Y
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=2*L;i++)
                printf(".");

            printf("\n");
            }
    /* ************** row 5 ******************************** */
            for(j=1;j<=L;j++)
            {
            // S
            for(i=1;i<=5*L;i++)
                printf("*");
            for(i=1;i<=L;i++)
                printf(".");

            // A
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=3*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
                printf(".");

            // V
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf(".");

            // E
            for(i=1;i<=5*L;i++)
                printf("*");
            for(i=1;i<=L;i++)
                printf("...");

            // H
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=3*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=L;i++)
                printf(".");

            // R
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=2*L;i++)
                printf("*");
            for(i=1;i<=L;i++)
                printf(".");

            // I
            for(i=1;i<=5*L;i++)
                printf("*");
            for(i=1;i<=L;i++)
                printf(".");


            // D
            for(i=1;i<=3*L;i++)
                printf("*");
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf(".");

            // O
            for(i=1;i<=5*L;i++)
                printf("*");
            for(i=1;i<=L;i++)
                printf(".");

            // Y
            for(i=1;i<=2*L;i++)
                printf(".");
            for(i=1;i<=L;i++)
                printf("*");
            for(i=1;i<=2*L;i++)
                printf(".");

            printf("\n");
            }
        }
        else
        {
        /* *********************** S ****************************** */
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                    printf("*");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=4*L;i++)
                    printf(".");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                    printf("*");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=4*L;i++)
                printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                    printf("*");
                printf("\n");
            }
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                    printf(".");
                printf("\n");
            }

        /* *********************** A ****************************** */
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf(".");
                for(i=1;i<=3*L;i++)
                    printf("*");
                for(i=1;i<=L;i++)
                    printf(".");
                printf("\n");
            }


            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=3*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                printf("\n");
            }


            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                    printf("*");
                printf("\n");
            }


            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=3*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                printf("\n");
            }


           for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                printf("*");
                for(i=1;i<=3*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                printf("\n");
            }
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                printf(".");
            printf("\n");
            }
        /* *********************** V ****************************** */
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=3*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=3*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                printf("\n");
            }


            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=3*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                printf("\n");
            }


            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=L;i++)
                    printf(".");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=2*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=2*L;i++)
                    printf(".");
                printf("\n");
            }
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                printf(".");
            printf("\n");
            }
        /* *********************** E ****************************** */
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                    printf("*");
                printf("\n");
            }


            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=4*L;i++)
                    printf(".");
                printf("\n");
            }


            for(j=1;j<=L;j++)
            {
                for(i=1;i<=3*L;i++)
                    printf("*");
                for(i=1;i<=2*L;i++)
                    printf(".");
                printf("\n");
            }


            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=4*L;i++)
                    printf(".");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                    printf("*");
                printf("\n");
            }

            for(j=1;j<=3*L;j++)
            {
                for(i=1;i<=5*L;i++)
                    printf(".");
                printf("\n");
            }
        /* *********************** H ****************************** */
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=3*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                printf("\n");
            }


            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=3*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                printf("\n");
            }


           for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                    printf("*");
                printf("\n");
            }


            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=3*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                printf("\n");
            }


            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=3*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                printf("\n");
            }
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                printf(".");
            printf("\n");
            }
        /* *********************** R ****************************** */
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                    printf("*");
                printf("\n");
            }

           for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=3*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                printf("\n");
            }


           for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                    printf("*");
                printf("\n");
            }


            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=2*L;i++)
                    printf(".");
                printf("\n");
            }

           for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=2*L;i++)
                    printf(".");
                for(i=1;i<=2*L;i++)
                    printf("*");
                printf("\n");
            }
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                printf(".");
            printf("\n");
            }
        /* *********************** I ****************************** */
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                    printf("*");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=2*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=2*L;i++)
                    printf(".");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=2*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=2*L;i++)
                    printf(".");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=2*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=2*L;i++)
                    printf(".");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                    printf("*");
                printf("\n");
            }
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                printf(".");
            printf("\n");
            }
        /* *********************** D ****************************** */
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=3*L;i++)
                    printf("*");
                for(i=1;i<=2*L;i++)
                    printf(".");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=2*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=L;i++)
                    printf(".");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=3*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=2*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=L;i++)
                    printf(".");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=3*L;i++)
                    printf("*");
                for(i=1;i<=2*L;i++)
                    printf(".");
                printf("\n");
            }
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                printf(".");
            printf("\n");
            }
        /* *********************** O ****************************** */
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                    printf("*");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=3*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=3*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=3*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                    printf("*");
                printf("\n");
            }
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=5*L;i++)
                printf(".");
            printf("\n");
            }
        /* *********************** Y ****************************** */
            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=3*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=L;i++)
                    printf(".");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=2*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=2*L;i++)
                    printf(".");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=2*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=2*L;i++)
                    printf(".");
                printf("\n");
            }

            for(j=1;j<=L;j++)
            {
                for(i=1;i<=2*L;i++)
                    printf(".");
                for(i=1;i<=L;i++)
                    printf("*");
                for(i=1;i<=2*L;i++)
                    printf(".");
                printf("\n");
            }
        }
        printf("\n\n");
    }
    return 0;
}
