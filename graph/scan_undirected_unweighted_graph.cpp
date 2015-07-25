vector<int> v[N];
int n,m;
void scan_undirected_unweighted_graph() {
        cin>>n>>m;
        REP(i,1,n) v[i].clear();
        int v1,v2;
        REP(i,0,m-1) {
                cin>>v1>>v2;
                v[v1].PB(v2);
                v[v2].PB(v1);
        }
}


