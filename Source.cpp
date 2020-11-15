#include <stdio.h>
double a[100][100] = { 0 };
double g[100][100] = { 0 };
int i;
void FindZero(int n)
{
	double v;
	if (a[i][i] == 0)
		for (int j = i + 1; j < n; j++)
			if (a[j][i] != 0)
			{
				for (int k = 0; k < n; k++)
				{
					v = a[i][k];
					a[i][k] = a[j][k];
					a[j][k] = v;
				}
				break;
			}
}
double Gaus(int n)
{
	double sum = 1;
	double v;
	int g = 0;
	i = 0;
	while (i < n - 1)
	{
		FindZero(n);
		if (a[i][i] == 0)
		{
			g = 1;
			break;
		}
		for (int j = i + 1; j < n; j++)
		{
			if (a[j][i] != 0)
			{
				v = a[j][i] / a[i][i];
				for (int p = i; p < n; p++)
					a[j][p] = a[j][p] - a[i][p] * v;
			}
		}
		i++;
	}
	for (i = 0; i < n; i++)
	{
		sum = sum * a[i][i];
	}
	return sum;
}
int main(void) {
	double sum = 1, b[100] = { 1 }, c[100] = { 1 };
	int n;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%lf", &a[i][j]);
			g[i][j] = a[i][j];
		}
	}
	for(i=0;i<n;i++)
		scanf_s("%lf", &b[i]);
	sum=Gaus(n);
		for (i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = g[i][j];
		for (int j = 0; j < n; j++)
		{
			for (i = 0; i < n; i++)
				a[j][i] = b[i];
			c[j] = Gaus(n);
			for (i = 0; i < n; i++)
				for (int d = 0; d < n; d++)
					a[i][d] = g[i][d];
		}
		for (i = 0; i < n; i++)
			if (c[i] != 0) {
				c[i] = c[i] / sum;
			}
		for (i = 0; i < n; i++)
		{
			printf("%lf\n",c[i]);
		}
}
