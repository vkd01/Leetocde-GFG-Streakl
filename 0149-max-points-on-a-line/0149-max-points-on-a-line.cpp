class Solution {
private:
    int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
public:

  int maxPoints(vector<vector<int>>& points) {

    int ans = 0;

    for (int i = 0; i < points.size(); i++) {
        int dup = 0;
        map<pair<int, int>, int> slope;
        for (int j = i; j < points.size(); j++) {

            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            if ( (dy == 0) and (dx == 0)) dup++;
           // if(dy!=0 and dx!=0)
            else {
                int gc = gcd(dy,dx);
                dx /= gc;
                dy /= gc;
                 slope[ {dx, dy}]++;
            }


           
        }
        ans = max(ans, dup);

        for (auto i : slope) {
            ans = max(ans, i.second + dup);
        }


    }
    return ans;
}
};