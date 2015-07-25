#define NINF INT_MIN
int dist[N];
void longest_paths_dag(int s) {
        REP(i,1,n) dist[i]=NINF;
        dist[s]=0;
        topo_sort();
        while(!Stack.empty()) {
                int u=Stack.top();
                Stack.pop();
                if(dist[u]!=NINF) {
                        TR(v[u],it)
                                if(dist[(*it).F]<dist[u]+(*it).S)
                                        dist[(*it).F]=dist[u]+(*it).S;
                }
        }
        REP(i,1,n) (dist[i]==NINF)? cout<<"INF": cout<<dist[i]<<" ";
}
