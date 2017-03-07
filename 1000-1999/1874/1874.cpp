#include<cstdio>
 
class stack{
private:
    int data[100001];
    int cnt, ansCnt;
    bool ansFalse;
    char ans[200000];
public:
    stack(){
        cnt = 0;
        ansCnt = 0;
        bool ansFalse = true;
    }
    void push(int i){
        data[cnt++] = i;
        ans[ansCnt++] = '+';
    }
    int pop(){
        if(!empty()){
            ans[ansCnt++] = '-';
            //printf("%d ",data[cnt-1]);
            return data[--cnt];         
        }else{
            ansFalse = false;
        }
    }
    bool empty(){
        if(cnt==0) return true;
        return false;
    }
    bool getAnsFalse(){
        return ansFalse;
    }
    int getAnsCnt(){
        return ansCnt;
    }
    char getAns(int i){
        return ans[i];
    }
    void setAnsFalse(bool i){
        ansFalse = i;
    }
};
 
int main(){
    stack s;
 
    int t, cnt = 0, num = 1;
    int input[100000] = {0};
    scanf("%d", &t);
     
    for(int i = 0 ; i < t ; i++){
        scanf("%d",&input[i]);
    } // input data
 
    while(true){
        if(cnt == t){ // 입력한 갯수와 테스트의 크기가 같다면 종료
            break;
        }// end
         
        if(input[cnt] == num){ // 입력받은 인덱스에 위치한 값과, num가 같다면
             
            s.push(num++);      // 넣고
            s.pop();                    // 꺼냄
            cnt++;                  // 다음 인덱스로
             
        }else if(input[cnt] < num){ // 입력받은 인덱스에 위치한 값보다 num이 더 크다면, 꺼내기
 
            int temp = s.pop(); // 꺼냄           
            if(temp != input[cnt]){ // 꺼낸 값이 입력받은 인덱스에 위치한 값과 같지 않다면
                s.setAnsFalse(false);   // NO를 출력하기위해 false 값 설정
                break;                          // end
            }
            cnt++;      // 맞는 경우라면 다음 인덱스 값 진행
 
        }else{ // 입력받은 인덱스에 위치한 값보다 작다면 그대로 푸쉬
 
            s.push(num++); // 푸쉬            
        }       
    }
 
    if(s.getAnsFalse()){
        int temp = s.getAnsCnt();
        for(int i = 0 ; i < temp ; i++){
            printf("%c\n",s.getAns(i));         
        }
    }else{
        printf("NO\n");
    }
    return 0;
}