
#include <stdio.h>
bool isSubsetSum(int set[], int n, int sum)
{
	
	bool t[n + 1][sum + 1];
	for (int i = 0; i <= n; i++)
		t[i][0] = true;
	for (int i = 1; i <= sum; i++)
		t[0][i] = false;

	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < set[i - 1])
				t[i][j] = t[i - 1][j];
			if (j >= set[i - 1])
				t[i][j] = t[i - 1][j]
							|| t[i - 1][j - set[i - 1]];
		}
	}

	return t[n][sum];
}

int main()
{
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 9;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		printf("Found a subset with given sum");
	else
		printf("No subset with given sum");
	return 0;
}
