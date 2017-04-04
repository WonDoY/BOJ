#include<cstdio>

int main(){
	char *a = "ascending\0",
		*b = "descending\0",
		*c = "mixed\0";
	int n[8], res = -1;
	for(int i=0 ; i<8;i++){
		scanf("%d",&n[i]);

		if(!i) {
			switch(n[0]){
			case 1: res = 0; break;
			case 8: res = 1; break;
			default: res = 2; break;
			} 
		}

		if(i>0){		
			switch(res){
			case 0: // asc
				(i!=(n[i]-1)) ? res = 2 : false ; break;
			case 1: // desc
				(i!=8-n[i]) ? res = 2 : false ; break;
			case 2: // mix
				break;
			}
		}
	}
	printf("%s",(res!=0)?((res!=1)?c:b):a);

	return 0;
}