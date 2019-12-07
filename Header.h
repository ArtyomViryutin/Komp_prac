#pragma once
#include <iostream>
using namespace std;
// Описание шаблона
template <typename T1, int N> 
class Stack
{
private:
	T1 *StackPtr; // Указатель на массив элементов
	int MaxSize = N; // Переменная, которая содержит максимальный размер стека
	int top; // Индекс верхнего элемента стека
public:
	Stack(); // Конструктор по умолчанию
	~Stack(); // Деструктор
	void Print(); // Операция вывода
	bool Push(const T1 value); // Операция добавления элемента в стек
	bool Pop(); // Операция удаления элемента из стека
	T1 Top(); // Определение верхнего элемента без его удаления
	int Size(); // Определение размера очереди
	void Init(); // Инициализации стека
	Stack& operator=(Stack &a); // Перегрузка оператора присваивания
	bool Empty(); // Проверка на пустоту
	bool Full(); // Проверка на полноту

};
// Пользовательский класс
class Money
{
private:
	long rub; // Переменная для хранения количества рублей
	int cop; // Переменная для хранения количества копеек
public:
	Money(); // Конструктор по умолчанию
	Money(long rub1, int cop1); // Конструктор с параметрами
	friend std::istream& operator>> (std::istream &in, Money &a) // Перегрузка оператор ввода
	{
		cout << "Рубли: "; cin >> a.rub;
		cout << "Копейки: "; cin >> a.cop;
		return in;
	}
	friend std::ostream& operator<< (std::ostream &out, const Money &a) // Перегрузка оператора вывода
	{
		cout << "Денежная сумма: " << a.rub << "," << a.cop << endl;
		return out;
	}

};

// Конструктур по умолчанию (инициализирует переменные нулями)
Money::Money() : rub(0), cop(0) {}

// Конструктор с параметрами (инициализирует переменные rub и cop значениями rub1 и cop1 соответственно
Money::Money(long rub1, int cop1) : rub(rub1), cop(cop1) {}

// Конструктор по умолчанию
// Выделяем память и присваиваем переменной top занчение -1, что говорит о пустоте очереди
template <typename T1, int N>
Stack<T1, N>::Stack() { StackPtr = new T1[1]; top = -1; }

// Проверка на пустоту
template <typename T1, int N>
bool Stack<T1, N>::Empty()
{
	if (top == -1) // Если индекс верхнего элемента top = -1, стек пуст
		return true; // Возвращаем true
	return false; // Иначе - false - стек не пуст
}

// Проверка на полноту
template <typename T1, int N>
bool Stack<T1, N>::Full()
{
	if (top + 1 == MaxSize) // Если индекс верхнего элемента (top + 1), то есть размер очереди, равен максимальному размеру очереди
		return true; // Значит очередь заполнена, возвращаем true
	return false; // Иначе - false - очередь не заполнена
}

// Деструктор
template <typename T, int N>
Stack<T, N>::~Stack() { delete[] StackPtr; } // Очищаем указатель на массив элементов

// Перегрузка оператора присванивания
template <typename T1, int N>
Stack<T1, N>& Stack<T1, N>::operator=(Stack<T1, N> &a)
{
	top = a.top; // Присваиваем индекс верхнего элемента очереди
	StackPtr = (T1*)realloc(StackPtr, (a.top + 1) * sizeof(T1)); // Выделяем память
	for (int i = 0; i < top + 1; i++)
		StackPtr[i] = a.StackPtr[i]; // Присваиваем значения элементов
	return *this; // Возвращаем указатель на объект, который вызвал метод
}

// Операция вывода
template <typename T1, int N>
void Stack<T1, N>::Print()
{
	for (int i = top; i >= 0; i--) // Начиная с конца массива StackPtr выводим все элементы
		cout << StackPtr[i] << endl;
}

// Операция добавления элемента в стек
template <typename T1, int N>
bool Stack<T1, N>::Push(const T1 value)
{
	if (Full()) // Проверка очереди на полноту, если она заполнена, то выводим соответствующее сообщение и возвращаем false
	{
		cout << "Невозможно добавить элемент, так как стек полностью заполнен." << endl;
		return false; // стек полон
	}

	top++; // Увеличиваем индекс верхнего элемента на 1
	StackPtr = (T1*)realloc(StackPtr, (top + 1) * sizeof(T1)); // Выделяем память для нового элемента
	StackPtr[top] = value; // помещаем элемент в стек // Присваием значение
	return true; // При успехе возвращаем true
}

// Операция удаления элемента из очереди
template <typename T1, int N>
bool Stack<T1, N>::Pop()
{
	if (Empty()) // Провеврка очереди на пустоту, если она пуста, то удалять нечего
	{
		cout << "Невозможно удалить элемент, так как стек пуст." << endl; // Выводим соответсвующее сообщения
		return false; // И возвращаем false
	}
	StackPtr = (T1*)realloc(StackPtr, top * sizeof(T1)); // Уменьшаем размер очереди(массива StackPtr) на 1
	top--; // Уменьшаем индекс верхнего элемента 1

	return true; // В случае успеха возвращаем true
}

// Определение верхнего элемента без его удаления
template <typename T1, int N>
T1 Stack<T1, N>::Top() { return StackPtr[top]; } // Возвращаем значение верхнего элемента по индексу top

// Определение размера очереди
template <typename T1, int N>
int Stack<T1, N>::Size() { return top + 1; } // Возвращаем размер очереди, как индекс верхнего элемента + 1

// Инициализация стека
template <typename T1, int N>
void Stack<T1, N>::Init()
{
	int n = 0; // Счетчик
	T1 temp; // Временная переменная для ввода
	while (n++ != MaxSize) // Пока не максимальный размер очереди
	{
		cin >> temp; // Вводим элемент
		this->Push(temp); // Добавляем элемент в очередь
	}
}

void Sep() {
	cout << "-------------------------" << endl;
}
