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

/// \brief ���������� �������� � �������
/// \param q ������ �� �������, � ������� ����� �������� �������
/// \param name ��� ������������ ��������
/// \param age ������� ������������ ��������
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

/// \brief ���������� �������� �� ������� � ������� �������� ���������� ��������
/// \param q ������ �� �������, �� ������� ����������� ��������
/// \param name ��� ��������, ����������� �� �������
/// \param age ������� ��������, ����������� �� �������
/// \return true, ���� ������� ������� ������� �� ������� � false, ���� ������� ���� �����
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

/// \brief �������� ���� ��������� ������� �� ������
/// \param q ��������� �������
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
