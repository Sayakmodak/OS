#include<stdio.h>
int main(){
    int n,bt[50],wt[50],p[50],tat[50],temp;
    float twt = 0, ttat = 0;
    printf("Enter the number of processes: \n");
    scanf("%d",&n);

    printf("\nEnter the process number: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }

    printf("\nEnter the burst time of the processes: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }

    printf("\nThe burst time of the processes are: \n");
    for(int i=0;i<n;i++){
        printf("%d ",bt[i]);
    }
    
    for(int i=0;i<n;i++){
        for(int i=0;i<n-i-1;i++){
            if(bt[i]>bt[i+1]){
                 temp = bt[i];
                 bt[i] = bt[i+1];
                 bt[i+1] = temp;

                 temp = p[i];
                 p[i] = p[i+1];
                 p[i+1] = temp;
            }

        }
    }
    

    //Calculating waiting time
    for(int i=0;i<n;i++){
        wt[0] = 0;
        wt[i] = wt[i-1] + bt[i-1];
    }
    //Calculating turn around time
    for(int i=0;i<n;i++){
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcesses\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d ",p[i],bt[i],wt[i],tat[i]);
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
    printf("\nAverage tat is %.2f ",ttat/n);
    printf("\nAverage wt is %.2f ",twt/n);
    return 0;
}