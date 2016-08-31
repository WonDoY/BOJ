#include<cstdio>
int output[10000] = { 0, };
void solve(){
	
    int i;
    int self, temp;
    for(i = 0 ; i < 10000; i++){
        self = i+1;
        while(self <= 10000){
            temp = self;
            while (self >= 1){
                temp += self%10;
                self = self/10;
            }
            self = temp;
            output[self-1] = 1;
        }
    }
}
void solve_print(){
    int i ;
    for(i = 0 ; i < 10000; i++){
        if(!output[i]){
            printf("%d ",i+1);
        }
    }
}
int main(){
    solve();
    solve_print();
    
    return 0;
}