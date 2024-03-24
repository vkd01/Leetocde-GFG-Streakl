typedef long long ll;
const ll N = 2e5 + 10;
  /*----------------------------SEGMENT TREE-------------------------------------------------*/
 class SegmentTree {

 public:
  vector<ll> segTree;

  SegmentTree(){
    segTree.resize(4*N);
  }
 
 ll combine(ll a, ll b){
    return max(a,b);
 }

public:

 
 void update(ll node, ll start, ll end, ll idx, ll val) {
   if(start == end){
 // Leaf node
     segTree[node] += val;
   }
   else{
     ll mid = start + (end - start) / 2;
     if(start <= idx and idx <= mid){
       update(2*node+1, start, mid, idx, val);
     }
     else {
       update(2*node+2, mid+1, end, idx, val);
     }
     segTree[node] = combine(segTree[2*node+1] ,segTree[2*node+2]);
   }
 }

 ll query(ll node, ll start, ll end, ll left, ll right){
   if(right < start or end < left)  return 0;
   if(left <= start and end <= right) return segTree[node];

   ll mid = start + (end - start)/2;
   ll p1 = query(2*node+1, start, mid, left, right);
   ll p2 = query(2*node+2, mid+1, end, left, right);
   return combine(p1 , p2);
 }
};


class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& arr, vector<int>& freq) {
        vector<ll> ans;
        ll n = arr.size();
        
        SegmentTree segtree;
        
        for(int i = 0;i<n;i++){
            ll ind = arr[i], val = freq[i];
            
            segtree.update(0,0,N-1, ind, val);
            
            ans.push_back(segtree.segTree[0]);
        }
        
        
        return ans;
    }
};
















