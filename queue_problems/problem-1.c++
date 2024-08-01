//------------------------------------
//      Print the first negative numbers in k size
//------------------------------------

#include <iostream>
#include <queue>
#include <deque>
using namespace std;

void printFirstNegative(int *arr, int n, int k)
{
     deque<int> dq;

     // process first k elements

     for (int i = 0; i < k; i++)
     {
          int element = arr[i];
          if (element < 0)
          {
               dq.push_back(i);
          }
     }

     // process remaining windows -> Removal and addition

     for (int index = k; index < n; index++)
     {
          if (dq.empty())
          {
               cout << "0 " << endl;
          }
          else
          {
               cout << arr[dq.front()] << " ";
          }
          // aage badhne se pehle purani window ka answer nikaldo

          // removal
          if (index - dq.front() >= k)
          {
               dq.pop_front();
          }

          if (arr[index] < 0)
          {
               dq.push_back(index);
          }
     }

     // last window answer
     if (dq.empty())
     {
          cout << "0 " << endl;
     }
     else
     {
          cout << arr[dq.front()] << " ";
     }
}

int main()
{
     int arr[] = {2, -5, 4, -1, -2, 0, 5};
     int size = 7;
     int k = 3;

     printFirstNegative(arr, size, k);
}