#include "Header.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");
	Stack<double, 6> f;
	cout << "Работа с классом, содержащим элементы типа double" << endl;
	cout << "Попробуем удалить элемент из стека до его инициализации:" << endl;
	f.Pop();
	Sep();
	cout << "Инициализируем стек:" << endl;
	cin >> f;
	Sep();
	cout << f;
	Sep();
	cout << "Удалим элемент из стека:" << endl;
	f.Pop();
	cout << f;
	Sep();
	cout << "Добавим элемент в стек (12,32):" << endl;
	f.Push(12.32);
	cout << f;
	Sep();
	cout << "Попробуем добавить элемент в заполненный стек:" << endl;
	f.Push(14.1);
	Sep();
	cout << "Определим размер очереди и верхний элемент без его удаления" << endl;
	cout << "Размер очереди - " << f.Size() << "\n" << "Верхний элемент - " << f.Top() << endl;
	Sep();
	cout << "Проверим работоспособность оператора присваивания:" << endl;
	Stack<double, 6> f1;
	f1 = f;
	cout << "Первый стек:" << endl;
	cout << f;
	cout << "Второй стек:" << endl;
	cout << f1;
	Sep();
	cout << "Удалим из второго стека элемент и посмотрим не изменился ли первый стек:" << endl;
	f1.Pop();
	cout << "Первый стек:" << endl;
	cout << f;
	cout << "Второй стек:" << endl;
	cout << f1;
	system("pause");
	return 0;
}


