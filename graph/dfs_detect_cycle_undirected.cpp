bool *visited = new bool[N];
bool detect_cycle_util(int s, int p) {
        visited[s]=true;
        TR(v[s],it) 
                if(!visited[*it]) {
                        if(detect_cycle_util(*it,s))
                                return true;
                }
                else if(*it!=p) return true;
        return false;
}
bool detect_cycle(int s) {
        REP(i,1,n) visited[i]=false;
        REP(i,1,n) if(!visited[i]&&detect_cycle_util(i,-1)) return true;
        return false;
}
