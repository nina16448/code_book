#include <iostream>
using namespace std;
typedef long long lint;
#define rate first
#define cost second
#define u first
#define v second
int flag;
int N, M, S, a, b;
double V, r, c;
double value[110];
pair <double, double> change[110][110];
pair <int, int> graph[110];

void Bellman_ford(){
    for(int i = 0; i < M; i++){
        double after = (value[graph[i].v] - change[graph[i].v][graph[i].u].cost) * change[graph[i].v][graph[i].u].rate; //v換成u
        if(after > value[graph[i].u]){
            value[graph[i].u] = after;
            flag = false;
        }

        after = (value[graph[i].u] - change[graph[i].u][graph[i].v].cost) * change[graph[i].u][graph[i].v].rate; //u換成v
        if(after > value[graph[i].v]){
            value[graph[i].v] = after;
            flag = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    flag = 0;
    cin >> N >> M >> S >> V;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> r >> c;
        change[a][b] = make_pair(r, c);

        cin >> r >> c;
        change[b][a] = make_pair(r, c);

        graph[i] = make_pair(a, b);
    }

    value[S] = V;
    while(!flag){
        flag = true;
        Bellman_ford();
        
        if(value[S] > V) break;
    }

    if(flag) cout << "NO\n";
    else cout << "YES\n";
    
    return 0;
}