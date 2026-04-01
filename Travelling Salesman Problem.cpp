#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int tsp(int graph[][4], int n) {
    int vertices[] = {1, 2, 3};
    int min_path = INT_MAX;

    do {
        int current_weight = 0;
        int k = 0;

        for (int i = 0; i < n - 1; i++) {
            current_weight += graph[k][vertices[i]];
            k = vertices[i];
        }

        current_weight += graph[k][0];
        min_path = min(min_path, current_weight);

    } while (next_permutation(vertices, vertices + n - 1));

    return min_path;
}

int main() {
    int graph[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "Minimum TSP cost = " << tsp(graph, 4);

    return 0;
}