#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
typedef struct {
    int u, v, weight;
} Edge;

// Structure to represent a disjoint set (Union-Find)
typedef struct {
    int parent[MAX];
    int rank[MAX];
} DisjointSet;

// Function to initialize the disjoint set
void initSet(DisjointSet *ds, int n) {
    int i;
    for (i = 0; i < n; i++) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }
}

// Find function with path compression
int find(DisjointSet *ds, int x) {
    if (ds->parent[x] != x) {
        ds->parent[x] = find(ds, ds->parent[x]);
    }
    return ds->parent[x];
}

// Union function by rank
void unionSets(DisjointSet *ds, int x, int y) {
    int rootX = find(ds, x);
    int rootY = find(ds, y);
    
    if (rootX != rootY) {
        if (ds->rank[rootX] > ds->rank[rootY]) {
            ds->parent[rootY] = rootX;
        } else if (ds->rank[rootX] < ds->rank[rootY]) {
            ds->parent[rootX] = rootY;
        } else {
            ds->parent[rootY] = rootX;
            ds->rank[rootX]++;
        }
    }
}

// Comparator function for sorting edges based on weight
int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

// Kruskal's algorithm to find MST
void kruskal(Edge edges[], int n, int m) {
    DisjointSet ds;
    int i, j;
    initSet(&ds, n);
    
    qsort(edges, m, sizeof(Edge), compareEdges); // Sort edges by weight
    
    int mstWeight = 0;
    int mstEdges = 0;
    printf("Edges in the MST:\n");

    for (i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        
        // Check if including this edge forms a cycle
        if (find(&ds, u) != find(&ds, v)) {
            printf("%d - %d (weight: %d)\n", u, v, edges[i].weight);
            mstWeight += edges[i].weight;
            mstEdges++;
            unionSets(&ds, u, v);
        }
        
        // If we've added n-1 edges, the MST is complete
        if (mstEdges == n - 1) {
            break;
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    int n, m;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    Edge edges[m];
    
    printf("Enter the edges (u, v, weight):\n");
    int i;
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    
    kruskal(edges, n, m);
    
    return 0;
}
