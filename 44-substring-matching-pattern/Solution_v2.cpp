class Solution {
public:
bool isstar(string &s, int k){
    for(int i=0;i<=k;i++){
        if(s[i]!='*')
        return false;
    }
    return true;
}
bool solve(string &s, string &p, int i, int j,vector<vector<int>>&dp){
    if(j<0) return true;
    if(i<0) return isstar(p,j);
    if(i>=0 and j<0) return false;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==p[j]){
        return dp[i][j]=solve(s,p,i-1,j-1,dp);
    
    }
    if(p[j]=='*'){
        return dp[i][j]= solve(s,p,i-1,j,dp) or solve(s,p,i,j-1,dp);
    }
    return false;

}
    bool hasMatch(string s, string p) {
        int n=s.size();
        vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
        for(int i=0;i<n;i++){
            if(solve(s,p,i,p.size()-1,dp)) return true;
        }
        return false;
    }
};