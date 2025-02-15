#include <stdio.h>
void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int mid_ind = i; // i represents the current position where the next smallest element will be placed
        for (int j = i + 1; j < n; j++) { // we dont check from i, as from i to i, its already sorted
            if (arr[j] < arr[mid_ind]) { // finding the smallest element
                mid_ind = j; // updating the mid_ind, so it can hold the index of the smallest element
            }
        }
        // Swap arr[i] and arr[mid_ind]
        int temp = arr[i];
        arr[i] = arr[mid_ind];
        arr[mid_ind] = temp;
    }
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	SelectionSort(arr,n); // time complexity: O(n^2): 2 for loops
	for(int i=0;i<n;++i){ // space complexity: O(1) no extra space used
		printf("%d ",arr[i]);
	}
	return 0;
}