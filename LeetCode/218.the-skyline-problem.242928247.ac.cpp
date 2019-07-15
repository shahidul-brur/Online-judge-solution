/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

class Solution {
public:
    int n;
    vector<int> tree,lazy;
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int> > ans;
        n = buildings.size();
        if(n==0) return ans;
        vector<pair<int,int>> val;
        int real[4*n+10];
        for(int i=0;i<n;i++){
            vector<int> e = buildings[i];
            val.push_back(make_pair(e[0], -(i+1)));
            val.push_back(make_pair(e[1], i+1));
        }
        sort(val.begin(),val.end());
        int last = 1, lft[n+2], rgt[n+2];
        for(int i=0;i<val.size();i++){
            if(i>0 && val[i].first>val[i-1].first) ++last;
            if(i>0 && val[i].first>val[i-1].first+1) ++last;
            if(val[i].second<0) lft[-val[i].second-1] = last;
            else rgt[val[i].second-1] = last;
            real[last] = val[i].first;
        }
        tree.resize(4*last);
        fill(tree.begin(), tree.end(), 0);
        lazy.resize(4*last);
        fill(lazy.begin(), lazy.end(), 0);
        vector<pair<int, pair<int,int>>> data;
        for(int i = 0;i<n;i++){
            data.push_back({buildings[i][2], {lft[i], rgt[i]}});
            
            
        }
        sort(data.begin(), data.end());
        for(int i = 0;i<n;i++){
            // cout << data[i].second.first << " ";
            // cout << data[i].second.second << " ";
            // cout << data[i].first << "##\n";
            update(1, 1, last, data[i].second.first, data[i].second.second, data[i].first);
            
        }
        int arr[last+2];
        for(int i=1;i<=last;i++){
            arr[i] = query(1,1,last,i);
            //cout << arr[i] << " ";
        }
        
        ans.push_back({real[1],arr[1]});
        for(int i=2;i<=last;i++){
            if(arr[i]!=arr[i-1]){
                int x = i-1;
                if(arr[i]>arr[i-1]) x = i;
                ans.push_back({real[x],arr[i]});
            }
        }
        ans.push_back({real[last],0});
        return ans;
    }

private:
void propagate(int node, int b, int e){
    tree[node] = max(tree[node],lazy[node]);
    if(b==e || lazy[node]==0) return;
    lazy[2*node] = max(lazy[2*node],lazy[node]);
    lazy[2*node+1] = max(lazy[2*node+1],lazy[node]);
    lazy[node] = 0;
}
int query(int node, int b, int e, int pos){
        propagate(node, b, e);
        if(pos>e || pos<b) return 0;
        if(b==e) return tree[node];
        int mid = (b+e)>>1, lft = node<<1, rgt = lft|1;
        return max(query(lft, b, mid, pos), query(rgt,mid+1,e,pos));
    }
    
    void update(int node, int b, int e, int l, int r, int val){
        
        propagate(node, b, e);
        if(l>e || r<b) return;
        // cout << node << ": " << val << "\n";
        if(l<=b && r>=e){
            lazy[node] = max(lazy[node], val);
            propagate(node, b, e);
            return;
        }
        int mid = (b+e)>>1, lft = node<<1, rgt = lft|1;
        update(lft, b, mid, l, r, val);
        update(rgt, mid+1, e, l, r, val);
        tree[node] = max(tree[lft], tree[rgt]);
    }
};


