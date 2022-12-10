/**------------------------------Question--------------------------------**/

/*
Problem
Read problems statements in Mandarin Chinese and Russian.
You are given an array A of integers of size N. You will be given Q queries where each query is represented by two integers L, R. You have to find the gcd(Greatest Common Divisor) of the array after excluding the part from range L to R inclusive (1 Based indexing). You are guaranteed that after excluding the part of the array remaining array is non empty.
Input
First line of input contains an integer T denoting number of test cases.
For each test case, first line will contain two space separated integers N, Q.
Next line contains N space separated integers denoting array A.
For next Q lines, each line will contain a query denoted by two space separated integers L, R.
Output
For each query, print a single integer representing the answer of that query.
Constraints
Subtask #1: 40 points

2 ≤ T, N ≤ 100, 1 ≤ Q ≤ N, 1 ≤ A[i] ≤ 10^5
1 ≤ L, R ≤ N and L ≤ R

Subtask #2: 60 points

2 ≤ T, N ≤ 10^5, 1 ≤ Q ≤ N, 1 ≤ A[i] ≤ 10^5
1 ≤ L, R ≤ N and L ≤ R
Sum of N over all the test cases will be less than or equal to 106.
Warning : Large IO(input output), please use faster method for IO.

link ::https://www.codechef.com/problems/GCDQ
*/
/**------------------------------Method : 1 --------------------------------**/

#include<iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,q;
	    cin>>n>>q;
	    int a[n];
	    for(int i=1;i<=n;++i){
	        cin>>a[i];
	    }
	    while(q--){
	        int l,r,gc=0;
	        cin>>l>>r;
	        for(int i=1;i<=l-1;++i){
	        gc=__algo_gcd(gc,a[i]);
	    }
	     for(int i=r+1;i<=n;++i){
	        gc=__algo_gcd(gc,a[i]);
	    }
	    cout<<gc<<endl;
	    }
	}
	return 0;
}




/**-------------------------------Method : 2 ---------------------------------**/
  
#include<iostream>
using namespace std;
const int N=1e5+10;
int main() {
int forward[N];
int backward[N];
	int t;
	cin>>t;
	while(t--){
	    int n,q;
	    cin>>n>>q;
	    int a[n];
         forward[0]=backward[n-1]=0;
	    for(int i=1;i<=n;++i){
	        cin>>a[i];
	    }
          for(int i=1;i<=n;++i){
	        forward[i]=__algo_gcd(forward[i-1],a[i]);
	    }
	     for(int i=n;i>=1;--i){
	        backward[i]=__algo_gcd(backward[i+1],a[i]);
	    }
	    while(q--){
	        int l,r;
	        cin>>l>>r;	   
	       cout<< __algo_gcd(forward[l-1],backward[r+1])<<endl;
	    }
	}
	return 0;
}