#include <iostream>

using namespace std;

void change2D(string ** array_root, int row, int col, string value);
void load2D(string ** array_root, int row, int col, string value);
void print2D(string ** array_root, int row, int col);

int main()
{
  // read values
  int row =6, col= 4;
  
  // create 2D array
  string** array_root = new string*[row];
  string* array_data = new string[row*col];
  for (int i = 0; i < row; ++i)
    array_root[i] = array_data + col*i;
    
  // initialize to any string value
  load2D(array_root, row, col, "0");
  
  // print before edits
  cout <<"-BEFORE-"<< endl;
  print2D(array_root, row, col);
  
  // make changes
  change2D(array_root, 1, 1, "X");
  change2D(array_root, 2, 2, "X");
  change2D(array_root, 3, 3, "X");
  change2D(array_root, 4, 1, "X");
  
 
  // print after edits
  cout <<"-AFTER-"<< endl;
  print2D(array_root, row, col);
  cout <<"-------"<< endl;
   

  // get rid of array to avoid memory leaks
  delete[] array_root;
  delete[] array_data;
 
  return 0;
}

void change2D(string ** array_root, int row, int col, string value){
    array_root[row][col] = value;
}

void load2D(string ** array_root, int row, int col, string value){
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
             array_root[i][j] = value;
    }
}

void print2D(string ** array_root, int row, int col){
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
             cout << array_root[i][j] << " ";
        }
        cout << endl;
    }
}
