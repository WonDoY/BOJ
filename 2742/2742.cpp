#include<cstdio>

int main(){
    int input, output;
    
    scanf("%d", &input);
    
    output = input ;
    
    while(input--){
        printf("%d\n", output);
        output--;
    }
    return 0;
}