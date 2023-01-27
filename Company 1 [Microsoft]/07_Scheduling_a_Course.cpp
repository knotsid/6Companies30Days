class Solution
{
public:
   bool isCycle(int sv, vector<int> adj[], vector<int> &visited)
   {
      if (visited[sv] == 2)
         return true;

      visited[sv] = 2;

      for (auto it : adj[sv])
      {
         if (visited[it] != 1)
            if (isCycle(it, adj, visited))
               return true;
      }
      visited[sv] = 1;
      return false;
   }

   bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
   {
      vector<int> adj[numCourses];

      for (auto edge : prerequisites)
      {
         adj[edge[1]].push_back(edge[0]);
      }

      vector<int> visited(numCourses, false);

      for (int i = 0; i < numCourses; ++i)
      {
         if (isCycle(i, adj, visited))
            return false;
      }
      return true;
   }
};