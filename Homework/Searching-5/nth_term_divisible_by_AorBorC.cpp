#include <bits/stdc++.h>
using namespace std;

int lcm(int a,int b)
{
	return (a*b) /(__gcd(a,b));
}
int checker(int a,int b,int c,int num)
{
    int part1=(num/a)+(num/b)+(num/c);
    int part2=-(num/lcm(a,b))-(num/lcm(b,c))-(num/lcm(a,c));
    int part3=(num/lcm(a,lcm(b,c)));
	return (part1+part2+part3);
}
int findNthTerm(int a,int b,int c,int n)
{
	int low=1,high=1e9,mid;
	while (low<high) {
		mid=low+(high-low)/2;
		if (checker(a,b,c,mid)<n) low=mid+1;
		else high=mid;
	}
	return low;
}
int main()
{
	int a=2,b=3,c=5,n=10;
	cout << findNthTerm(a,b,c,n);
	return 0;
}
