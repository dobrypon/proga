#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

void task1() {
    int N, S, F;
    cin >> N >> S >> F;
    S--; F--; 

    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];

    const int INF = numeric_limits<int>::max();
    vector<int> dist(N, INF);
    vector<bool> visited(N, false);
    dist[S] = 0;

    for (int i = 0; i < N; i++) {
        int u = -1;
        for (int j = 0; j < N; j++)
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;

        if (dist[u] == INF) break;
        visited[u] = true;

        for (int v = 0; v < N; v++) {
            if (graph[u][v] != -1 && dist[v] > dist[u] + graph[u][v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    if (dist[F] == INF)
        cout << -1 << endl;
    else
        cout << dist[F] << endl;
}


void task2() {
    int N;
    cin >> N;
    vector<int> cost(N);
    for (int i = 0; i < N; i++) cin >> cost[i];

    int M;
    cin >> M;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const int INF = numeric_limits<int>::max();
    vector<int> dist(N, INF);
    dist[0] = cost[0]; 

    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({ dist[0], 0 });

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (int v : adj[u]) {
            int new_cost = dist[u] + cost[v]; 
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({ dist[v], v });
            }
        }
    }

    if (dist[N - 1] == INF)
        cout << -1 << endl;
    else
        cout << dist[N - 1] << endl;
}


int main() {
    setlocale(LC_ALL, "RUSSIAN");
    int choice;
    cout << "Выберите задачу (1 - Дейкстра, 2 - Заправки): ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Введите данные для задачи Дейкстра:\n";
        task1();
        break;
    case 2:
        cout << "Введите данные для задачи Заправки:\n";
        task2();
        break;
    default:
        cout << "Неверный выбор!" << endl;
    }

    return 0;
}
