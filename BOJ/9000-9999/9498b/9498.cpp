#include<cstdio>

int main(){
    int input;
    scanf("%d",&input);
    if(input > 89){
        printf("A");
    }else if(input > 79){
        printf("B");
    }else if(input > 69){
        printf("C");
    }else if(input > 59){
        printf("D");
    }else{
        printf("F");
    }
    return 0;
}