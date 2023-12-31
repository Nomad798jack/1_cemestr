﻿//Если в тексте нет слов - палиндромов длиной более 1 - й буквы, то вывести слова текста в
// соответствии с убыванием количества звонких согласных,
//в противном  случае удалить из слов текста гласные буквы и вывести полученные слова в поpядке, 
//обpатном к алфавитному. (Звонкие согласные : бвгжздйлмнр)


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

bool palindrome(std::string word)
{
	int cnt = 0;
	int length = word.length();
	for (int i = 0; i < length; i++)
	{	
		if (length > 1)
		{
			if (word[i] == word[length - 1 - i]) cnt++;
		}
	}
	if (cnt == length) return true;
	else return false;
}

int cnt_zv_sgl(std::string word)
{
	int cnt = 0;
	char zvsgl[] = "бвгжздйлмнр";
	for (int i = 0; i < word.length(); i++)
	{
		for (int j = 0; j < strlen(zvsgl); j++)
		{
			if (word[i] == zvsgl[j]) cnt++;
		}		
	}
	return cnt;
}

std::string delete_gl(std::string word)
{
	std::string result;
	int b = word.length();

	for (int i = 0; i < word.length(); i++)
	{
		if ((word[i] != 'а') && (word[i] != 'е') && (word[i] != 'и') && (word[i] != 'о') && (word[i] != 'у') && (word[i] != 'ы') && (word[i] != 'э') && (word[i] != 'ю') && (word[i] != 'я'))
		{
			result += word[i];
		}
	}
	return result;


}







int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream in("C://input2.txt", std::ios::in);
	std::ofstream out("C://output2.txt", std::ios::out);
	std::string mas[2001];
	std::string newmas[2001];
	std::string str;
	int j = 0;
	while (!in.eof())
	{
		in >> str;
		mas[j] = isletter(str);
		j++;
	}

	int cnt = 0;
	for (int i = 0; i < j; i++)
	{
		if (palindrome(mas[i])) cnt++;
	}
	
	std::string temp;
	if (cnt == 0)
	{
		for (int i = 0; i < j; i++)
		{
			for (int k = i + 1; k < j + 1; k++)
			{
				if (cnt_zv_sgl(mas[i]) < cnt_zv_sgl(mas[k]))
				{
					temp = mas[k];
					mas[k] = mas[i];
					mas[i] = temp;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < j; i++)
		{
			std::string dodik = mas[i];
			newmas[i] = delete_gl(dodik);
		}
	}
	
	std::string temp1;
	for (int i = 0; i < j - 1; i++) 
	{
		for (int x = i + 1; x < j; x++)
		{
			if (newmas[x] >= newmas[i])
			{
				temp1 = newmas[x];
				newmas[x] = newmas[i];
				newmas[i] = temp1;
			}
		}
	}
	for (int i = 0; i < j; i++)
	{
		if (cnt == 0)
		{
			std::cout << mas[i] << std::endl;
			out << mas[i] << std::endl;
		}
		else
		{
			std::cout << newmas[i] << std::endl;
			out << newmas[i] << std::endl;
		}
	}
	


}
	