//------------------------------------
//      Common Elements
//      n1 = 6; A = {1, 5, 10, 20, 40, 80}
//      n2 = 5; B = {6, 7, 20, 80, 100}
//      n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
//      Output: 20 80
//      Explanation: 20 and 80 are the only
//                   common elements in A, B and C.
//------------------------------------

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
     int arr[] = {1, 5, 10, 20, 40, 80};
     int brr[] = {6, 7, 20, 80, 100};
     int crr[] = {3, 4, 15, 20, 30, 70, 80, 120};
     int n1 = 6;
     int n2 = 5;
     int n3 = 8;
     int i, j, k;
     i = j = k = 0;

     vector<int> ans;
     set<int> st;

     while (i < n1 && j < n2 && k < n3)
     {
          if (arr[i] == brr[j] && brr[j] == crr[k])
          {
               st.insert(arr[i]);
               i++;
               j++;
               k++;
          }
          else if (arr[i] < brr[j])
          {
               i++;
          }
          else if (brr[j] < crr[k])
          {
               j++;
          }
          else
          {
               k++;
          }
     }

     for (int it : st)
     {
          ans.push_back(it);
     }

     for (int i = 0; i < ans.size(); i++)
     {
          cout << ans[i] << " ";
     }

     cout << endl;
}