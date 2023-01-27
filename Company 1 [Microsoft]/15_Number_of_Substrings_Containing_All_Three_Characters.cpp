class Solution
{
public:
   int numberOfSubstrings(string s)
   {
      int n = s.size();
      int ans = 0;
      int j = 0;
      vector<int> arr(3, 0);
      for (int i = 0; i < n; i++)
      {
         arr[s[i] - 'a']++;
         while (arr[0] > 0 && arr[1] > 0 && arr[2] > 0)
         {
            ans += n - i;
            arr[s[j++] - 'a']--;
         }
      }
      return ans;
   }
};