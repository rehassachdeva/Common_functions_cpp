bool *visited=new bool[V];
stack<int> Stack;
void topo_sort_util(int i) {
        visited[i]=true;
        TR(v[i],it) if(!visited[*it]) topo_sort_util(*it);
        Stack.push(i);
}
void topo_sort() {
        REP(i,1,n) visited[i]=false;
        REP(i,1,n) if(!visited[i]) topo_sort_util(i);
        while(!Stack.empty()) {
                cout<<Stack.top()<<" ";
                Stack.pop();
        }
}
