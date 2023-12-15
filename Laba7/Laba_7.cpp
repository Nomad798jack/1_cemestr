//Дана целочисленная матрица {Aij}i = 1...n; j = 1..n, n <= 100.
//Если суммы цифр минимального и максимального элементов матрицы одинаковы,
//упорядочить строки матрицы по неубыванию суммы элементов.

#include <iostream>
#include "functions.hpp"

int main()
{
    const int n = 3;
    int matrix[mt::nmax][mt::nmax] = {};

    int min = 1000000;
    int max = 0;
    
    mt::iMput(matrix, n);
    mt::minmax(matrix, n, max, min);
    mt::sort(matrix, n, max, min);


    
    std::cout << min << " " << max << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < n; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
    }


    return 0;




}
