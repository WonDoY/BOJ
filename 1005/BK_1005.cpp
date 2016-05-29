#include<iostream>
#include<cstdio>
using namespace std;
// 이름공간 std 사용
int main() {
	int t;
	int bulid_cnt, rule_cnt;
	cin >> t;
	
	while (t--) { 
		int time[1000] = { 0 };
		int result[1000] = { 0 };
		/*
		input case 
		*/
		cin >> bulid_cnt >> rule_cnt;
		int cnt = 0;
		while (cnt < bulid_cnt) {
			cin >> time[cnt];
			result[cnt] = time[cnt++];
		}
		
		
	/*	int From[1000000] = { 0 };
		int To[100000] = {0};*/
		int arr_from[100000], arr_to[100000]; 
		int from, to;
		cnt = 0;
		while (cnt < rule_cnt) {
			cin >> arr_from[cnt] >> arr_to[cnt];
			from = arr_from[cnt]; to = arr_to[cnt];
			int temp = result[from-1] + time[to-1];
			if (temp < result[to-1]) {
				temp = result[to-1];
			}
			result[to-1] = temp;	
			cnt++;
		}
		cout << " 1 ****";
		for (int i = 0; i < bulid_cnt; i++) {
			cout << ", " << result[i];
		}
		cout << endl;
		cnt = 0;
		while (cnt < rule_cnt) {
			from = arr_from[cnt]; to = arr_to[cnt];
			int temp = result[from - 1] + time[to - 1];
			if (temp < result[to - 1]) {
				temp = result[to - 1];
			}
			result[to - 1] = temp;
			cnt++;
		}
		cout << " 2 ****";
		for (int i = 0; i < bulid_cnt; i++) {
			cout << ", " << result[i];
		}
		cout << endl; cnt = 0;
		while (cnt < rule_cnt) {
			from = arr_from[cnt]; to = arr_to[cnt];
			int temp = result[from - 1] + time[to - 1];
			if (temp < result[to - 1]) {
				temp = result[to - 1];
			}
			result[to - 1] = temp;
			cnt++;
		}
		
		int dst;
		cin >> dst;
		cout << result[dst - 1] << endl;
	}
	return 0;

}