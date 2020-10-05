// Kruskals Algorithm 
// Before adding a vertex, checks if it forms a cycle

#include <iostream>
using namespace std;

#define I INT_MAX
#define V 7
#define E 9

// Set operations: Union and Find
void Union(int u, int v, int s[]){
    if (s[u] < s[v]){
        s[u] += s[v];
        s[v] = u;
    } else {
        s[v] += s[u];
        s[u] = v;
    }
}
 
int Find(int u, int s[]){
    int x = u;
    int v = 0;
 
    while (s[x] > 0){
        x = s[x];
    }
 
    while (u != x){
        v = s[u];
        s[u] = x;
        u = v;
    }
    return x;
}

void PrintMCST(int T[][V-1], int A[][E]){
    cout << "\nMinimum Cost Spanning Tree Edges\n" << endl;
    for (int i {0}; i<V-1; i++){
        cout << "[" << T[0][i] << "]-----[" << T[1][i] << "]" << endl;
    }
    cout << endl;
}

// Kruskals Algorithm
void kruskalsAlgo(int edges[3][9]){
    int R[2][V - 1] = {0}; // Resulting adjacencies
    int track[E] = {0}; // Tracking included edges in the solution
    int set[V + 1] = {-1}; // Array for finding cycles, check if parents are the same

    int n = 7;
    int e = 9;

    int i = 0;


    while(i < V - 1) {
        int min = I;

        int u = 0;
        int v = 0;
        int k = 0;

        for (int j = 0; j < e; j++) {
            if (track[j] == 0 && edges[2][j] < min) {
                min = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                k = j;
            }
        }

        if (Find(u, set) != Find(v, set)) {
            R[0][i] = u;
            R[1][i] = v;

            // Perform Union
            Union(Find(u, set), Find(v, set), set);
            i++;
        }
        track[k] = 1;
    }

    // Print Result
    PrintMCST(R, edges);
}


int main () {
    // List of adjacencies
    int edges[3][9] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                       { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};
    kruskalsAlgo(edges);
}