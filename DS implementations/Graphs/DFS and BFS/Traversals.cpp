#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void bfs(int G[][6], int start, int end){
    queue<int> bfsQ; // Queue manages BFS
    int visited[6] = {0}; // Array to mark visited vertixes
    int u = start; // Starting vertex

    // Process starting vertex
    cout << u << " ";
    visited[u] = 1;
    bfsQ.push(u);

    while(bfsQ.size() > 0) {
        u = bfsQ.front();
        bfsQ.pop();

        for (int v = 1; v < end; v++) {
            // Check if theres an edge that you havent visited
            if (G[u][v] == 1 && visited[v] == 0) {
                cout << v << " ";
                visited[v] = 1;
                bfsQ.push(v); 
            }
        }
    }
}

void dfsRec(int G[][8], int start, int n) {
    int u = start; // set starting point
    static int visited[8] = {0}; // static so we can use it in every call

    if (visited[u] == 0) { // process the vertex
        cout << u << " ";
        visited[u] = 1;
        for (int v = 1; v < n; v++) {
            if (G[u][v] == 1 && visited[v] == 0) {
                dfsRec(G, v, n); // process adjacent vertexes
            }
        }
    }
}

void dfs(int u, int G[][8], int n) {
    int visited[8] = {0};
    stack<int> dfsStack;
    dfsStack.push(u); // Push starting vertex

    while (!dfsStack.empty()){
        // Get the top of the stack
        u = dfsStack.top();
        dfsStack.pop();

        // Check if vertex is visited
        if (visited[u] == 0){
            // Process vertex
            cout << u << " ";
            visited[u] = 1;

            // Check adjacent vertexes
            for (int v = n - 1; v >= 0; v--){
                // Check if that adjacent vertex is not visited (u, v)
                if (G[u][v] == 1 && visited[v] == 0)
                    dfsStack.push(v);
            }
        }
    }
}

int main() {
    int G[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
    
    dfsRec(G, 1, 8);
    cout << endl;
    dfs(1, G, 8);
    cout << endl;
    return 0;
}