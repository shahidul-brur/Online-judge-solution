//Accepted
#include<stdio.h>
#include<math.h>
#define MAX 10005
void mergeSort(double arr[],int low,int mid,int high);
void part(double arr[],int low,int high);

int main()
{
    freopen("11579.txt", "r", stdin);
    int t,n,i,j,found;
    double L[MAX],tmp,s,a,maxi;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lf",&L[i]);
        }

        part(L,0,n-1);
        found=0;
        maxi=0;
        for(i=n-1;i>=2;i--)
        {
            if(L[i-1]+L[i-2]>L[i])
            {
                s=(L[i-1]+L[i-2]+L[i])/2.0;
                a=sqrt(s)*sqrt(s-L[i])*sqrt(s-L[i-1])*sqrt(s-L[i-2]);
                found=1;
                if(a>maxi)
                    maxi=a;
            }

        }
        if(found==1)
            printf("%.2lf\n",maxi);
        else
            printf("0.00\n");

    }
    return 0;
}
void part(double arr[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        part(arr,low,mid);
        part(arr,mid+1,high);
        mergeSort(arr,low,mid,high);
    }
}
void mergeSort(double arr[],int low,int mid,int high)
{
    int i,m,k,l;
    double temp[MAX];
    l=low;
    i=low;
    m=mid+1;
    while((l<=mid)&&(m<=high))
    {
        if(arr[l]<=arr[m])
        {
            temp[i]=arr[l];
            l++;
        }
        else
        {
            temp[i]=arr[m];
            m++;
        }
        i++;
    }
    if(l>mid)
    {
        for(k=m;k<=high;k++)
        {
            temp[i]=arr[k];
            i++;
        }
    }
    else
    {
        for(k=l;k<=mid;k++)
        {
            temp[i]=arr[k];
            i++;
        }
    }
    for(k=low;k<=high;k++)
    {
        arr[k]=temp[k];
    }
}
