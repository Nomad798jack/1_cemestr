#pragma once

namespace mt
{
	const int nmax = 100;
	int sum_cifr(int n);
	void minmax(int(&matrix)[nmax][nmax], int n, int& max, int& min);
	void iMput(int(&matrix)[nmax][nmax], int n);
	void sort(int(&matrix)[nmax][nmax], int n, int max, int min);

}