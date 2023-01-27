class Solution
{
public:
   bool isRectangleCover(vector<vector<int>> &rectangles)
   {
      map<pair<int, int>, int> mp;
      for (auto i : rectangles)
      {
         mp[{i[0], i[1]}]++;
         mp[{i[2], i[3]}]++;
         mp[{i[0], i[3]}]--;
         mp[{i[2], i[1]}]--;
      }
      int cnt = 0;
      for (auto i = mp.begin(); i != mp.end(); i++)
      {
         if (abs(i->second) == 1)
         {
            cnt++;
         }
         else if (abs(i->second) != 1 && i->second != 0)
         {
            return false;
         }
      }
      return cnt == 4;
   }
};