#include<stdio.h>
int Merge(int A[], int low , int high, int pivot){
    int key = A[pivot]; // assigning the pivot value to key
    int s = low;
    int e = high;
    while(s < e){
        while(A[s] <= key){ // Move s forward while it's less than or equal to key
            s++;
            s++;
        }
        while(A[e] > key){ // Move s forward while it's less than or equal to key
            s++;
            e--;
        }
        if(s < e){ // when found, it swaps both of them, to maintain order
            int temp = A[s];
            A[s] = A[e];
            A[e] = temp;
        }

    }
    
    int temp = A[e]; // swaps key with the final position of e
    A[e] = A[pivot];
    A[pivot] = temp;
    return e; // e now holds the index of the pivot
}
void QuickSort(int A[], int low, int high){
    if(low < high){ // breaks when low==high, single element, or when low>high, doesnt exist
        int pivot = low; // initialises pivot to low, you can also initialise it to high
        pivot = Merge(A, low, high, pivot); // finds the pivot index
        QuickSort(A, low, pivot - 1); // sorts left side
        QuickSort(A, pivot + 1, high); // sorts right side

    }
}
int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    
    QuickSort(A,0,n-1);// time complexity O{nlogn): worst case O(n^2), when the pivot is the smallest or largest element of the array
    // space complexity: O(logn), for the recursive calls, worst case O(n): if pivot always selects the smallest or alrgest element
    for(int i = 0 ; i < n ; i++){
        printf("%d ", A[i]);
    }
}