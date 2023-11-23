#include <stdio.h>
#include <string.h>

int checkPalindrome(int arr[],int start,int end){
	printf("start: %d,end: %d\n",arr[start],arr[end]);
	if(arr[start] != arr[end]){
		return 0;
	}
	else {
		if (end <= start){
			return 1;
		}
		checkPalindrome(arr,start+1,end-1);
	}
}
// the complexity is O(n)

int main(){
	int arr[] = {3,2,4,1,5,2,3};
	int sizeOfArr = sizeof(arr)/sizeof(arr[0]);
	printf("the array is palindrome: %d\n",checkPalindrome(arr,0,sizeOfArr-1));
	return 0;
}