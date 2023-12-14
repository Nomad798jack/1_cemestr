//В текстовом файле input.txt записан русский текст.
//Найти в тексте слова, содержащие не менее четырех различных гласных букв,
//записать их заглавными буквами и указать после каждого такого слова в скобках найденные буквы.
//Полученный текст записать в файл output.txt.Весь текст, кроме найденных слов, должен остаться неизменным, включая и знаки препинания.

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
		else if (s[i] < 191)
			result += s[i];
	return result;
}

std::string BIG(std::string s) //делает заглавными
{
	std::string result;
	for (int i = 0; i < s.length(); i++)
		if (((s[i] >= 'а') and (s[i] <= 'я')))
		{
			result += toupper(s[i]);
		}
		else if (s[i] < 191) result += s[i];
	return result;
}


std::string delete_sogl(std::string word)
{
	std::string result;
	int b = word.length();

	for (int i = 0; i < word.length(); i++)
	{
		if ((word[i] == 'а') || (word[i] == 'е') || (word[i] == 'и') || (word[i] == 'о') || (word[i] == 'у') || (word[i] == 'ы') || (word[i] == 'э') || (word[i] == 'ю') || (word[i] == 'я'))
		{
			result += word[i];
		}
	}
	return result;


}bool is_glas(char c)
{
	if ((c == 'а') || (c == 'е') || (c == 'и') || (c == 'о') || (c == 'у') || (c == 'ы') || (c == 'э') || (c == 'ю') || (c == 'я'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string uniq_gl(std::string word)
{
	std::string glas = delete_sogl(word);
	int cnt = 0;
	int bukv[32] = {};
	std::string c;
	char g = 0;
	for (int i = 0; i < glas.length(); i++)
	{
		int c = 32 + glas[i];
		bukv[c] += 1;
	}
	for (int j = 0; j < 33; j++)
	{
		if ((bukv[j] >= 1) && is_glas(j + 224))
		{
			cnt++;
			g = j + 224;
			c += g;
		}
		else
		{
			continue;
		}
	}
	if (cnt >= 4)
	{
		return BIG(word) + " " + "(" + c + ")";
	}
	else
	{
		return word;
	}
}





int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream in("C://input3.txt", std::ios::in);
	std::ofstream out("C://output3.txt", std::ios::out);
	std::string mas[2001];
	std::string str;
	int j = 0;
	while (!in.eof())
	{
		in >> str;
		mas[j] = isletter(str);
		j++;
	}

	for (int i = 0; i < j; i++)
	{
		std::cout << mas[i] << " " << uniq_gl(mas[i]) << std::endl;
		out << uniq_gl(mas[i]) << std::endl;
	}


	return 0;

}