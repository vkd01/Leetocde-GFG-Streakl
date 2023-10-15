class Solution {
private:
    
    static bool comp(string a, string b){
        string x = "", y = "";
        x+=a;
        x+=b;
        
        
        y+=b;
        y+=a;
        
        return x>y;
    }
    
public:
    string largestNumber(vector<int>& arr) {
        string ans = "";
        
        
        vector<string> v;
        
        for(auto&i:arr){
            v.push_back(to_string(i));
        }
        
        sort(v.begin(), v.end(),comp);
        
        for(auto&i:v) cout<<i<<" ";
        cout<<endl;
        
        
        for(auto&i:v) ans+=i;
        
        
        set<char> st;
        for(auto&i:ans) st.insert(i);
        
        if(st.size() == 1 and *st.begin() == '0') return"0";
        
        
        
        
        return ans;
    }
};