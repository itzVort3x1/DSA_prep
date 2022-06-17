#include <iostream>
using namespace std;

void reachHome(int src, int dest)
{
     cout << "source " << src << " destination " << dest << endl;
     // reach destination
     if (src == dest)
     {
          cout << "Reached destination" << endl;
          return;
     }

     return reachHome(src + 1, dest);
}

int main()
{
     int dest = 10;
     int src = 1;

     reachHome(src, dest);

     return 0;
}