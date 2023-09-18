//------------------------------------
//      Spiral print
//      Ex: INPUT: n = 3 4 11
//                     2 12 1
//                     7 8  7
//          OUTPUT: 3 4 11 1 7 8 7 2 12
//------------------------------------

#include <iostream>
#include <vector>

using namespace std;

void sprialPrint(int arr[][4], int rows, int cols)
{
    vector<int> ans;
    int row = rows;
    int col = cols;

    int count = 0;
    int total = row * col;

    // index initialisation
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    while (count < total)
    {

        // print start row
        for (int index = startingCol; count < total && index <= endingCol; index++)
        {
            ans.push_back(arr[startingRow][index]);
            count++;
        }
        startingRow++;

        // print ending column
        for (int index = startingRow; count < total && index <= endingRow; index++)
        {
            ans.push_back(arr[index][endingCol]);
            count++;
        }

        endingCol--;

        // print ending row
        for (int index = endingCol; count < total && index >= startingCol; index--)
        {
            ans.push_back(arr[endingRow][index]);
            count++;
        }

        endingRow--;

        // pring starting col
        for (int index = endingRow; count < total && index >= startingRow; index--)
        {
            ans.push_back(arr[index][startingCol]);
            count++;
        }
        startingCol++;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int arr[4][4];

    cout << "Enter your array elements: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    sprialPrint(arr, 4, 4);
}