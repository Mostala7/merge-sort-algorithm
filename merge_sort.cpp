#include <iostream>
using namespace std; 

void mergeSort (int arr[] , int l , int r) ;
void merge (int arr[] , int l , int m , int r) ;
void print (int arr[] , int size) ;

int main()
{
    int array[] = {3,2,8,7,9,9,9,11} ;
    int s = size (array) ;
    mergeSort(array , 0 , s-1);
    print (array, s) ;
}

void mergeSort (int arr[] , int l , int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2 ;

        mergeSort (arr , l , m) ;
        mergeSort (arr , m+1 , r) ;
        merge (arr , l , m , r) ;
    }
}

void merge (int arr[] , int l , int m , int r)
{
    int i , j , k ;
    int size_1 = m - l + 1 ;
    int size_2 = r - m ;

    int *temp_1 = new int [size_1] ;
    int *temp_2 = new int [size_2] ;

    for (i=0 ; i<size_1 ; i++)
        temp_1[i] = arr[l+i] ;

    for (j=0; j<size_2 ; j++)
        temp_2[j] = arr[m+j+1] ;

    i = j = 0 ;
    k = l ; 
    while (j < size_2 && i < size_1)
    {
        if (temp_1[i] < temp_2[j])
        {
            arr[k] = temp_1[i] ;
            i++ ;
        }
        else {
            arr[k] = temp_2[j] ;
            j++ ;
        }
        k++ ;
    }

    while (i < size_1)
    {
        arr[k] = temp_1[i] ;
        i++ ;
        k++ ;
    }

    while (j < size_2)
    {
        arr[k] = temp_2[j] ;
        j++ ;
        k++ ;
    }
}

void print (int arr[] , int size) 
{
    for (int i=0 ; i<size ; i++)
        cout << arr[i] << " " ;
    cout << endl ;
}
