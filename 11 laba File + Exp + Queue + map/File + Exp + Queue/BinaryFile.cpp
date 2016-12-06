#pragma once
#include "BinaryFile.h"
#include "Exception.h"
#include "Queue.h"
#include <iomanip>
template <class T>
BinaryFile<T>::BinaryFile() {}									//Конструктор по умолчанию
template <class T>
BinaryFile<T>::BinaryFile(const char* fn) : File(fn), last_read_pos(0), last_write_pos(0)
{																//Конструктор с параметром
	file.open(fn, ios::in | ios::out | ios::binary);
	if (!file)
	{
		file.open(fn, ios::in | ios::out | ios::binary | ios::trunc);
	}
}
template <class T>
BinaryFile<T>::~BinaryFile()									//Деструктор
{
	file.close();												//Закрытие файла
}
template <class T>
void BinaryFile<T>::refresh()									//Обновление файла
{
	if (file.is_open())											//Если файл открыт
	{
		file.clear();											//Сброс битов
		last_read_pos = 0;										//Зануление позиций чтения и записи
		last_write_pos = 0;
		file.seekg(last_read_pos, ios::beg);
		file.seekp(last_write_pos, ios::beg);
	}
}
template <class T>
void BinaryFile<T>::show_status()								//Выводит статус файла
{
	if (file.is_open())											//Если файл открыт
	{
		cout.setf(ios::right);
		cout << setfill('-') << setw(120) << '-' << endl << setfill(' ');
		cout << setw(20) << "is open";
		cout << setw(20) << "end of file";
		cout << setw(20) << "size(elements)";
		cout << setw(20) << "read position";
		cout << setw(20) << "write position" << endl;
		cout << setw(20) << file.is_open();
		cout << setw(20) << file.eof();							//Вывод бита конца файла
		cout << setw(20) << size();								//Вывод размера файла
		cout << setw(20) << last_read_pos / sizeof(T);			//Вывод последней позиции чтения
		cout << setw(20) << last_write_pos / sizeof(T) << endl;	//Вывод последней позиции записиы
		cout << setfill('-') << setw(120) << '-' << endl << setfill(' ');
		cout.setf(ios::left);
	}
	else
	{
		cout << "File isn't open." << endl;						//Если файл не открыт то вывод сообщения об этом
	}
}
template <class T>
void BinaryFile<T>::show()										//Вывод содержимого файла
{
	T buf;														//Буферный элемент
	bool file_end = false;
	if (!file.is_open())										//Если файл не открыт, то
	{
		throw FileExp(11, "File isn't open.");					//Генерация ошибки
	}
	if (file.eof())												//Если конец файла
	{
		file.clear();											//Очистка битов
		file_end = true;
	}
	streampos lastRP = last_read_pos;
	last_read_pos = 0;
	while (read(&buf))											//Вывод самого файла
	{
		cout << buf << endl;
	}
	file.clear();												//Очистка битов потока
	if (file_end) file.clear(1);								//Если был конец файла, то возвращение битак конца
	last_read_pos = lastRP;
}
template <class T>
void BinaryFile<T>::close()										//Закрытие файла
{
	file.close();
}
template <class T>
bool BinaryFile<T>::write(const T& el, int n)					//Запись в файл
{
	if (file.is_open())											//Если файл открыт
	{
		file.seekp(last_write_pos, ios::beg);
		file.write(reinterpret_cast<const char*>(&el), n * sizeof(T));	//Чтение из файла
		last_write_pos = file.tellp();							//Запоминаем позицию последнего чтения
		return true;
	}
	else
	{
		return false;											//Если файл закрыт то возвращаем false
	}
}
template<class T>
bool BinaryFile<T>::open(const char* fn)						//Функция открытия файла
{
	file.close();												//Закрытие старого файла
	file.open(fn, ios::in | ios::out | ios::binary);			//Попытка открытия уже существующего файла
	if (!file)
	{
		file.open(fn, ios::in | ios::out | ios::binary | ios::trunc);	//Иначе создание нового файла
		if (!file)
		{
			return false;
		}
	}
	strcpy(file_name, fn);										//Запоминаем имя файла
	last_read_pos = 0;											//Колодки чтения и записи ставим в начало
	last_write_pos = 0;
	return true;
}
template <class T>
bool BinaryFile<T>::is_open()									//true если файл открыт
{
	return file.is_open();
}
template <class T>
bool BinaryFile<T>::eof()										//true если конец файла
{
	return file.eof();
}
template <class T>
int BinaryFile<T>::size()										//Возвращает размер файла
{
	int size = 0;
	bool end_file = false;										//Запоминает битконца файла
	if (file.eof())
	{
		end_file = true;
		file.clear();
	}
	if (file.is_open())											//Если файл открыт
	{
		file.seekg(0, ios::end);								//Перемещаем колодку чтения в конец
		size = file.tellg();									//Запоминаем её позиция
		file.seekg(last_read_pos, ios::beg);
		size /= sizeof(T);										//Делим на размер элемента
		if (end_file)
		{
			file.clear(1);										//Возвращаем флаг конца файла(если он был)
		}
		return size;
	}
	else
	{
		throw FileExp(11, "File isn't open.");
	}
}
template <class T>
bool BinaryFile<T>::read(T* el, int n)							//Чтение из файла
{
	if (!file.is_open() || file.eof())							//Если файл закрыт или конец файла
	{
		return false;											//то false
	}
	file.seekg(last_read_pos, ios::beg);						//Перемещаем колодку чтения на последнюю позиция чтения
	file.read(reinterpret_cast<char*>(el), n * sizeof(T));		//Считываем элемент
	if (file.eof())
	{
		return false;
	}
	last_read_pos = file.tellg();
	return true;
}
template <class T>
bool BinaryFile<T>::empty()										//true если файл пуст
{
	try
	{
		if (size() == 0)										//Если размер равен нулю
		{
			return true;										//то возвращает true
		}
		else
		{
			return false;										//Иначе false
		}
	}
	catch (...)
	{
		throw;
	}
}
template <class T>
T BinaryFile<T>::operator [] (int i)							//Доступ к нужному элементу файла
{
	T buf;
	if (file.is_open() && (i < size()) && i >= 0)				//Если правильно выбран номер
	{
		file.seekg(i * sizeof(T), ios::beg);
		file.read(reinterpret_cast<char*>(&buf), sizeof(T));	//Считываем этот элемент
		file.seekg(last_read_pos, ios::beg);
		return buf;
	}
	else
	{
		throw FileExp(12, "There is no such element");
	}
}
template <class T>
void BinaryFile<T>::read_queue(cQueue<T>& q)					//Чтение очереди их файла
{
	T buf;
	q.clear();
	if (!is_open())												//Проверка на открытие файла
	{
		throw FileExp(11, "File isn't open.");
	}
	if (file.eof())
	{
		file.clear();
	}
	streampos lastRP = last_read_pos;
	file.seekg(0, ios::beg);
	while (read(&buf))											//Чтение очереди из файла
	{
		q.PushBack(buf);
	}
	file.clear();
	last_read_pos = lastRP;
}