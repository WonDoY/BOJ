#include<cstdio>

int main(){
    int N,X,i;
    int num[10000];
    scanf("%d %d", &N, &X);
    
    for(i=0; i < N ; i++){
        scanf("%d ", &num[i]);
    }
    for(i=0 ; i < N ; i++){
        if(num[i] < X){
            printf("%d ",num[i]);
        }        
    }    
    
    return 0;
}