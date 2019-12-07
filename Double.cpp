#include "Header.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");
	Stack<double, 4> d;
	cout << "Работа с шаблоном, содержащим элементы типа int" << endl;
	cout << "Попробуем удалить элемент из стека до его инициализации:" << endl;
	d.Pop();
	Sep();
	cout << "Инициализируем стек:" << endl;
	d.Init();
	Sep();
	d.Print();
	Sep();
	cout << "Удалим элемент из стека:" << endl;
	d.Pop();
	d.Print();
	Sep();
	cout << "Добавим элемент в стек:" << endl;
	d.Push(1.12);
	d.Print();
	Sep();
	cout << "Попробуем добавить элемент в заполненный стек:" << endl;
	d.Push(9.98);
	Sep();
	cout << "Определим размер очереди и верхний элемент без его удаления" << endl;
	cout << "Размер очереди - " << d.Size() << "\n" << "Верхний элемент - " << d.Top() << endl;
	Sep();
	cout << "Проверим работоспособность оператора присваивания:" << endl;
	Stack<double, 4> d1;
	d1 = d;
	cout << "Первый стек:" << endl;
	d.Print();
	cout << "Второй стек:" << endl;
	d1.Print();
	Sep();
	cout << "Удалим из второго стека элемент и посмотрим не изменился ли первый стек:" << endl;
	d1.Pop();
	cout << "Первый стек:" << endl;
	d.Print();
	cout << "Второй стек:" << endl;
	d1.Print();
	system("pause");
	return 0;
}


