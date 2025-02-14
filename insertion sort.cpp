#include <stdio.h>
void insertion(int arr[], int n){
	for(int i=1;i<n;++i){ // assuming the first element is sorted
		int key=arr[i]; // key stores the element that we want to place
		int j=i-1; // stores the index of the last element in the sorted part
		while(j>=0 && arr[j]>key){ // j>=0 makes sure we dont cross any borders, if current element > key,
		// we need to create space for key, and shift the current element to the next index
			arr[j+1]=arr[j]; // shifting logic
			j--; // allows us to check the previous elements
		}
		arr[j+1]=key; // ensures we place the value key in the array, sorting order is maintained
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	insertion(arr,n); // time complexity: worst case O(n^2), space complexity : O(1), no space used
	for(int i=0;i<n;++i){
		printf("%d ",arr[i]); // printing the sorted array
	}
	return 0;
}