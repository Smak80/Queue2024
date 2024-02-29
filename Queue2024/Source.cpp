#include <iostream>
#include <fstream>
#include "queue.h"
using namespace std;

void show_queue_data(queue q)
{
	auto* curr = q.first;
	while (curr)
	{
		cout << curr->name << " " << curr->age << "\n";
		curr = curr->next;
	}
	cout << endl;
}

void main()
{
	setlocale(LC_ALL, "");

	queue trud;
	queue ne_trud;

	ifstream file("persons.txt");
	if (file)
	{
		char* name = new char[256];
		int age;
		while (!file.eof())
		{
			file >> name;
			file >> age;
			enqueue(age >= 14 && age < 65 ? trud : ne_trud, name, age);
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
}