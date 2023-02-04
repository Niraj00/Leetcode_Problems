#include <iostream>
using namespace std;
bool SubSetSum(int set[], int n, int sum)
{
	if (sum == 0)
		return true;
	if (n == 0)
		return false;
	if (set[n - 1] > sum)
		return SubSetSum(set, n - 1, sum);
	return SubSetSum(set, n - 1, sum)
		|| SubSetSum(set, n - 1, sum - set[n - 1]);
}

int main()
{
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 9;
	int n = sizeof(set) / sizeof(set[0]);
	if (SubSetSum(set, n, sum) == true)
		cout <<"Subset founded with given sum";
	else
		cout <<"No subset with given sum";
	return 0;
}
