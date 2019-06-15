//Accepted

#include <stdio.h>
#include <string.h>
int convertToUtc(int time, char *from)
{
    if(strcmp(from, "UTC")==0);
    else if(strcmp(from, "GMT")==0);
    else if(strcmp(from, "BST")==0)
        time-=60;
    else if(strcmp(from, "IST")==0)
        time-=60;
    else if(strcmp(from, "WET")==0);
    else if(strcmp(from, "WEST")==0)
        time-=60;
    else if(strcmp(from, "CET")==0)
        time-=60;
    else if(strcmp(from, "CEST")==0)
        time-=120;
    else if(strcmp(from, "EET")==0)
        time-=120;
    else if(strcmp(from, "EEST")==0)
        time-=180;
    else if(strcmp(from, "MSK")==0)
        time-=180;
    else if(strcmp(from, "MSD")==0)
        time-=240;
    else if(strcmp(from, "AST")==0)
        time+=240;
    else if(strcmp(from, "ADT")==0)
        time+=180;
    else if(strcmp(from, "NST")==0)
        time+=210;
    else if(strcmp(from, "NDT")==0)
        time+=150;
    else if(strcmp(from, "EST")==0)
        time+=300;
    else if(strcmp(from, "EDT")==0)
        time+=240;
    else if(strcmp(from, "CST")==0)
        time+=360;
    else if(strcmp(from, "CDT")==0)
        time+=300;
    else if(strcmp(from, "MST")==0)
        time+=420;
    else if(strcmp(from, "MDT")==0)
        time+=360;
    else if(strcmp(from, "PST")==0)
        time+=480;
    else if(strcmp(from, "PDT")==0)
        time+=420;
    else if(strcmp(from, "HST")==0)
        time+=600;
    else if(strcmp(from, "AKST")==0)
        time+=540;
    else if(strcmp(from, "AKDT")==0)
        time+=480;
    else if(strcmp(from, "AEST")==0)
        time-=600;
    else if(strcmp(from, "AEDT")==0)
        time-=660;
    else if(strcmp(from, "ACST")==0)
        time-=570;
    else if(strcmp(from, "ACDT")==0)
        time-=630;
    else if(strcmp(from, "AWST")==0)
        time-=480;

    return time;
}

int convertFromUtc(int time, char *from)
{
    if(strcmp(from, "UTC")==0);
    else if(strcmp(from, "GMT")==0);
    else if(strcmp(from, "BST")==0)
        time+=60;
    else if(strcmp(from, "IST")==0)
        time+=60;
    else if(strcmp(from, "WET")==0);
    else if(strcmp(from, "WEST")==0)
        time+=60;
    else if(strcmp(from, "CET")==0)
        time+=60;
    else if(strcmp(from, "CEST")==0)
        time+=120;
    else if(strcmp(from, "EET")==0)
        time+=120;
    else if(strcmp(from, "EEST")==0)
        time+=180;
    else if(strcmp(from, "MSK")==0)
        time+=180;
    else if(strcmp(from, "MSD")==0)
        time+=240;
    else if(strcmp(from, "AST")==0)
        time-=240;
    else if(strcmp(from, "ADT")==0)
        time-=180;
    else if(strcmp(from, "NST")==0)
        time-=210;
    else if(strcmp(from, "NDT")==0)
        time-=150;
    else if(strcmp(from, "EST")==0)
        time-=300;
    else if(strcmp(from, "EDT")==0)
        time-=240;
    else if(strcmp(from, "CST")==0)
        time-=360;
    else if(strcmp(from, "CDT")==0)
        time-=300;
    else if(strcmp(from, "MST")==0)
        time-=420;
    else if(strcmp(from, "MDT")==0)
        time-=360;
    else if(strcmp(from, "PST")==0)
        time-=480;
    else if(strcmp(from, "PDT")==0)
        time-=420;
    else if(strcmp(from, "HST")==0)
        time-=600;
    else if(strcmp(from, "AKST")==0)
        time-=540;
    else if(strcmp(from, "AKDT")==0)
        time-=480;
    else if(strcmp(from, "AEST")==0)
        time+=600;
    else if(strcmp(from, "AEDT")==0)
        time+=660;
    else if(strcmp(from, "ACST")==0)
        time+=570;
    else if(strcmp(from, "ACDT")==0)
        time+=630;
    else if(strcmp(from, "AWST")==0)
        time+=480;

    return time;
}

int main()
{
    freopen("10371.txt", "r", stdin);
    freopen("10371.out", "w", stdout);
    int t, c, H,M,h,m,i,utc,ans,given;
    char timeStr[15], format[5], from[8], to[8];
    scanf("%d", &t);
    for(c=1;c<=t;c++)
    {
        scanf("%s", timeStr);
        if(strcmp(timeStr, "noon")==0)
        {
            H=12;
            M=0;
        }
        else if(strcmp(timeStr, "midnight")==0)
        {
            H=0;
            M=0;
        }
        else
        {
            i=0;
            H=(timeStr[i]-'0');
            if(timeStr[i+1]!=':')
            {
                H=H*10+timeStr[i+1]-'0';
                i++;
            }
            M=(timeStr[i+2]-'0')*10+timeStr[i+3]-'0';
            scanf("%s", format);
            if(strcmp(format, "p.m.")==0)
                H=12+(H%12);
            else if(strcmp(format, "a.m.")==0)
            {
                if(H==12)
                    H=0;
            }
        }
        H+=24;
        scanf("%s", from);
        scanf("%s", to);

        given=H*60+M;
        utc=convertToUtc(given, from);
        ans=convertFromUtc(utc, to);
        h=ans/60;

        m=ans%60;
        h=h%24;

        if(h==0 && m==0)
            printf("midnight\n");
        else if(h==12 && m==0)
            printf("noon\n");
        else if(h>=12)
        {
            h-=12;
            if(h==0)
                h=12;
            printf("%d:%02d p.m.\n", h, m);
        }
        else if(h<12)
        {
            if(h==0)
                h=12;
            printf("%d:%02d a.m.\n", h, m);
        }
    }
    return 0;
}
