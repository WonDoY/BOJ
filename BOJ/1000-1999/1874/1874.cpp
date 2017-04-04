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
        if(cnt == t){ // �Է��� ������ �׽�Ʈ�� ũ�Ⱑ ���ٸ� ����
            break;
        }// end
         
        if(input[cnt] == num){ // �Է¹��� �ε����� ��ġ�� ����, num�� ���ٸ�
             
            s.push(num++);      // �ְ�
            s.pop();                    // ����
            cnt++;                  // ���� �ε�����
             
        }else if(input[cnt] < num){ // �Է¹��� �ε����� ��ġ�� ������ num�� �� ũ�ٸ�, ������
 
            int temp = s.pop(); // ����           
            if(temp != input[cnt]){ // ���� ���� �Է¹��� �ε����� ��ġ�� ���� ���� �ʴٸ�
                s.setAnsFalse(false);   // NO�� ����ϱ����� false �� ����
                break;                          // end
            }
            cnt++;      // �´� ����� ���� �ε��� �� ����
 
        }else{ // �Է¹��� �ε����� ��ġ�� ������ �۴ٸ� �״�� Ǫ��
 
            s.push(num++); // Ǫ��            
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