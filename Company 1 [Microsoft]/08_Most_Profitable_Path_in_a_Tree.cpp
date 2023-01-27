class Solution
{
public:
private:
   vector<vector<int>> adj;
   vector<int> dis, par;

public:
   void dfs1(int src, int p, int d)
   {
      par[src] = p;
      dis[src] = d;

      for (auto x : adj[src])
      {
         if (x != p)
         {
            dfs1(x, src, d + 1);
         }
      }
   }

   int dfs2(int src, vector<int> &amount, int p)
   {
      int ans = INT_MIN;

      for (auto x : adj[src])
      {
         if (x != p)
         {
            ans = max(ans, dfs2(x, amount, src));
         }
      }
      if (ans == INT_MIN)
      {
         return amount[src];
      }
      return amount[src] + ans;
   }
   int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
   {
      int n = amount.size();
      adj.resize(n, vector<int>());
      for (auto x : edges)
      {
         adj[x[0]].push_back(x[1]);
         adj[x[1]].push_back(x[0]);
      }

      dis.resize(n);
      par.resize(n);

      dfs1(0, -1, 0);
      int cur = bob;
      int bob_move = 0;
      while (cur != 0)
      {
         if (dis[cur] > bob_move)
         {
            amount[cur] = 0;
         }
         else if (dis[cur] == bob_move)
         {
            amount[cur] = amount[cur] / 2;
         }
         bob_move++;
         cur = par[cur];
      }
      return dfs2(0, amount, -1);
   }
};