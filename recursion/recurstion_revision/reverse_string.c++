#include <iostream>
using namespace std;

void reverse(string &str, int i)
{
     if (i > str.length() / 2)
     {
          return;
     }
     swap(str[i], str[str.length() - i - 1]);
     i++;
     reverse(str, i);
}

int main()
{
     string name = "abcde";

     reverse(name, 0);

     cout << name << endl;

     return 0;
}