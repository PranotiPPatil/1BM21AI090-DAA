#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct CompareEdge {
    bool operator()(const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    }
};

int findParent(vector<int>& parent, int vertex) {
    if (parent[vertex] == vertex)
        return vertex;
    return findParent(parent, parent[vertex]);
}

void unionSets(vector<int>& parent, int a, int b) {
    int parentA = findParent(parent, a);
    int parentB = findParent(parent, b);
    parent[parentA] = parentB;
}

void kruskalMST(vector<Edge>& edges, int V) {
    vector<int> parent(V);
    for (int i = 0; i < V; ++i)
        parent[i] = i;

    sort(edges.begin(), edges.end(), CompareEdge());

    vector<Edge> mst;
    int mstWeight = 0;

    for (const Edge& edge : edges) {
        if (findParent(parent, edge.src) != findParent(parent, edge.dest)) {
            mst.push_back(edge);
            unionSets(parent, edge.src, edge.dest);
            mstWeight += edge.weight;
        }
    }

    cout << "Edges in the minimum spanning tree:" << endl;
    for (const Edge& edge : mst) {
        cout << edge.src << " - " << edge.dest << " (Weight: " << edge.weight << ")" << endl;
    }
    cout << "Total cost of minimum spanning tree: " << mstWeight << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter " << E << " edges in the format: source destination weight" << endl;
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    kruskalMST(edges, V);

    return 0;
}

