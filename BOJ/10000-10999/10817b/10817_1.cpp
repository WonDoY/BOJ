#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int n1,n2,n3,max, mid, min;
    scanf("%d %d %d", &n1, &n2, &n3);
    max = n1;
    if(n2 > n3){
        mid = n2;
        min = n3;
    }else{
        mid = n3;
        min = n2;
    }
    if(max < n2){
        max = n2;
        if(n1 > n3){
            mid = n1;
            min = n3;
        }else{
            mid = n3;
            min = n1;
        }
    }
    if(max < n3){
        max = n3;
        if(n1 > n2){
            mid = n1;
            min = n2;
        }else{
            mid = n2;
            min = n1;
        }
    }
    printf("%d\n", mid);
    return 0;
}