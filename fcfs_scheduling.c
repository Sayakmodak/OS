#include<stdio.h>
int main(){
    int n;
    int bt[50], wt[50],tat[50];
    float twt = 0.0;
    float ttat = 0.0;

    printf("Enter the number of processes: \n");
    scanf("%d",&n);

    printf("Enter the burst time of the processes: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }

    printf("The burst time of the processes are: \n");
    for(int i=0;i<n;i++){
        printf("%d ",bt[i]);
    }

    // Calculating the waiting time
    for(int i=0;i<n;i++){
        wt[0] = 0;
        wt[i] = wt[i-1] + bt[i-1] ;
    }

    // Calculating the turn aroud time
    for(int i=0;i<n;i++){
        tat[i] = bt[i] + wt[i];
    }
    printf("\nProcesses\tBurst Tine\tWaiting Time\tTurn Around Time");
    for(int i=0;i<n;i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
        printf("\n");
    }
    //Calculating total waiting time
    for(int i=0;i<n;i++){
        twt = twt + wt[i];
    }
    //Calculating total turn around time
    for(int i=0;i<n;i++){
        ttat = ttat + tat[i];
    }

    printf("Average tat is %.2f ",ttat/n);
    printf("Average wt is %.2f ",twt/n);
    return 0;
}