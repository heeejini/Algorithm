// 두스티커 16937번 
#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> stickers; 
int find_sticker(int h, int w){
    int temp=0;

    for(int i=0; i<n; i++){
        int r1= stickers[i].first;
        int c1= stickers[i].second;

        for(int j=i+1; j<n; j++){
         int r2= stickers[j].first;
         int c2= stickers[j].second;
        // 옆으로 붙일 때 (둘 다 그대로 붙임, 1만 90도 회전, 2만 90도 회전, 둘다 90도 회전)
         if( (r1+r2<=h&&max(c1,c2)<=w) || (r1+c2<=h && max(c1,r2)<=w)
            || (c1+r2<=h&& max(r1,c2)<=w) ||(c1+c2<=h && max(r1,r2)<=w) )
            {
                temp = max(temp, (r1*c1)+(r2*c2));
         }
         else if((r1+r2<=w&& max(c1,c2)<=h) || (c1+r2<=w && max(r1,c2)<=h)
            || (r1+c2<=w&& max(c1,r2)<=h) ||(c1+c2<=w && max(r1,r2)<=h )) {
        // 위아래로 붙일 때 (둘 다 그대로 붙임, 1만 90도 회전, 2만 90도 회전, 둘다 90도 회전)
                temp = max(temp, (r1*c1)+(r2*c2));
            }
        
    
        }
    }
    return temp;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int h,w;
    cin >> h >> w >>n;

    stickers.resize(n);
    for(int i = 0; i < n; i++) {
        // first == r, second == c
        cin >> stickers[i].first >> stickers[i].second;
    } // n개 중에서 2개만 뽑아서 

    int result = find_sticker(h,w);
    cout << result;

}