#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int V) : vertices(V), adjacencyList(V) {}

    void addEdge(int from, int to) {
        adjacencyList[from].push_back(to);
    }

    void BFS(int startNode) {
        queue<int> q;
        unordered_set<int> visited;

        q.push(startNode);
        visited.insert(startNode);

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();

            cout << currentNode << " ";

            for (int neighbor : adjacencyList[currentNode]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    Graph graph(vertices);

    cout << "Enter the edges (from to):" << endl;
    for (int i = 0; i < edges; ++i) {
        int from, to;
        cin >> from >> to;
        graph.addEdge(from, to);
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    cout << "Nodes reachable from " << startNode << " are: ";
    graph.BFS(startNode);

    return 0;
}

