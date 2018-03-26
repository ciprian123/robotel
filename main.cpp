#include <iostream>

using namespace std;

void numar_obiecte(unsigned int n, unsigned int &nr)
{
	int j = n, i = j / 2 + 1, k = 1, a[101][101], tmp = n * n;

	for (int i = 0; i <= n + 1; ++i)
		for (int j = 0; j <= n + 1; ++j) a[i][j] = 0;

	a[i][j] = 1;
	while (k <= tmp)
	{
		if (i - 1 >= 1 && j + 1 <= n && !a[i - 1][j + 1])
			a[i - 1][j + 1] = 1 + a[i][j], i--, j++;
		else if (j == n && i - 1 >= 1 && !a[i - 1][1])
			a[i - 1][1] = 1 + a[i][j], j = 1, i--;
		else if (i == 1 && j + 1 <= n && !a[n][j + 1])
			a[n][j + 1] = 1 + a[i][j], i = n, j++;
		else if (i == 1 && j == n && !a[n][1])
			a[n][1] = 1 + a[i][j], i = n, j = 1;
		else
			a[i][j - 1] = 1 + a[i][j], j--;

		k++;
	}

	nr = 0;
	for (unsigned int i = 1; i <= n; ++i)
		nr += a[i][i];
}

int main()
{
	unsigned int n;
	unsigned int nr;

	cin >> n;
	numar_obiecte(n, nr);

	cout << nr;
	return 0;
}

	


