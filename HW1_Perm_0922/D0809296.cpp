#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void perm(int [], int, int);

int main() {
	int len;
	printf("Please Enter a Number: ");
	scanf("%d",&len);
	int arr[len];
	perm(arr,len,0);
	
}


void perm(int arr[], int len, int i) {

	if(i == len) {
		int j;
		for(j=0; j<len; j++) {
			printf("%d",arr[j]);
		}
		printf("\n");
		return;
	}
	arr[i] = 0;
	perm(arr, len, i+1);
	
	arr[i] = 1;
	perm(arr, len, i+1);
	
}

