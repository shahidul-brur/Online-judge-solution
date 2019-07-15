class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> a(n,0);
        //memset(a,0, sizeof(a));
        for(auto x:bookings){
            a[x[0]-1]+=x[2]; if(x[1]!=n) a[x[1]]-=x[2];
            }
        for(int i=1;i<n;i++){ a[i]+=a[i-1];
                              }
        return a;
    }
};
