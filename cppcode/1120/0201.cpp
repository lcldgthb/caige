#include <bits/stdc++.h>
using namespace std;
const int N=20010;
int a[N];
int cnt;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int b[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
            b[i]=a[i];
        }
        sort(b,b+n);
        for(int i=0;i<n-1;i++){
            int x=a[i]+a[i+1];
            if(x%2==1){
                swap(a[i],a[i+1]);
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]==b[i])
                cnt++;
        }
        if(cnt==n){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
        
    }
    return 0;
}