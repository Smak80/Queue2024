#include <iostream>
#include <fstream>
#include "queue.h"
using namespace std;

struct person
{
	char name[50];
	int age;
};

void show_queue_data(queue<person> q)
{
	auto* curr = q.first;
	while (curr)
	{
		cout << curr->data.name << " " << curr->data.age << "\n";
		curr = curr->next;
	}
	cout << endl;
}

void main()
{
	setlocale(LC_ALL, "");

	queue<person> trud;
	queue<person> ne_trud;

	ifstream file("persons.txt");
	if (file)
	{
		while (!file.eof())
		{
			person the_person;
			file >> the_person.name;
			file >> the_person.age;
			enqueue(the_person.age >= 14 && the_person.age < 65 ? trud : ne_trud, the_person);
		}
		file.close();
	} else
	{
		cout << "Файл с данными не открылся :(";
	}
	cout << "Трудоспособные: \n";
	show_queue_data(trud);
	cout << "Нетрудоспособные: \n";
	show_queue_data(ne_trud);

	clear(trud);
	clear(ne_trud);

	queue<int> q;
	for (int i = 0; i < 10; i++)
	{
		enqueue(q, i);
	}
	while(q.first)
	{
		int val;
		dequeue(q, val);
		cout << val << " ";
	}
	cout << endl;
}