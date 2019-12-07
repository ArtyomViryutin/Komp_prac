#include "Header.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");
	Stack<int, 5> i;
	Stack<double, 4> d;
	Stack<float, 3> f;
	cout << "Работа с шаблоном, содержащим элементы типа int" << endl;
	cout << "Попробуем удалить элемент из стека до его инициализации:" << endl;
	i.Pop();
	Sep();
	cout << "Инициализируем стек:" << endl;
	i.Init();
	Sep();
	i.Print();
	Sep();
	cout << "Удалим элемент из стека:" << endl;
	i.Pop();
	i.Print();
	Sep();
	cout << "Добавим элемент в стек:" << endl;
	i.Push(15);
	i.Print();
	Sep();
	cout << "Попробуем добавить элемент в заполненный стек:" << endl;
	i.Push(9);
	Sep();
	cout << "Определим размер очереди и верхний элемент без его удаления" << endl;
	cout << "Размер очереди - " << i.Size() << "\n" << "Верхний элемент - " << i.Top() << endl;
	Sep();
	cout << "Проверим работоспособность оператора присваивания:" << endl;
	Stack<int, 5> i1;
	i1 = i;
	cout << "Первый стек:" << endl;
	i.Print();
	cout << "Второй стек:" << endl;
	i1.Print();
	Sep();
	cout << "Удалим из второго стека элемент и посмотрим не изменился ли первый стек:" << endl;
	i1.Pop();
	cout << "Первый стек:" << endl;
	i.Print();
	cout << "Второй стек:" << endl;
	i1.Print();
	system("pause");
	return 0;
}


