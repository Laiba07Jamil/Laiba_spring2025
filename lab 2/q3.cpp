#include <iostream>
using namespace std;

//function prototype
int sum_of_array(int** array, int rows , int cols);
void sum_of_rows(int** array, int rows , int cols);
void sum_of_columns(int** array, int rows , int cols);
int highest_sum_of_rows(int** array , int rows , int cols);
int highest_sum_of_columns(int** array, int rows , int cols);
void transpose_matrix(int** array , int rows , int cols);

int main(){
   int rows = 3;
   int cols = 3;
   int** array = new int*[rows];
   for(int i = 0 ; i < rows ; i++){
    array[i] = new int[cols];
   }
   for(int i = 0 ; i < rows ; i++){
    for(int j = 0 ; j < cols ; j++){
        cout << "Enter the Elements[" << i+1 <<"]"<<"[" <<j+1  <<"]"<<":";
        cin >> array[i][j];
        if(array[i][j] < 1 || array[i][j] > 100){
            cout << "Sorry limit exceeded:"<< endl;
            j--;
        }
    }
   }
   int sum_of_elements = sum_of_array(array, rows, cols);
   cout << "Sum Of Elemnts: " << sum_of_elements << endl;

   sum_of_rows(array,rows ,cols);
   sum_of_columns(array,rows ,cols);

   int sum_of_highest_row = highest_sum_of_rows(array, rows ,cols);
   cout << "The Highest sum of Rows is :" << sum_of_highest_row <<endl;

   int sum_oF_highest_columns = highest_sum_of_columns(array, rows ,cols);
   cout << "The highest sum of Columns is:" << sum_oF_highest_columns << endl;

   cout << "Transpose Matrix:" <<endl;
   transpose_matrix(array, rows ,cols);

   for(int i = 0 ; i < rows ; i++){
    delete[] array[i];
   }
   delete[] array;
}

int sum_of_array(int** array, int rows , int cols){            //function for sum of array
    int sum = 0;
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            sum += array[i][j];
        }
    }
    return sum;
}

void sum_of_rows(int** array,int rows,int cols){           //function for sum of rows
    int rsum[3] = {0};
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            rsum[i] += array[i][j];
        }
    }
     cout << "-----Sum of Rows-----";
     for(int i = 0 ; i < 3 ; i++){
        cout << "Sum of Row " << i+1 << ":"<< rsum[i] << endl;
     }
}

void sum_of_columns(int** array , int rows , int cols){            //function for sum of columns
    int csum[3] = {0};
    for(int j = 0 ; j < cols ; j++){
        for(int i = 0 ; i < rows ; i++){
            csum[j] += array[i][j];
        }
    }
     cout << "-------Sum of Columns ------:";
     for(int i = 0 ; i < 3 ; i++){
        cout << "Sum of Column " << i+1 << ":"<< csum[i] << endl;
     }
}

int highest_sum_of_rows(int** array, int rows , int cols){        //function for highest sum of rows
    int rsum[3] = {0};
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            rsum[i] += array[i][j];
        }
    }
     int high_sum_of_row = 0;
     for(int i = 0 ; i < 3 ; i++){
        if(rsum[i] > high_sum_of_row){
            high_sum_of_row = rsum[i];
        }
     }
     return high_sum_of_row;
}

int highest_sum_of_columns(int** array, int rows , int cols){       //function for highest sum of columns
    int csum[3] ={0};
    for(int j = 0 ; j < cols ; j++){
        for(int i = 0 ; i < rows ; i++){
            csum[j] += array[i][j];
        }
    }
     int high_sum_of_col = 0;
     for(int i = 0 ; i < 3 ; i++){
        if(csum[i] > high_sum_of_col){
            high_sum_of_col = csum[i];
        }
     }
     return high_sum_of_col;
}

void transpose_matrix(int** array, int rows , int cols){           //function for transpose matrix
    int transpose[3][3];
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
             transpose[j][i] = array[i][j];
        }
    }
    cout << "Transpose Matrix:" << endl;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
}

