/*<------------- problem -------------------------->*/
/*
Monk is a multi-talented person, and prepares results for his college in his free time. (Yes, he is still in love with his old college!) He gets a list of students with their marks. The maximum marks which can be obtained in the exam is 100.

The Monk is supposed to arrange the list in such a manner that the list is sorted in decreasing order of marks. And if two students have the same marks, they should be arranged in lexicographical manner.

Help Monk prepare the same!

Input format:
On the first line of the standard input, there is an integer N, denoting the number of students. N lines follow, which contain a string and an integer, denoting the name of the student and his marks.

Output format:
You must print the required list.

Constraints:
1 <= N <= 10^5
1 <= | Length of the name | <= 100 
1 <= Marks <= 100
*/

/*<------------------------- code --------------->*/
#include <bits/stdc++.h>
using namespace std;
int main() {
	int num;
	cin >> num;    //Reading input from STDIN
	map<int,multiset<string> > m;
	for(int i=0;i<num;++i){
		string s;
		int n;
		cin>>s>>n;
		m[-1*n].insert(s);
	}
		for(auto pr :m){
		for(auto &se :pr.second){
			cout<<se<<" "<<pr.first*-1<<endl;
		}
 
		}	
}

/*<----------------input ------------------------>*/
3
Eve 78
Bob 99
Alice 78
/*<----------------output ------------------------>*/
Bob 99
Alice 78
Eve 78