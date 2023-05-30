#include <iostream>
#include <queue>
#include <cstdint>

using namespace std;

vector<vector<int>> graph {{0, 10, 0, 0, 15, 5},
                {10, 0, 10, 30, 0, 0},
                {0, 10, 0, 12, 5, 0},
                {0, 30, 12, 0, 0, 20},
                {15, 0, 5, 0, 0, 0},
                {5, 0, 0, 20, 0, 0}};

void shortest_paths(vector<vector<int>> graph, int start) {
    int n = graph.size();

    vector<int> dists(n, INT32_MAX);
    priority_queue <vector<int>> q;

    vector<int> item {0, start};
    q.push(item);
    dists[start] = 0;

    int node, dist, new_dist;

    while (!q.empty()) {
        item = q.top();
        q.pop();
        node = item[1];
        dist = -item[0];
        if (dist > dists[node]) continue;

        for (int i = 0; i < n; i++) {
            if (i == node) continue;
            if (graph[node][i] == 0) continue;
            new_dist = dist + graph[node][i];
            if (new_dist < dists[i]) {
                item[0] = -new_dist;
                item[1] = i;
                q.push(item);
                dists[i] = new_dist;
            }
        }
    }
    /*
    // Question 3
    cout << "Source node = " << start << endl;
    for (int i = 0; i < n; i++) {
        if (i == start) continue;
        cout << start << " -> " << i << ": " << dists[i] << endl;
    }*/

    // Question 4
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += dists[i];
    }
    cout << start << "\t" << (float) sum / (float) (n-1) << endl;

}

int main() {
    cout << "Average time from each source city\n";
    cout << "Source\tTime\n";
    for (int i = 0; i < graph.size(); i++) {
        shortest_paths(graph, i);
    }
    return 0;
}