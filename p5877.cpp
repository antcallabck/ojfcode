#include <iostream>
#include <string>
using namespace std;
#define MAXN 1000005
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int next[MAXN];
	string s ;
	string p ;
	cin >> s ;
	cin >> p ;
	int len_p = p.length();
	int len_s = s.length();
	for(int i =0 ;i < len_p ; i ++){
		next[i] = 0;
	}
	for(int i = 1, j =0 ; i < len_p ; i++){
		while(j > 0 && p[i]!=p[j]){
			j = next[j -1];
		}
		if(p[i]==p[j]){
			j++;
		}
		next[i] = j;
	}
	for(int i =0 , j =0 ; i < len_s ; i++ ){
		while(j >0 && s[i] != p[j]){
			j = next[j -1];
		}
		if(s[i] == p[j]){
			j++;
		}
		if(j == len_p){
			cout <<  i - len_p + 2 << endl;
			j = next[j -1];
		}
	}
	for(int i= 0 ;i < len_p ;i ++){
		cout << next[i]<< " ";
	}
	return 0;
}
