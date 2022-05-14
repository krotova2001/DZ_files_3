#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int key; // берем у пользователя ключ - величину сдвига
	cout << "Hi! Enter a key";
	cin >> key;

	ifstream Source; // создадим объект для чтения исходного файла
	ofstream Result; // объект для вывода результатов
	
	Source.open("c:\\1\\11.txt"); //откроем файл - источник
	
	if (Source.is_open()) // если удалось открыть исходный файл, то...
	{
		Result.open("c:\\1\\encrypted.txt", ios::out); // откроем файл на запись и запишем
		if (Result.is_open())
		{
			while (!Source.eof()) // идем до конца файла
			{
				char temp; // хранение считываемого символа
				Source.get(temp); // считываем по символу и считаем...
				temp += key; // шифруем сдвигом по алфавиту
				Result << temp; // записываем результат
			}
			Result.close(); // закрываем скачала результат
		}
		else
		{
			cout << "Can not write c:\\1\\enctypted.txt";
		} 
		Source.close(); // потом закрываем источник
	}
	else
	{
		cout << "Can not  open file c:\\1\\11.txt";
	}
}
