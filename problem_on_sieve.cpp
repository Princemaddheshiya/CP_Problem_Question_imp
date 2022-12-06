/*problem link :
https://www.hackerearth.com/problem/algorithm/monk-and-divisor-conundrum-56e0eb99/
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N=2e5+10;
    int hsh[N];
    int store[N];
int main(){
int n;
cin>>n;
for (int i = 0; i < n; i++)
{
    int x;
   cin>>x;
   hsh[x]++;
}
for(int i=1;i<N;++i){
    for (int j = 0; j < N; j+=i)
    {
        store[i]+=hsh[j];
    }   
}
int c;
cin>>c;
while(c--){
    int p,q;
    cin>>p>>q;
    long long lcm=(p*1LL*q)/__gcd(p,q);
    long ans =store[p]+store[q];
    if(lcm<N)
ans-=store[lcm];
cout<<ans<<endl;
}
return 0;
}