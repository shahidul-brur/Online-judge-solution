// Accepted

#include <stdio.h>
#include <string.h>

int main()
{
    freopen("12662.txt", "r", stdin);
    int students, query, i, left, right, leftDis, rightDis, j, position, L, R, M;
    char studentsName[103][5];
    scanf("%d", &students);
    for(i=1;i<=students;i++)
        scanf("%s", studentsName[i]);
    scanf("%d", &query);
    while(query--)
    {
        scanf("%d", &position);
        if(studentsName[position][0]!='?')
            printf("%s\n", studentsName[position]);
        else
        {
            left = L = R = M = right = leftDis = rightDis = 0;
            for(i=position-1;i>=1;i--)
            {
                leftDis++;
                if(studentsName[i][0]!='?')
                {
                    left=i;
                    break;
                }
            }

            for(i=position+1;i<=students;i++)
            {
                rightDis++;
                if(studentsName[i][0]!='?')
                {
                    right=i;
                    break;
                }
            }
            if(left==0)
                L=1;
            else if(right==0)
                R=1;
            else
            {
                if(leftDis < rightDis)
                    R=1;
                else if(rightDis < leftDis)
                    L=1;
                else if(leftDis == rightDis)
                    M=1;
            }

            if(L == 1)
            {
                for(i=1;i<=rightDis;i++)
                    printf("left of ");
                printf("%s\n", studentsName[right]);
            }
            else if(R == 1)
            {
                for(i=1;i<=leftDis;i++)
                    printf("right of ");
                printf("%s\n", studentsName[left]);
            }
            else if(M == 1)
                printf("middle of %s and %s\n", studentsName[left], studentsName[right]);
        }
    }
    return 0;
}
