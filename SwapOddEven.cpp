#include <iostream> 
using namespace std; 
  
// Function to segregate even odd numbers 
void arrayEvenAndOdd(int arr[], int n) 
{ 
  
    // i is the last digit of the even number
    // j is the iterator to find the even number
    int i = -1, j = 0; 

    while (j != n) { 
        if (arr[j] % 2 == 0) { 
            i++; 
  
            // Swapping even and odd numbers 

            // point pointer position
            swap(arr[i], arr[j]); 
            for (int c = 0; c < n; c++){
                if (c == i){
                    cout << "i";
                }
                else if (c == j){
                    cout << "j";
                }
                else{
                    cout << " ";
                }
                cout << " ";
            }
            cout << endl;

            // print actual array:
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " "; 
            }
            cout << endl;
            cout << "Currect i and j: " << i << "   " << j << endl;
        } 
        j++; 
    } 
  
    // Printing segregated array 
    cout << "The Final result is: ";
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 1, 3, 2, 4, 7, 6, 9, 0 }; 
    int n = sizeof(arr) / sizeof(int); 
    arrayEvenAndOdd(arr, n); 
    return 0; 
} 