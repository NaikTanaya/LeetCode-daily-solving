class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int, int>>adj[n];
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1] , it[2]});
        }

        queue<pair<int, pair<int, int>>>q;  //{stops, {node, cost}}
        q.push({0, {src, 0}});

        vector<int>dist(n, 1e9);
        dist[src] = 0;

        while(!q.empty())
        {
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            q.pop();

            if(stops > k){
                continue;
            }

            for(auto x : adj[node])
            {
                int adjNode = x.first;
                int edW = x.second;

                if(cost + edW < dist[adjNode] && stops <= k)
                {
                    dist[adjNode] = cost + edW;
                    q.push({stops+1, {adjNode, dist[adjNode]}});
                }
            }

        }

        if(dist[dst] == 1e9)return -1;   //not reachable within k stops
        return dist[dst];
    }


    //TC = O(N) AS we are using a queue
    //SC = O(E + V)
};

// Example 1:

// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

// Example 2:

// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
// Output: 200
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

// Example 3:

// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
// Output: 500
// Explanation:
// The graph is shown above.
// The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
