#include <iostream>
#include <queue>
using namespace std;
typedef long long lint;
#define weight first
#define u second.first
#define v second.second
priority_queue < pair <int, pair <int, int> >, vector < pair <int, pair <int, int> > >, greater < pair <int, pair <int, int> > > > pq;
int N, w, num, sum;
char PA, PB;

struct Union_Find{
    int root[30];
    int tree[30];
    void init(){
        for(int i = 0; i < 30; i++){
            root[i] = i;
            tree[i] = 1;
        }
    }

    int Find(int x){
        if(x == root[x]) return x;
        return root[x] = Find(root[x]);
    }

    void Union(int x, int y){
        x = Find(x);
        y = Find(y);

        if(x == y) return;
        
        if(tree[x] > tree[y]){
            root[y] = x;
            tree[x] += tree[y];
        }
        else{
            root[x] = y;
            tree[y] += tree[x];
        }
    } 
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    Union_Find UF;
    while(cin >> N && N){
        UF.init();
        while(!pq.empty()) pq.pop();
        sum = 0;
        
        for(int t = 1; t < N; t++){
            cin >> PA >> num;
            while(num--){
                cin >> PB >> w;
                pq.push(make_pair(w, make_pair(PA - 'A', PB - 'A')));
            }
        }

        while(!pq.empty()){
            if(UF.Find(pq.top().v) != UF.Find(pq.top().u)){
                UF.Union(pq.top().u, pq.top().v);
                sum += pq.top().weight;
            }
            pq.pop();
        }
        
        cout << sum << "\n";
    }

    return 0;
}