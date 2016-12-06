#pragma once
#include "File.h"
#include "Queue.h"
template <class T>
class BinaryFile : public File					//Бинарный файл
{
	streampos last_read_pos;					//Последняя позиция чтения
	streampos last_write_pos;					//Последняя позиция записи
	fstream file;								//Файл
public:
	BinaryFile();								//Конструктор по умолчанию
	BinaryFile(const char* fn);					//Конструктор с параметрам
	~BinaryFile();								//Деструктор
	void refresh();								//Обновление файла
	void show_status();							//Вывод состояния файла
	void show();								//Вывод содержимого файла
	void close();								//Закрытие файла
	bool write(const T& el, int n = 1);			//Запись в файл
	bool read(T* el, int n = 1);				//Чтение из файла
	bool open(const char* fn);					//Открытие файла
	bool is_open();								//true если файл открыт
	bool eof();									//true если конец файла
	bool empty();								//true если файл пуст
	int size();									//Возвращает размер файла
	T operator [] (int i);						//Возвращает нужный элемент
	void read_queue(cQueue<T>& q);				//Чтение очереди из файла
};