#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct Edge {
    int dest, weight;
};

struct CompareEdge {
    bool operator()(const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    }
};

void dijkstraShortestPaths(vector<vector<Edge>>& graph, int source) {
    int V = graph.size();
    vector<int> distances(V, INT_MAX);
    vector<bool> visited(V, false);

    priority_queue<Edge, vector<Edge>, CompareEdge> pq;

    distances[source] = 0;
    pq.push({source, 0});

    while (!pq.empty()) {
        int u = pq.top().dest;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        for (const Edge& edge : graph[u]) {
            int v = edge.dest;
            int weight = edge.weight;

            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({v, distances[v]});
            }
        }
    }

    cout << "Shortest distances from source vertex " << source << ":" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<Edge>> graph(V);

    cout << "Enter " << E << " edges in the format: source destination weight" << endl;
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstraShortestPaths(graph, source);

    return 0;
}

