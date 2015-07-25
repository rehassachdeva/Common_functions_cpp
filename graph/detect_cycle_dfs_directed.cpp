bool *visited=new bool[N],*onstack=new bool[N];
bool is_cyclic_util(int i) {
        visited[i]=true;
        onstack[i]=true;
        TR(v[i],it) {
                if(!visited[*it]&&is_cyclic_util(*it)) return true;
                else if (onstack[*it]) return true;
        }
        return false;
}
bool iscyclic() {
        REP(i,1,n) visited[i]=onstack[i]=false;
        REP(i,1,n) if(!visited[i]&&is_cyclic_util(i)) return true;
        return false;
}

