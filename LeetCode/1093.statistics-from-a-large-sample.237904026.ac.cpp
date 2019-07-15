class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double sum = 0.0;
        vector<int> val;
        int mx = -1, mini = -1, mode, n = count.size(), most = 0, ocr = 0;
        for (int i=0;i<n;i++){
            if(count[i]>0) {
                if(mini==-1) mini = i;
                mx = i;
                val.push_back(i);
                ocr+=count[i];
                sum+=i*count[i];
            if(count[i]>most) mode = i, most=count[i];
            }
        }
        n = val.size();
        double avg = (sum*1.0)/(1.0*ocr);
        double median = 1.0*val[n/2]/1.0;
        int tot = 0;
        for(int i=0;i<n;i++){
            tot+=count[val[i]];
            if(tot>=(ocr+1)/2){
                //cout << i << ": " << val[i] << "\n";
                if(ocr%2==1) median = val[i]*1.0;
                else {
                    if(tot>(ocr+1)/2) median = val[i]*1.0;
                    else median = (val[i]+val[i+1])*1.0/2.0;
                    
                }
                break;
            }
        }
        vector<double> v;
        v.push_back(mini*1.0);
        v.push_back(mx*1.0);
        v.push_back(avg*1.0);
        v.push_back(median*1.0);
        v.push_back(mode*1.0);
        return v;
    }
};
