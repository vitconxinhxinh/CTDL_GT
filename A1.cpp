#include <iostream>
using namespace std;

const int MAX = 100005;
int N, M;
int *adj[MAX];    // danh sách kề động cho mỗi đỉnh
int deg[MAX];     // số cạnh kề
bool visited[MAX];

int dfs(int u) {
    visited[u] = true;
    int cnt = 1;
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            cnt += dfs(v);
        }
    }
    return cnt;
}

int main() {
    cin >> N >> M;

    // cấp phát động cho từng danh sách kề
    for (int i = 1; i <= N; i++) {
        adj[i] = new int[MAX]; // tạm cấp phát đủ lớn (M có thể tới 100000)
        deg[i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }

    cout << dfs(1) << endl;

    return 0;
}
