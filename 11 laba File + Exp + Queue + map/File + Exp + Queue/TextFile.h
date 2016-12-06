#pragma once
#include "File.h"
#include "Queue.h"
template <class T>
class TextFile : File								//Текстовый файл
{
	streampos last_read_pos;						//Последняя позиция чтения
	streampos last_write_pos;						//Последняя позиция записи
	fstream file;									//Файл
public:
	TextFile();										//Конструктор по умолчанию
	TextFile(const char* fn);						//Конструктор с параметром
	~TextFile();									//Деструктор
	void refresh();									//Обновление файла
	void show_status();								//Вывод состояния файла
	void show();									//Вывод содержимого файла
	void close();									//Закрытие файла
	bool open(const char* fn);						//Открытие файла
	bool is_open();									//true если файл открыт
	bool eof();										//true если конец файла
	bool empty();									//true если файл пуст
	void getline(char* s, int n, char c = ' ');		//Чтение строеи из файла
	int size();										//Возвращает размер файла
	T operator [] (int i);							//Доступ к любому элементу файла
	TextFile& operator << (const T& el);			//Запись в файл элемента
	TextFile& operator >> (T& el);					//Чтение элемента из файла
	TextFile& operator << (const cQueue<T>& el);	//Запись очереди в файл
	TextFile& operator >> (cQueue<T>& el);			//Чтение очереди из файла
};