void dfsutil(int s) {
        visited[s]=true;
        cout<<s<<" ";
        TR(v[s],it) 
                if(!visited[*it])
                        dfsutil(*it);
}
void dfs(int s) {
        bool *visited = new bool[N];
        REP(i,1,n) visited[i]=false;
        dfsutil(s);
}
