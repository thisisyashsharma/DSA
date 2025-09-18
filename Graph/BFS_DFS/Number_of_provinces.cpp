class DisjointSet {
public:
    vector<int> parent, rank, size;

    // 1. re-init the parent, rank, size to n+1;
    DisjointSet(int n) {
        parent.resize(n + 1, 0);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // 2. init findParent function
    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // updating the parent;
    }

    // 3.1 init unionByRank function
    void unionByRank(int u, int v) {
        // 1. find roots of v & u
        int rootu = findParent(u);
        int rootv = findParent(v);

        // 2. if same roots of v & u
        if (rootu == rootv)
            return;

        // 3. if diff root of v & u  - then union v & u based on their rank
        if (rank[rootu] < rank[rootv]) {
            parent[rootu] = rootv;
        } else if (rank[rootu] > rank[rootv]) {
            parent[rootv] = rootu;
        } else {
            parent[rootv] = rootu;
            rank[rootu]++;
        }
    }

    // 3.2 init unionBySize function
    void unionBySize(int u, int v) {
        // 1. find root v & u;
        int rootu = findParent(u);
        int rootv = findParent(v);

        // 2. if same root of v & u
        if (rootv == rootu)
            return;

        // 3. if diff root of v & u - then union v & u based on the their size
        if (size[rootv] < size[rootu]) {
            parent[rootv] = rootu;
            size[rootu] += size[rootv];
        } else {
            parent[rootu] = rootv;
            size[rootv] += size[rootu];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        DisjointSet dsu(n);

        // 1. init DisjointSet directly from Matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0 ; j < n ; j++) {
                if( !isConnected[i][j]) continue;  
                dsu.unionBySize(i, j);
            }
        }

        int provinces = 0;
        // 2. increment provinces if nodes are parent of itself
        for (int i = 0 ; i < n ; i++) {
            if (dsu.findParent(i) == i)
                provinces++;
        }

        return provinces;
    }
};
