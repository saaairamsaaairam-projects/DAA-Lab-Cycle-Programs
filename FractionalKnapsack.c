#include<stdio.h>
#define Max 50

int main(){
    double profit[Max], weight[Max], ratio[Max], fract[Max];
    int n, i, j, t;
    double capacity, remaining, total=0, dtemp;
    int id[Max];

    printf("Enter number of items: ");
    scanf("%d",&n);

    if(n<1 || n>Max){
        printf("Invalid number of items\n");
        return 1;
    }

    printf("enter profits of %d items: ",n);
    for(int i=0; i<n; i++){
        scanf("%lf",&profit[i]);
    }

     printf("\nenter weights of %d items: ",n);
    for(int i=0; i<n; i++){
        scanf("%lf",&weight[i]);
        if(weight[i]<=0){
            printf("Weight cannot be negative");
            return 1;
        }
    }

    printf("Enter Knapsack capacity: ");
    scanf("%lf", &capacity);

    if(capacity<0){
        printf("Capacity must be positive\n");
        return 1;
    }

    for(int i=0; i<n; i++){
        ratio[i]=profit[i]/weight[i];
        id[i]= i+1;
        fract[i]=0.0;
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(ratio[j]>ratio[i]){
                dtemp = ratio[i]; 
                ratio[i]= ratio[j];
                ratio[j]= dtemp;

                dtemp = profit[i]; 
                profit[i]= profit[j];
                profit[j]= dtemp;

                dtemp = weight[i]; 
                weight[i]= weight[j];
                weight[j]= dtemp;

                t=id[i];
                id[i]=id[j];
                id[j]=t;
            }
        }
    }

    remaining = capacity;
    for(i=0; i<n && remaining>0; i++){
        if(weight[i]<=remaining){
            fract[i]=1.0;
            remaining-=weight[i];
            total+=profit[i];
        }else{
            fract[i]=remaining/weight[i];
            total+=profit[i]*fract[i];
            remaining =0;
        }
    }

    printf("\nItem Profit Weight Ratio Fraction taken\n");
   for (i = 0; i < n; i++) {
        printf("%-5d %-7.2f %-7.2f %-7.3f %.3f\n", id[i], profit[i], weight[i], ratio[i], fract[i]);
    }

    printf("\nMaximum total profit = %.2f\n", total);
    return 0;
}
