#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long lint;
#define ID first
#define weight second
int u, v, w, diameter, point;
queue <int> qu;
int stp[10010];
vector <pair <int, int> > graph[10010];

void init(int v){
    while(!qu.empty()) qu.pop();
    for(int i = 0; i < 10010; i++) stp[i] = -1;
    diameter = 0;
    stp[v] = 0;
    qu.push(v);
}

void BFS(int level){
    while(!qu.empty()){
        for(int i = 0; i < graph[qu.front()].size(); i++){
            pair <int, int> x = graph[qu.front()][i];
            if(stp[x.ID] != -1) continue;

            qu.push(x.ID);
            stp[x.ID] = stp[qu.front()] + x.weight;
            
            if(stp[x.ID] > diameter){
                point = x.ID;
                diameter = stp[x.ID];
            }
        }
        qu.pop();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> u >> v >> w){
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    init(1);
    BFS(1);

    init(point);
    BFS(point);

    cout << diameter << "\n";
    return 0;
}