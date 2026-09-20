class Solution {
public:
bool isstar(string &s, int i){
    for(int j=0;j<=i;j++){
        if(s[j]!='*')
        return false;
    }
    return true;
}
bool solve(string &s, string &p, int i, int j,vector<vector<int>>& dp){
    if(i<0 and j<0){
        return true;
    }
    if(i<0 and j>=0) return isstar(p,j);
    if(i>=0 and j<0) return false;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==p[j] or p[j]=='?')
    return dp[i][j]=solve(s,p,i-1,j-1,dp);
    if(p[j]=='*')
    return dp[i][j]=solve(s,p,i-1,j,dp) or solve(s,p,i,j-1,dp);

    return false;
}
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
        return solve(s,p,s.size()-1,p.size()-1,dp);
    }
};