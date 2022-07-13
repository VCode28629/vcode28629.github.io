#include<cstdio>
#include<cstring>
#include<queue>

const int MAX_NODE_NUM = 1e5 + 5;

struct Edge {
    Edge(int to, int cost, Edge *next) : to(to), cost(cost), next(next) {}
    int to;
    int cost;
    Edge *next;
};

Edge *first[MAX_NODE_NUM];
int dis[MAX_NODE_NUM];

void addEdge(int from, int to, int cost) {
    first[from] = new Edge(to, cost, first[from]);
}

void dij(int start) {
    std::priority_queue<std::pair<int, int> > heap;
    memset(dis, 0x3f, sizeof(dis));
    dis[start] = 0;
    heap.push({0, start});
    while(!heap.empty()) {
        auto now = heap.top();
        heap.pop();
        if(now.first != -dis[now.second]) continue;
        for(Edge *edg = first[now.second]; edg != NULL; edg = edg->next) {
            if(dis[edg->to] > edg->cost - now.first) {
                dis[edg->to] = edg->cost - now.first;
                heap.push({-dis[edg->to], edg->to});
            }
        }
    }
}

int main() {
    int noden, edgen, start;
    scanf("%d%d%d", &noden, &edgen, &start);
    while(edgen--) {
        int from, to, cost;
        scanf("%d%d%d", &from, &to, &cost);
        addEdge(from, to, cost);
    }
    dij(start);
    for(int i = 1; i <= noden; ++i) {
        printf("%d ", dis[i]);
    }
    return 0;
}