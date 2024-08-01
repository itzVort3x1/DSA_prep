//------------------------------------
//      First non-repeating character in a stream
//------------------------------------

#include <iostream>
#include <queue>
using namespace std;

int main()
{
     string str = "ababc";

     queue<char> q;
     int freq[26] = {0};

     for (int i = 0; i < str.length(); i++)
     {
          char ch = str[i];
          freq[ch - 'a']++;
          q.push(ch);

          while (!q.empty())
          {
               char frontCharacter = q.front();
               if (freq[frontCharacter - 'a'] > 1)
               {
                    q.pop();
               }
               else
               {
                    cout << frontCharacter << "->";
                    break;
               }
          }
          if (q.empty())
          {
               cout << "#" << "->";
          }
     }

     return 0;
}