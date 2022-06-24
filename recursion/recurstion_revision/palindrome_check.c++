#include <iostream>
using namespace std;

bool checkPalindrome(string str, int i, int j)
{
     if (i > j)
     {
          return true;
     }
     if (str[i] == str[j])
     {
          i++;
          j--;
          return checkPalindrome(str, i, j);
     }
     else
     {
          return false;
     }
}

int main()
{
     string name = "aabbcbbaa";
     cout << endl;

     bool isPalindrome = checkPalindrome(name, 0, name.length() - 1);

     if (isPalindrome)
     {
          cout << "The given string is palindrome" << endl;
     }
     else
     {
          cout << "The given string is not palindrome" << endl;
     }
}