void bfs(int s) {
        bool *visited = new bool[N];
        REP(i,1,n) visited[i]=false;
        queue<int> q;
        visited[s]=true;
        q.push(s);
        while(!q.empty()) {
                s=q.front();
                cout<<s<<" ";
                q.pop();
                TR(v[s],it) {                        
                        if(!visited[*it]) {
                                visited[*it]=false;
                                q.push(*it);
                        }
                }
        }
}
