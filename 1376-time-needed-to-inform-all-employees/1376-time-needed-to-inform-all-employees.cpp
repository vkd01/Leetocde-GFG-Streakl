class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n];
        for(int i = 0;i<n;i++){
            if(manager[i] == -1){
                continue;
            }
            adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        q.push({0,headID});
        vector<int>time(n,INT_MAX);
        time[headID] = 0;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int t = temp.first;
            int head = temp.second;
            for(auto v:adj[head]){
                int reqtime = t+informTime[head];
                if(reqtime<time[v]){
                    q.push({reqtime,v});
                    time[v] = reqtime;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans = max(ans,time[i]);
        }
        return ans;
    }
};