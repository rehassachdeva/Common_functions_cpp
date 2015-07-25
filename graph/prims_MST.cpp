#include<iostream>
#include<bits/stdc++.h>
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
#define MINH priority_queue< pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > >
#define N 100000
typedef long long LL;
using namespace std;
set<pair<int,int> > s;
bool isMST[N];
int key[N];
int parent[N];
int main()
{
        vector< pair<int, int> > v[N];
        int n,m,x,c=0;
        cin>>n>>m;
        int v1,v2,w;
        REP(i,0,m-1) {
                cin>>v1>>v2>>w;
                v[v1].PB(MP(v2,w));                        
                v[v2].PB(MP(v1,w));
        }
        REP(i,1,n) {
                isMST[i]=false;
                key[i]=INT_MAX;
                parent[i]=-1;
        }
        REP(i,2,n) s.insert(MP(INT_MAX, i));                
        key[1]=0;
        s.insert(MP(0,1));
        while(!s.empty()) {
                int u=(*s.begin()).S;
                s.erase(MP(key[u],u));
                isMST[u]=true;      
                REP(i,0,SZ(v[u])-1) {
                        x=v[u][i].F;
                        if(isMST[x]==false) {
                                if(key[x]>v[u][i].S) {
                                        s.erase(MP(key[x],x));
                                        key[x]=v[u][i].S;
                                        parent[x]=u;
                                        s.insert(MP(key[x],x));
                                }
                        }
                        
                }
        }
        REP(i,2,n) cout<<parent[i]<<" "<<i<<endl;
        return 0;
}
