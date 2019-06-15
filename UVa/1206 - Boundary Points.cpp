#include<bits/stdc++.h>
using namespace std;
#define eps 1e-4
int n;
char s[2000005];
struct Point
{
  double x, y;
};
Point points[1000005];
Point reff;
int orientation(Point p, Point q, Point r)
{
    double val1 = (q.y - p.y) * (r.x - q.x);
    double val2 =  (q.x - p.x) * (r.y - q.y);

    if (fabs(val1 - val2) < eps ) 
        return 0;  // collinear
    return (val1 > val2+eps)? 1: 2; // 1=clock, 2=counter clock
}
double dist(Point p1, Point p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}
Point nextToTop(stack<Point> &S)
{
    Point top = S.top();
    S.pop();
    Point p=S.top();
    S.push(top);
    return p;
}
int cmp(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;
 
   int o = orientation(reff, *p1, *p2);
   if (o == 0)
     return (dist(reff, *p2) + eps < dist(reff, *p1))? 1 : -1;
 
   return (o == 2)? -1: 1;
}
void printConvexHull()
{
    long long m = 1;
    
    for(long long i=1;i<n;i++)
    {
        while(i<n-1 && orientation(reff, points[i], points[i+1])==0)
            i++;
        points[m++] = points[i];
    }
    
    stack<Point> S;
    
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
    
    for(long long i=3;i<m;i++)
    {
        while(i<m && orientation(nextToTop(S), S.top(), points[i])!=2)
            S.pop();
        S.push(points[i]);
    }
    
    cout << "(" << reff.x << "," << reff.y << ")";
    
    while(!S.empty())
    {
        Point p = S.top();
        S.pop();
        printf(" (%g,%g)", p.x, p.y);
    }
    cout << "\n";
}
int main()
{
    //freopen("in.txt", "r", stdin);
    long long i, len, neg;
    double x, y;
    while(gets(s))
    {
        n=0;
        len = strlen(s);
        for(i=1;i<len;)
        {
            neg=0;
            x = 0.0;
            if(s[i]=='-')
                i++, neg=1;
            double d=1.0;
            while(s[i]!=',')
            {
                if(s[i]=='.')
                {
                    i++;
                    double fp = 0.0;
                    while(s[i]!=',')
                    {
                        d*=10.0;
                        fp = fp*10.0 + (s[i] - '0');
                        i++;
                    }
                    x += fp/d;
                }
                else
                {
                    x = x*10.0 + s[i] - '0';
                    i++;
                }
            }
            if(neg==1)
                x*=-1.0;
            
            neg = 0;
            y=0.0;
            ++i;
            
            if(s[i]=='-')
                i++, neg=1;
            d = 1.0;
            while(s[i]!=')')
            {
                if(s[i]=='.')
                {
                    i++;
                    double fp = 0.0;
                    while(s[i]!=')')
                    {
                        d*=10.0;
                        fp = fp*10.0 + (s[i] - '0');
                        i++;
                    }
                    y += fp/d;
                    //cout << x << "\n";
                }
                else
                {
                    y = y*10 + s[i] - '0';
                    i++;
                }
            }
            if(neg)
                y*=-1.0;
            
            i+=3;
            points[n].x=x;
            points[n++].y=y;
        }
        
        
        double ymin = points[0].y;
        long minInd=0;
        
        for(i=1;i<n;i++)
        {
            if(points[i].y+eps<ymin|| (fabs(ymin - y)<eps && points[i].x+eps < points[minInd].x))
            {
                ymin = points[i].y;
                minInd = i;
            }
        }
        
        
        Point temp = points[0];
        points[0] = points[minInd];
        points[minInd] = temp;
        
        reff = points[0];
        
        qsort(&points[1], n-1, sizeof(Point), cmp);
        
        printConvexHull();
    }
    return 0;
}