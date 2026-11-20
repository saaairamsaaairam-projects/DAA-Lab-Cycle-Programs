#include<stdio.h>
#define Max 100

void merge(int a[], int low, int mid, int high){
	int temp[Max];
	int i=low;
	int j=mid+1;
	int k=low;
	int x;

	while(i<=mid && j<=high){
		if(a[i]<a[j]){
			temp[k++]=a[i++];
		}
		else{
			temp[k++] = a[j++];
			}

	}
	while(i<=mid){
		temp[k++]=a[i++];
	}
	while(j<=high){
		temp[k++] = a[j++];
	}

	for(x=low; x<=high;x++){
		a[x]=temp[x];
	}
}
	
void mergeSort(int a[], int low, int high){
	int mid;
	if(low>=high){
		return;
	}

	mid = (low+high)/2;
	mergeSort(a,low,mid);
	mergeSort(a,mid+1,high);
	merge(a,low,mid,high);
}

int main(){
int a[Max], n, i;
printf("Enter n value : ");
scanf("%d",&n);

if(n<1 || n>Max){
	printf("Invalid number of elements");
	return 1;
}

printf("Enter %d elements:",n);
for(int i=0; i<n; i++){
	scanf("%d",&a[i]);
}

printf("Merge Sort started\n");
mergeSort(a,0,n-1);

printf("Sorted list: \n");
for(int i=0; i<n;i++){
	printf("%d",a[i]);
	printf("\n");
}

	return 0;
}
