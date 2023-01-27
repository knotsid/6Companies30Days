class Solution
{
public:
   string longestPrefix(string s)
   {
      int n = s.size();
      int i = 1;
      int len = 0;
      vector<int> arr(n, 0);
      while (i < n)
      {
         if (s[i] == s[len])
         {
            arr[i] = len + 1;
            len++;
            i++;
         }
         else if (len == 0)
         {
            arr[i] = len;
            i++;
         }
         else
         {
            len = arr[len - 1];
         }
      }

      return s.substr(0, arr[n - 1]);
   }
};