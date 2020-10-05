// Minimum Cost of Spanning Tree
#include <iostream>
using namespace std;

#define I INT_MAX
#define V 8

void primsAlgo(int cost[][V]){
    int near[8] = {I, I, I, I, I, I, I, I};
    int track[2][6];
    int n = 7;
    int u = 0;
    int v = 0;
    int min = I;
    int k = 0;

    // Find Minumum Cost Edge
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) { // Starts in i to traverse only the low triangle
            if (cost[i][j] < min) {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    track[0][0] = u;
    track[1][0] = v;
    // Update array Near for included nodes
    near[u] = 0;
    near[v] = 0;

    // Initialize Near Array
    for (int i = 1; i <= n; i++){
        if (near[i] != 0) {
            if (cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }

    for (int i = 1; i < n - 1; i++) {
        min = I;
        for (int j = 1; j <= n; j++) {
            if (near[j] != 0 && cost[j][near[j]] < min) {
                k = j;
                min = cost[j][near[j]];
            }
        }
        track[0][i] = k;
        track[1][i] = near[k];
        near[k] = 0;
        // Modify near array
        for (int j = 1; j <=n; j++) {
            if (near[j] != 0 && cost[j][k] < cost[j][near[j]])
                near[j] = k;
        }
    }


    // Print the solution
    for (int i = 0; i < n - 1; i++) {
        cout << "(" << track[0][i] << "," << track[1][i] << ")" << endl;
    }
}

int main(){
    int cost [V][V] = {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };

    primsAlgo(cost);
}