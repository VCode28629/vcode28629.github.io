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

void spfa(int start) {
    static bool in_que[MAX_NODE_NUM];
    memset(dis, 0x7f, sizeof(dis));
    memset(in_que, false, sizeof(in_que));
    dis[start] = 0;
    std::queue<int> que;
    que.push(start);
    in_que[start] = true;
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        in_que[now] = false;
        for(Edge *edg = first[now]; edg != NULL; edg = edg->next) {
            if(dis[edg->to] > dis[now] + edg->cost) {
                dis[edg->to] = dis[now] + edg->cost;
                if(!in_que[edg->to]) {
                    que.push(edg->to);
                    in_que[edg->to] = true;
                }
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
    spfa(start);
    for(int i = 1; i <= noden; ++i) {
        printf("%d ", dis[i]);
    }
    return 0;
}