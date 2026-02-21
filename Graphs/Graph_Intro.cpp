#include<bits/stdc++.h>
using namespace std;
class Graph {
    int V;
    list<int> *l;
public:
    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int i, int j, bool undir = true) {
        l[i].push_back(j);
        if (undir) {
            l[j].push_back(i);
        }
    }
    void printAdjList() {
        for (int i = 0; i < V; i++) {
            cout << i << "->";
            for (auto node : l[i]) {
                cout << node << ",";
            }
            cout << endl;
        }
    }
    void bfs (int source) {
        queue<int> q;
        vector<bool> visited(V, false);
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (auto nbr : l[node]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.printAdjList();
    cout << "\nBFS traversal starting from node 0: ";
    g.bfs(0);
}