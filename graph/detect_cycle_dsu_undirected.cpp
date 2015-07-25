struct edge { int v1,v2,w; };
struct subset { int parent,rank; };
subset subsets[N];
edge edges[M];
int find(int v) {
        if(subsets[v].parent!=v) subsets[v].parent=find(subsets[v].parent);
        return subsets[v].parent;
}
void set_union(int p1,int p2) {
        int x=find(p1),y=find(p2);
        if(subsets[x].rank>subsets[y].rank) subsets[y].parent=x;
        else if(subsets[y].rank>subsets[x].rank) subsets[x].parent=y;
        else {
                subsets[y].parent=x;
                subsets[x].rank++;
        }
}
bool detect_cycle() {
        REP(i,0,m-1) {
                int p1=find(edges[i].v1), p2=find(edges[i].v2);
                if(p1==p2) return true;
                set_union(p1,p2);
        }
        return false;
}
