#include<cstdio>

int main(){
    
    
    /*
    첫째 줄에 빈 칸을 사이에 두고 x(1≤x≤12)와 y(1≤y≤31)이 주어진다. 
    참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, ** 31%7 = 4
    4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.30%7 = 3 
    */
    int month, day, result;
    result = 0;// init set 0
    scanf("%d %d", &month, &day);
    
    if(month > 11){ // 1,3,5,7,8,10 - 4 / 4,6,9,11 - 3
        result += 6*3 + 4*2; 
    }else if(month > 10){ // 1,3,5,7,8,10 -4 / 4,6,9 - 3
        result += 6*3 + 3*2;
    }else if(month > 9){ // 1,3,5,7,8 -4 / 4,6,9-3
        result += 5*3 + 3*2;
    }else if(month > 8){ // 1,3,5,7,8 - 4 / 4,6 -3
        result += 5*3 + 2*2;
    }else if(month > 7){ // 1,3,5,7 -4 / 4,6 -3
        result += 4*3 + 2*2;
    }else if(month > 6){ // 1,3,5-4 / 4,6-3
        result += 3*3 + 2*2;
    }else if(month > 5){ // 1,3,5-4 / 4-3
        result += 3*3 + 1*2;
    }else if(month > 4){ // 1,3-4 / 4-3
        result += 2*3 + 1*2;
    }else if(month > 3){ // 1,3-4
        result += 2*3;
    }else if(month > 2){ // 1-4
        result += 1*3;
    }else if(month > 1){ // 1-4
        result += 1*3;
    }    
    result += day;
    
    //첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다
    result = result % 7;
    if(result == 0){
        printf("SUN\n");
    }else if(result == 1){
        printf("MON\n");
    }else if(result == 2){
        printf("TUE\n");
    }else if(result == 3){
        printf("WED\n");
    }else if(result == 4){
        printf("THU\n");
    }else if(result == 5){
        printf("FRI\n");
    }else if(result == 6){
        printf("SAT\n");
    }
    
    return 0;
}