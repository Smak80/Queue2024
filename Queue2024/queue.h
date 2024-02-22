#pragma once

struct queue_elem
{
	char name[50];
	int age;
	queue_elem* next = nullptr;
	queue_elem* prev = nullptr;
};

struct queue
{
	queue_elem* first = nullptr;
	queue_elem* last  = nullptr;
};

/// \brief Добавление элемента в очередь
/// \param q Ссылка на очередь, в которую нужно добавить элемент
/// \param name Имя добавляемого человека
/// \param age Возраст добавляемого человека
void enqueue(queue& q, const char* name, int age);

/// \brief Извлечение элемента из очереди и возврат значения удаленного элемента
/// \param q Ссылка на очередь, из которой извлекается значение
/// \param name Имя человека, извлеченное из очереди
/// \param age Возраст человека, извлеченный из очереди
/// \return true, если элемент удалось извлечь из очереди и false, если очередь была пуста
bool dequeue(queue& q, char*& name, int& age);

/// \brief Удаление всех элементов очереди из памяти
/// \param q Удаляемая очередь
void clear(queue& q);
