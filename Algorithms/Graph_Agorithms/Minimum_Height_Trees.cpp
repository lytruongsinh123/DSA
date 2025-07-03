#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1) return {0}; // Special case for single node

        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);

        // Build the graph and calculate degrees
        for (const auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        vector<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                leaves.push_back(i);
            }
        }

        while (n > 2) {
            n -= leaves.size();
            vector<int> newLeaves;

            for (int leaf : leaves) {
                for (int neighbor : graph[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        newLeaves.push_back(neighbor);
                    }
                }
            }

            leaves = newLeaves;
        }

        return leaves; // Remaining nodes are the roots of MHTs
    }
};
int main() {
    Solution solution;
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}};
    
    vector<int> result = solution.findMinHeightTrees(n, edges);
    
    cout << "Minimum Height Trees: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
