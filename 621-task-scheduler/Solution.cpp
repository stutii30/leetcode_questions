class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        priority_queue<int>q;
        for(auto it=mp.begin();it!=mp.end();it++){
            q.push(it->second);
        }
        
        int ans=0;
        while(!q.empty()){
            vector<int>a;
        for(int i=0;i<=n;i++){
            if(!q.empty()){
                int t=q.top();
                q.pop();
                t--;
                if(t>0) a.push_back(t);
                ans++; 
            }
            else{ 
            if(a.empty())break;
            ans++;
            }
        }
        for(int i=0;i<a.size();i++){
            q.push(a[i]);
        }
        }
        return ans;
    }
};