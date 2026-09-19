class Solution {
public: int expand(string &s, int i, int j){
    while(i>=0 and j<s.size() and s[i]==s[j]){
        i--;
        j++;
    }
    return j-i-1;
}
    string longestPalindrome(string s) {
        int st=0,maxl=1;
        for(int i=0;i<s.size();i++){
            int o=expand(s,i,i);
            int e=expand(s,i,i+1);
            int k=max(o,e);
            if(k>maxl){
                maxl=k;
                st=i-(k-1)/2;
            }
        }
        return s.substr(st,maxl);
    }
};