#pragma once

template <typename T>
struct queue_elem
{
	T data;
	queue_elem* next = nullptr;
	queue_elem* prev = nullptr;
};

template <typename T>
struct queue
{
	queue_elem<T>* first = nullptr;
	queue_elem<T>* last  = nullptr;
};

/// \brief Добавление элемента в очередь
/// \param q Ссылка на очередь, в которую нужно добавить элемент
/// \param name Имя добавляемого человека
/// \param age Возраст добавляемого человека
template <typename T>
void enqueue(queue<T>& q, T data)
{
	auto* new_el = new queue_elem<T>;
	new_el->data = data;
	new_el->prev = q.last;
	if (q.last) q.last->next = new_el;
	q.last = new_el;
	if (!q.first) q.first = new_el;
}

/// \brief Извлечение элемента из очереди и возврат значения удаленного элемента
/// \param q Ссылка на очередь, из которой извлекается значение
/// \param name Имя человека, извлеченное из очереди
/// \param age Возраст человека, извлеченный из очереди
/// \return true, если элемент удалось извлечь из очереди и false, если очередь была пуста
template <typename T>
bool dequeue(queue<T>& q, T& data)
{
	if (!q.first) return false;
	data = q.first->data;
	const queue_elem<T>* del = q.first;
	q.first = q.first->next;
	if (q.first) q.first->prev = nullptr;
	else q.last = nullptr;
	delete del;
	return true;
}

/// \brief Удаление всех элементов очереди из памяти
/// \param q Удаляемая очередь
template <typename T>
void clear(queue<T>& q)
{
	queue_elem<T>* curr = q.first;
	while (curr)
	{
		const auto* del = curr;
		curr = curr->next;
		delete del;
	}
	q.first = q.last = nullptr;
}
