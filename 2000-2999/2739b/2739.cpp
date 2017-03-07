#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int input;
    int index;
    scanf("%d", &input);
    for(index = 1; index < 10 ; index++){
        printf("%d * %d = %d\n", input, index, input*index);
    }
    
    return 0;
}