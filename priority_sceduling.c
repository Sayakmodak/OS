#include<stdio.h>

int main(){
    int n,indexofmin,temp;
    int prt[50],bt[50],wt[50],tat[50];
    float twt=0.0,ttat=0.0;
    printf("Enter the number of processes: \n");
    scanf("%d",&n);
    printf("\nEnter priority of the processes\n");
    for(int i=0;i<n;i++){
        scanf("%d",&prt[i]);
    }
    printf("\nEnter burst time of the processes\n");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    for(int i=0;i<n;i++){
        indexofmin = i;
        for(int j=i+1;j<n;j++){
            if(prt[j]<prt[indexofmin]){
                indexofmin = j;
            }
        }
        // Swapping between prt[indexofmin] and prt[i]
        temp = prt[indexofmin];
        prt[indexofmin] = prt[i];
        prt[i] = temp;

        temp = bt[indexofmin];
        bt[indexofmin] = bt[i];
        bt[i] = temp;
    }
    // Calculating waiting time
    for(int i=0;i<n;i++){
        wt[0] = 0;
        wt[i] = wt[i-1] + bt[i-1];
    }
    // Calculating turn around time
    for(int i=0;i<n;i++){
       tat[i] = wt[i] + bt[i];
    }
    // Calculating total waiting time
    for(int i=0;i<n;i++){
        twt = twt + wt[i];
    }
    // Calculating total turn around time
    for(int i=0;i<n;i++){
        ttat = ttat + tat[i];
    }
    printf("\nProcesses\tBurst Time\tPriority\tWaiting Time\tTurn Around Time");
    for(int i=0;i<n;i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i+1,bt[i],prt[i],wt[i],tat[i]);
        printf("\n");
    }

    printf("Average wt is %.2f ",twt/n);
    printf("Average tat is %.2f ",ttat/n);
    return 0;
}