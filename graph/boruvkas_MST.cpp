#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define TR(a,t) for(typeof(a.begin()) t=a.begin();t!=a.end();t++)
#define REP(i,l,h) for(int i=(l); i<=(h);i++)
#define REPD(i,h,l) for(int i=(h);i>=(l);i--)
#define ALL(a) a.begin(),a.end()
#define DRT()  int t; cin>>t; while(t--)
#define PRSNT(a,e) (a.find(e) != a.end())
#define MINH priority_queue<int, vector<int>, greater<int> >
#define N 100000
#define M 1000000
typedef long long LL;
using namespace std;
struct edge { int v1,v2,w; };
struct subset { int parent,rank; };
int n,m;
subset subsets[N];
edge edges[M];
int cheapest[N];
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
void boruvkasMST() {
        int numTrees=n;
        int MSTweight=0;
        while(numTrees>1) {
                REP(i,0,m-1) {
                        int p1=find(edges[i].v1), p2=find(edges[i].v2);
                        if(p1!=p2) {
                                if(cheapest[p1]==-1||edges[cheapest[p1]].w>edges[i].w)
                                        cheapest[p1]=i;
                                if(cheapest[p2]==-1||edges[cheapest[p2]].w>edges[i].w)
                                        cheapest[p2]=i;
                        }
                }

                REP(i,1,n) {
                        if(cheapest[i]!=-1) {
                                int p1=find(edges[i].v1), p2=find(edges[i].v2);
                                if(p1!=p2) {
                                        MSTweight+=edges[cheapest[i]].w;
                                        set_union(p1,p2);
                                        numTrees--;
                                }
                        }
                }
        }
        cout<<MSTweight<<endl;


}
int main()
{
        int v1,v2,w;
        cin>>n>>m;
        REP(i,1,n) {
                subsets[i].parent=i;
                subsets[i].rank=0;
                cheapest[i]=-1;
        }
        REP(i,0,m-1) {
                cin>>v1>>v2>>w;
                edges[i].v1=v1;
                edges[i].v2=v2;
                edges[i].w=w;
        }
        boruvkasMST();
        return 0;
}
