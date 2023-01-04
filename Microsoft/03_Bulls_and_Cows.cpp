#include <bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess)
{

   int bulls = 0, cows = 0;
   vector<int> s(10, 0), g(10, 0);
   for (int i = 0; i < secret.size(); i++)
   {
      if (secret[i] == guess[i])
         bulls++;
      else
      {
         s[secret[i] - '0']++;
         g[guess[i] - '0']++;
      }
   }
   for (int i = 0; i < 10; i++)
      cows += min(s[i], g[i]);

   return (to_string(bulls) + "A" + to_string(cows) + "B");
}

// TC --> O(N)
// SC --> O(1)

int main()
{

   cout << getHint("1807", "7810") << endl;

   cout << getHint("1123", "0111") << endl;

   return 0;
}