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

/// \brief ���������� �������� � �������
/// \param q ������ �� �������, � ������� ����� �������� �������
/// \param name ��� ������������ ��������
/// \param age ������� ������������ ��������
void enqueue(queue& q, const char* name, int age);

/// \brief ���������� �������� �� ������� � ������� �������� ���������� ��������
/// \param q ������ �� �������, �� ������� ����������� ��������
/// \param name ��� ��������, ����������� �� �������
/// \param age ������� ��������, ����������� �� �������
/// \return true, ���� ������� ������� ������� �� ������� � false, ���� ������� ���� �����
bool dequeue(queue& q, char*& name, int& age);

/// \brief �������� ���� ��������� ������� �� ������
/// \param q ��������� �������
void clear(queue& q);
