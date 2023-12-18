#include "List_arr.h"
#include "List_point.h"
#include "List_doubly_linked.h"
#include "List_circular.h"
#include "Queue.h"
#include "Stack_arr.h"
#include "Stack_point.h"
#include <algorithm>
#include <string>
#include <map>


template <typename T>
void Test_l(T &list) {
	int index, data, count = 0;
	cout << "\nЗаполните список. Введите индекс и значение элемента: index new_elemen. Для окончания введите -1\n>>>> ";
	cin >> index;
	while (index != -1) {
		cin >> data;
		++count;
		list->insert(index, data);
		cout << ">>>> ";
		cin >> index;
	}
	cout << "\nВывод списка\n";
	for (int i = 0; i < count; ++i) {
		cout << list->retriеve(i) << " ";
	}
	cout << "\nВведите элемент для поиска\n>>>> ";
	cin >> data;
	index = list->find(data);
	cout << "Индекс элемента " << data << ": " << index;
	if (index == -1) cout << " (заданного элемента не существует)";
	cout << endl;
	cout << "Введите позицию для удаления\n>>>> ";
	cin >> index;
	list->remove(index);
	count = list->getLength();
	if (list->is_empty()) cout << "Список пуст\n";
	else {
		cout << "Список не пуст. Длина списка: " << count << endl;
		cout << "\nВывод списка\n";
		for (int i = 0; i < count; ++i) {
			cout << list->retriеve(i) << " ";
		}
	}
}

template<typename Stack>
void Test_s(Stack &stack) {
	string str;
	int data;
	map<string, int> command = { {"push", 1} ,{"pop", 2} ,{"get_top", 3} ,{"is_empty", 4} };
	cout << "Список команд:\npush X: добавляет новый элемент X в стек\npop N: удаляет N элементов из стека";
	cout << "\nget_top: возвращает значение элемента из вершины стека\nis_empty: определяет, пуст ли стек\nbreak: завершает ввод команд\n\n";
	while (true) {
		cout << ">>>> ";
		cin >> str;
		if (str == "break") break;
		switch (command[str])
		{
		case 1:
			cin >> data;
			stack.push(data);
			break;
		case 2:
			cin >> data;
			for (int i = 0; i < data; ++i) {
				stack.pop();
				if (stack.is_empty()) break;
			}
			break;
		case 3:
			data = stack.get_top();
			if (!stack.is_empty())
				cout << "Значение вершины стека: " << data << endl;
			break;
		case 4:
			if (stack.is_empty()) cout << "Стек пуст\n";
			else cout << "Стек не пуст\n";
			break;
		default:
			cout << "Введенная команда отсутствует\n";
			break;
		}
	}
	cout << "Полученный стек:\n";
	TypeItem stackTop;
	while (!stack.is_empty()) {
		stackTop = stack.get_top();
		stack.pop();
		cout << stackTop << " ";
	}
}

template<typename Stack>
void Count(Stack stack) {
	cout << "Введите постфиксное выражение для расчета.\n>>>> ";
	string exp;
	cin >> exp;
	for (char symbol : exp) {
		int temp1, temp2;
		switch (symbol)
		{
		case '+':
			temp2 = stack.get_top();
			stack.pop();
			temp1 = stack.get_top();
			stack.pop();
			stack.push(temp1 + temp2);
			break;
		case '-':
			temp2 = stack.get_top();
			stack.pop();
			temp1 = stack.get_top();
			stack.pop();
			stack.push(temp1 - temp2);
			break;
		case '/':
			temp2 = stack.get_top();
			stack.pop();
			temp1 = stack.get_top();
			stack.pop();
			stack.push(temp1 / temp2);
			break;
		case '*':
			temp2 = stack.get_top();
			stack.pop();
			temp1 = stack.get_top();
			stack.pop();
			stack.push(temp1 * temp2);
			break;
		default:
			const char ch = symbol;
			stack.push(atoi(&ch));
			break;
		}
	}
	cout << "Результат: " << stack.get_top() << endl;
}

void L() {
	cout << "Выберите список для работы:\n(1) Список из массива\n(2) Список из указателей";
	cout << "\n(3) Двусвязный список из указателей\n(4) Кольцевой список из указателей\n>>>> ";
	int choise, index, data, count = 0;
	List *list_arr = new List;
	list list = new Node;
	list_c list_c = new Node_c;
	list_d list_d = new Node_d;
	cin >> choise;
	switch (choise)
	{
	case 1:
		Test_l(list_arr);
		break;
	case 2:
		Test_l(list);
		break;
	case 3:
		Test_l(list_d);
		if (!list_d->is_empty()) {
			cout << "\nВывод списка в обратном порядке:\n";
			list_d->getReversed();
		}
		break;
	case 4:
		Test_l(list_c);
		break;
	default:
		cout << "<Ошибка ввода>";
		break;
	}
	delete list;
	delete list_arr;
	delete list_c;
	delete list_d;
}

void Q() {
	Queue queue;
	string str;
	int data;
	map<string, int> command = { {"en_queue", 1} ,{"de_queue", 2} ,{"get_front", 3} ,{"is_empty", 4} };
	cout << "Список команд:\nen_queue X: добавляет новый элемент X в конец очереди\nde_queue N: удаляет N элементов из начала очереди";
	cout << "\nget_front: возвращает значение элемента из начала очереди\nis_empty: определяет, пуста ли очередь\nbreak :завершает ввод команд\n\n";
	while (true) {
		cout << ">>>> ";
		cin >> str;
		if (str == "break") break;
		switch (command[str])
		{
		case 1:
			cin >> data;
			queue.en_queue(data);
			break;
		case 2:
			cin >> data;
			for (int i = 0; i < data; ++i) {
				queue.de_queue();
				if (queue.is_empty()) break;
			}
			break;
		case 3:
			data = queue.get_front();
			if (!queue.is_empty())
				cout << "Значение начала очереди: " << data << endl;
			break;
		case 4:
			if (queue.is_empty()) cout << "Очередь пуста\n";
			else cout << "Очередь не пуста\n";
			break;
		default:
			cout << "Введенная команда отсутствует\n";
			break;
		}
	}
	cout << "Полученная очередь:\n";
	while (!queue.is_empty()) {
		cout << queue.get_front() << " ";
		queue.de_queue();
	}
}

void S() {
	cout << "Выберите стек для работы:\n(1) Стек из массива\n(2) Стек из указателей";
	cout << "\n(3) Выполнить вычисление выражения с помощью стека\n>>>> ";
	int choise, index, data, count = 0;
	Stack_arr stack_arr;
	Stack_p stack_p;
	cin >> choise;
	switch (choise)
	{
	case 1:
		Test_s(stack_arr);
		break;
	case 2:
		Test_s(stack_p);
		break;
	case 3:
		Count(stack_arr);
		break;
	default:
		cout << "<Ошибка ввода>";
		break;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int choise;
	cout << "Выберите обьект для работы: \n(1) Список\n(2) Очередь\n(3) Стек\n>>>> ";
	cin >> choise;
	switch (choise)
	{
	case 1:
		L();
		break;
	case 2:
		Q();
		break;
	case 3:
		S();
		break;
	default:
		break;
	}
}
/*
0 1
0 0
2 3
2 2
4 4
-1
*/