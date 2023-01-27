#define ll long long
class Solution
{
   int mod = 1000000007;

public:
   int countPaths(int n, vector<vector<int>> &roads)
   {

      vector<vector<ll>> adj[n];
      for (auto &i : roads)
      {
         adj[i[0]].push_back({i[1], i[2]});
         adj[i[1]].push_back({i[0], i[2]});
      }
      vector<ll> dist(n, LONG_MAX);
      vector<ll> ways(n, 0);
      priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
      dist[0] = 0;
      ways[0] = 1;
      pq.push({0, 0});
      while (!pq.empty())
      {
         auto [dis, node] = pq.top();
         pq.pop();

         if (dis > dist[node])
            continue;
         for (auto &i : adj[node])
         {
            ll weight = i[1];
            ll adjNode = i[0];
            if (dis + weight < dist[adjNode])
            {
               dist[adjNode] = dis + weight;
               ways[adjNode] = ways[node] % mod;
               pq.push({dist[adjNode], adjNode});
            }
            else if (dis + weight == dist[adjNode])
            {
               ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
         }
      }
      return ways[n - 1];
   }
};