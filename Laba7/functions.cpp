#include "functions.hpp"
#include <iostream>

namespace mt
{
    int sum_cifr(int n)
    {
        int cnt = 0;
        while (n > 0)
        {
            cnt += n % 10;
            n = n / 10;
        }
        return cnt;
    }

    void minmax(int(&matrix)[nmax][nmax], int n, int& max, int& min)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] < min) min = matrix[i][j];
                if (matrix[i][j] > max) max = matrix[i][j];
            }
        }
    }

    void iMput(int(&matrix)[nmax][nmax], int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cin >> matrix[i][j];
            }
        }
    }

    void sort(int(&matrix)[nmax][nmax], int n, int max, int min)
    {
        int temp = 0;
        int masstrok[100] = {};
        int sumstrok = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sumstrok += matrix[i][j];
                masstrok[i] = sumstrok;
                if (j == 2) sumstrok = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (sum_cifr(min) == sum_cifr(max))
                {
                    if (masstrok[i] > masstrok[j])
                    {
                        for (int k = 0; k < n; k++)
                        {
                            std::swap(matrix[i][k], matrix[j][k]);
                        }
                        std::swap(masstrok[i], masstrok[j]);
                    }
                }
            }
        }
    }

}