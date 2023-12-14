//Найти в тексте N <= 2000 самых длинных слов,
//не содержащих одинаковых согласных.
//Записать найденные слова в текстовый файл в порядке
//убывания длины.Все найденные слова должны быть разными!


#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <windows.h>
#include <clocale>


std::string isletter(std::string s) 
{
	std::string result;
	for (int i = 0; i < s.length(); i++)
		if (((s[i] >= 'а') and (s[i] <= 'я')) or ((s[i] >= 'А') and (s[i] <= 'Я')))
			result += tolower(s[i]);
	return result;
}

bool is_cogl(char c)
{
	if ((c == 'б') || (c == 'в') || (c == 'г') || (c == 'д') || (c == 'ж') || (c == 'з') || (c == 'й') || (c == 'к') || (c == 'л') || (c == 'м') || (c == 'п') || (c == 'р') || (c == 'с') || (c == 'т') || (c == 'ф') || (c == 'х') || (c == 'ц') || (c == 'ч') || (c == 'ш') || (c == 'щ') || (c == 'н'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool eq_cogl(std::string fstword)
{
	int cnt = 0;
	int mas[32] = {};
	std::string lowletter = isletter(fstword);
	for (int i = 0; i < lowletter.length(); i++)
	{
		int c = 32 + lowletter[i];
		mas[c] += 1;
	}
	for (int j = 0; j < 33; j++)
	{
		if ((mas[j] > 1) && is_cogl(j + 224))
		{
			return true;
			break;
		}
		else
		{
			continue;
		}
	}
	return false;
}
//bool noteq_words(std::string onewrd, std::string twowrd)
//{
//	int cnt = 0;
//	if (onewrd.length() != twowrd.length())
//	{
//		return true;
//	}
//	else
//	{
//		for (int i = 0; i < onewrd.length() + 1; i++)
//		{
//			if (onewrd[i] == twowrd[i])
//			{
//				cnt++;
//			}
//			else
//			{
//				return true;
//				break;
//			}
//		}
//	}
//	if (cnt == onewrd.length())
//	{
//		return false;
//	}
//}	


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream in("C://input.txt", std::ios::in);
	std::ofstream out("C://output.txt", std::ios::out);
	std::string str;
	std::string mas[2001];

	int j = 0;
	while (!in.eof())
	{
		in >> str;
		mas[j] = isletter(str);
		j++;
	}
	std::string newmas[2001];
	int nmb = 0;
	for (int i = 0; i < j; i++) //новый массив с подх словами
	{
		for (int x = i + 1; x < j+1; x++)
		{
			if ((eq_cogl(mas[i]) == 0))
			{
				newmas[nmb] = mas[i];
				nmb++;
				i++;
			}
		}
	}
	
	std::string temp;
	for (int i = 0; i < nmb; i++) //сортировка слов
	{
		for (int k = i + 1; k < nmb + 1; k++)
		{
			if (newmas[k].length() > newmas[i].length())
			{
				temp = newmas[k];
				newmas[k] = newmas[i];
				newmas[i] = temp;
			}
		}
	}
	int b = nmb;
	while (b > 0) //удаление одинаковых
	{
		if (newmas[b] == newmas[b-1])
		{
			newmas[b] = "";
			for (int i = b; i < nmb; i++)
			{
				temp = newmas[i+1];
				newmas[i+1] = newmas[i];
				newmas[i] = temp;
			}
			b--;
		}
		b--;
	}



	for (int i = 0; i < j; i++)
	{
		std::cout << newmas[i] << std::endl;
		out << newmas[i] << std::endl;
	}

	return 0;
}

