#include <iostream>
using namespace std;
#define MAXN 100005
int a[MAXN];
int dpup[MAXN];
int dpdown[MAXN];
int main(){
	int n;
	cin >> n;
	for(int i =1 ;i <= n; i++){
		cin >> a[i];
		dpup[i] = 1;
		dpdown[i] = 1;
	}
	int ans =1;
	for(int i = 1;i <= n;i++){
		for(int j = 1; j <i; j++){
			if(a[j] < a[i]){
				dpup[i] = max(dpup[i],dpdown[j] +1 );
			}else{
				dpdown[i] = max(dpdown[i] ,dpup[j] +1 );
			}
		}
		ans = max(ans , max(dpup[i] ,dpdown[i] ));
	}
    cout << ans;
	return 0;
}
