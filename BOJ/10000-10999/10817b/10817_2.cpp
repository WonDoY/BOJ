#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int arr[3], temp;
    int i, range;
    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
    
    for(range = 2 ; range > 0 ; range--){
        for(i = 0; i < range ;i++){
            if(arr[i] > arr[i+1]){
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
    }
    printf("%d\n", arr[1]);
    return 0;
}