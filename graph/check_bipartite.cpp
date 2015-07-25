bool check_bipartite(int s) {
        int color[N];        
        REP(i,1,n) color[i]=-1;
        color[s]=1;
        queue<int> q;
        visited[s]=true;
        q.push(s);
        while(!q.empty()) {
                s=q.front();
                cout<<s<<" ";
                q.pop();
                TR(v[s],it) {                        
                        if(color[*it]==-1) {
                                color[*it]=1-color[s];
                                q.push(*it);
                        }
                        else if(color[s]==color[*it]) return false;
                }
        }
        return true;
}
