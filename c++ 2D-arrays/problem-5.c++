//------------------------------------
//      Spiral print
//      Ex: INPUT: n = 3 4 11
//                     2 12 1 
//                     7 8  7
//          OUTPUT: 3 4 11 1 7 8 7 2 12 
//------------------------------------

// vector<int> ans;
//         int row = matrix.size();
//         int col = matrix[0].size();
        
//         int count = 0;
//         int total = row*col;
        
         // index initialisation
//         int startingRow = 0;
//         int startingCol = 0;
//         int endingRow = row-1;
//         int endingCol = col-1;
        
//         while(count < total){
            
             //print start row
//             for(int index = startingCol; count < total && index<=endingCol; index++){
//                 ans.push_back(matrix[startingRow][index]);
//                 count++;
//             }
//             startingRow++;
            
             //print ending column
//             for(int index = startingRow; count < total && index<=endingRow; index++){
//                 ans.push_back(matrix[index][endingCol]);
//                 count++;
//             }
            
//             endingCol--;
            
             // print ending row
//             for(int index = endingCol; count < total && index>=startingCol; index--){
//                 ans.push_back(matrix[endingRow][index]);
//                 count++;
//             }
            
//             endingRow--;
            
             //pring starting col 
//             for(int index = endingRow; count < total && index>=startingRow; index--){
//                 ans.push_back(matrix[index][startingCol]);
//                 count++;
//             }
//             startingCol++;
            
//         }
//         return ans;