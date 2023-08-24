#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct CompareEdge {
    bool operator()(const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    }
};

void primMST(vector<vector<pair<int, int>>>& graph, int startVertex) {
    int V = graph.size();
    vector<bool> visited(V, false);
    priority_queue<Edge, vector<Edge>, CompareEdge> pq;

    visited[startVertex] = true;
    for (const pair<int, int>& edge : graph[startVertex]) {
        pq.push({startVertex, edge.first, edge.second});
    }

    int totalCost = 0;
    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();

        int v = e.dest;

        if (visited[v]) {
            continue;
        }

        visited[v] = true;
        totalCost += e.weight;
        cout << "Added edge: " << e.src << " - " << e.dest << " (Weight: " << e.weight << ")" << endl;

        for (const pair<int, int>& edge : graph[v]) {
            if (!visited[edge.first]) {
                pq.push({v, edge.first, edge.second});
            }
        }
    }

    cout << "Total cost of minimum spanning tree: " << totalCost << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V);

    cout << "Enter " << E << " edges in the format: source destination weight" << endl;
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src].push_back(make_pair(dest, weight));
        graph[dest].push_back(make_pair(src, weight));
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    primMST(graph, startVertex);

    return 0;
}

