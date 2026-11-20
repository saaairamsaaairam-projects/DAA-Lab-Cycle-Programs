#include <stdio.h>
#define Max 100

int partition(int a[], int low, int high){
	int pivot = a[high];
	int i=low-1;
	int j,temp;

	for(int j=low; j<high;j++){
		if(a[j]<pivot){
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}

	temp=a[i+1];
	a[i+1]=high;
	a[high]=temp;

	return i+1;
}

int quickSelect(int a[],int low, int high, int k){
	int p;
	if(low==high){
	     return a[low];
	}

	p = partition(a,low,high);


	if(k-1==p){
            return a[p];
	}
	else if(k-1<p){
		return quickSelect(a,low,p-1,k);
	}
	else{
		return quickSelect(a,p+1,high,k);
	}
}

int main() {
    int a[Max],n,k,i,result;

    printf("Enter number of elemensts: ");
    scanf("%d",&n);

    if(n<1 || n>Max){
        printf("Invalid number of elements.\n");
        return 1;
    }

    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }

    printf("enetr K (1 based): ");
    scanf("%d",&k);

    if(k<1 || k>n){
        printf("Invalid K value");
        return 1;
    }

    result = quickSelect(a,0,n-1,k);
    printf("The %d-th element is %d\n",k,result);

    return 0;
    
}
