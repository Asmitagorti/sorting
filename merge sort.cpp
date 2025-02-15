#include <stdio.h>
void merge(int arr[], int start, int mid, int end){
	int i=start,j=mid+1,k=0; // i iterates through the first part, j iterates through the second part, 
	//k is for the indeces of B
	int B[end-start+1]; // suppose: arr[]={1,2,3,4,5}, end indice=4, start indice=0: size=4-0+1, size=5
	// this avoids calling n as the argument
	while(i<=mid && j<=end){ // iterating through the individual parts
		if(arr[i]<arr[j]){ // sorting logic: ascending: smallest first
			B[k++]=arr[i++]; // we add the elements in arr[i] to B array
		}
		else B[k++]=arr[j++]; // if arr[i]>arr[j], the smallest is arr[j], hence we add it to B array
	}
	while(i<=mid){ // second part is already sorted, remaining elements in first part, are added to B
		B[k++]=arr[i++];
	}
	while(j<=end){ // first part is already sorted, remaining elements in second part, are added to B
		B[k++]=arr[j++];
	}
	k=0;
	for(int i=start;i<=end;++i){
		arr[i]=B[k++];
	}
}
void merge_divide(int arr[], int start, int end){
	if(start>=end) return; // base call: when we reach a single element array, it is already sorted
	int mid=start +(end-start)/2; // calculating mid, avoids overflow with numbers
	merge_divide(arr,start,mid); // recursively divides left part of array
	merge_divide(arr,mid+1,end); // recursively divided right part of array
	
	merge(arr,start,mid,end); // merges both the parts, and sorts them
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	merge_divide(arr,0,n-1); // time complexity: worst case O(nlogn), logn: recursion, n: merge
	//space complexity : O(n), for temporary array B, of size n
	for(int i=0;i<n;++i){
		printf("%d ",arr[i]); // printing the sorted array
	}
	return 0;
}