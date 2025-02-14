#include <stdio.h>
void Bubblesort(int arr[], int n){
	for(int i=0;i<n-1;++i){ // the largest element is sorted to the end
		for(int j=0;j<n-i-1;++j){ // all the i elements from the end are already sorted
			if(arr[j]>arr[j+1]){ // to sort into ascending, if out of order, swap
				int temp=arr[j+1]; // swap code
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	Bubblesort(arr,n); // time complexity : worst case 0(n^2), ebst case O(n) : array is already sorted
	for(int i=0;i<n;++i){ // space complexity : O(1), no extra storage is used 
		printf("%d ",arr[i]); // print the sorted array
	}
	return 0;
}