#include<cstdio>

int main(){
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    printf("%d\n%d\n%d\n%d\n",(A+B)%C,(A%C + B%C)%C,  (A*B)%C, (A%C * B%C)%C);
    // (A+B)%C, ��° �ٿ� (A%C + B%C)%C, ��° �ٿ� (A��B)%C, ��° �ٿ� (A%C �� B%C)%C
    return 0;
}