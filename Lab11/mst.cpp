#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> graph {{0, 3, 0, 0, 0, 1},
                {3, 0, 2, 1, 10, 0},
                {0, 2, 0, 3, 0, 5},
                {0, 1, 3, 0, 5, 0},
                {0, 10, 0, 5, 0, 4},
                {1, 0, 5, 0, 4, 0}};


void min_spanning_tree(vector<vector<int>> graph, vector<vector<int>>& mst, int n) {
    int found[n] = {0};
    int node = 0;

    found[node] = 1;
    int found_count = 1;

    priority_queue <vector<int>> q;

    while (found_count < n) {
        for (int i = 0; i < n; i++) {
            if (graph[node][i] > 0) {
                vector<int> edge {-graph[node][i], i, node};
                q.push(edge);
            }
        }
        vector<int> edge;
        int a, b;
        while (1) {
            edge = q.top();
            q.pop();
            a = edge[1];
            b = edge[2];

            if (!found[a]) {
                found[a] = 1;
                found_count += 1;

                mst[a][b] = mst[b][a] = -edge[0];
                node = a;
                break;
            }
        }
    }
}

void print_mst(vector<vector<int>> mst, int n) {
    cout << " " << "\t";
    for (int i = 0; i < n; i++) {
        cout << i << '\t';
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << i << '\t';
        for (int j = 0; j < n; j++) {
            cout << mst[i][j] << '\t';
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> mst = graph;
    int n = 6;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mst[i][j] = 0;
        }
    }
    min_spanning_tree(graph, mst, 6);

    cout << "Adjacency matrix of MST" << endl;
    print_mst(mst, 6);
    return 0;
}