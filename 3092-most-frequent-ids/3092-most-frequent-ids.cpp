typedef long long ll;
const ll N = 4e5 + 10;

class SegmentTree{

    public :
    vector<ll> tree;
    SegmentTree(){
        tree.resize(4*N,0);
    }

    void update(ll node, ll left, ll right, ll ind, ll val){
        if(left == right){
            tree[node]+=val;
            return;
        }

        ll mid = left + (right - left)/2;

        if(ind<=mid) update(2*node+1, left, mid, ind, val);
        else update(2*node+2, mid+1, right, ind, val);

        tree[node] = max(tree[2*node+1], tree[2*node+2]);

    }

};



class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& arr, vector<int>& freq) {

        vector<ll> ans;

        SegmentTree segtree;
        
        ll n = arr.size();
        
        for(ll i = 0;i<n;i++){

            ll ele = arr[i], times = freq[i];
            segtree.update(0,0,N-1, ele, times);
            ans.push_back(segtree.tree[0]);
        }



        return ans;
    }
};