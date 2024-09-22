#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Humans {
	string firstName;
	string lastName;
	string birthDate;
};
class Person {
public:
	
	int PeopleSize;
	int currentSize;
	int humanNum;
	int index;
	Humans people[10];

	Person() {
		
		PeopleSize = 10;
		currentSize = 3;

		people[0] = { "Иван", "Иванов", "01.01.1990" };
		people[1] = { "Петр", "Петров", "02.02.1991" };
		people[2] = { "Анна", "Сидорова", "03.03.1992" };
		
	}
	void ShowPeople() {

		cout << "\nИнформация о людях:\n";
		for (int i = 0; i < currentSize; i++) {
			cout << "Человек " << i + 1 << ":\n";
			cout << "Имя: " << people[i].firstName << "\n";
			cout << "Фамилия: " << people[i].lastName << "\n";
			cout << "Дата рождения: " << people[i].birthDate << "\n\n";
		}
		HumanChoise();
	}
	void AddPeople() {
		cout << "\nВведите имя человека: ";
		cin >> people[currentSize].firstName;
		cout << "\nВведите фамилию человека: ";
		cin >> people[currentSize].lastName;
		cout << "\nВведите дату рождения человека: ";
		cin >> people[currentSize].birthDate;

		currentSize++;

		HumanChoise();
	}
	void FoundPeople() {
		cout << "Напишите номер человека которого нужно отобразить: \n";
		cin >> humanNum;

		cout << "Имя: " << people[humanNum].firstName << "\n";
		cout << "Фамилия: " << people[humanNum].lastName << "\n";
		cout << "Дата рождения: " << people[humanNum].birthDate << "\n\n";

		HumanChoise();
	}
	void DropPeople() {
		
		cout << "Введите номер человека, которого хотите удалить: ";
		cin >> index;
		if (index >= 1 && index <= currentSize) {
			for (int i = index - 1; i < currentSize - 1; i++) {
				people[i] = people[i + 1];
			}
			currentSize--;
		}
		else {
			cout << "Некорректный номер человека.\n";
		}
		HumanChoise();
	}

	void HumanChoise() {

		int choise;
		cout << "-------------------------------------\n";
		cout << "|Выберите пункт:                    |\n";
		cout << "|1. Посмотреть массив с людьми.     |\n";
		cout << "|2. Добавить человека в массив.     |\n";
		cout << "|3. Найти человека по номеру.       |\n";
		cout << "|4. Удалить человека из массива.    |\n";
		cout << "|0. Выйти.                          |\n";
		cout << "-------------------------------------\n";

		cin >> choise;
		while (true) {
			switch (choise) {
			case 1:
				ShowPeople();
				break;
			case 2:
				AddPeople();
				break;
			case 3:
				FoundPeople();
				break;
			case 4:
				DropPeople();
				break;
			case 0:
				break;
			default:
				break;
			}
		}
	}
};
class MassiveDoMath {
public:


	int arr[100];
	int currentSize = 100;
	int element;
	int pos;

	MassiveDoMath() {
		srand(time(0)); 

		for (int i = 0; i < currentSize - 1; i++) {
			arr[i] = Math();
		}
	}



	void OutPutMassive() {
		for (int i = 0; i < currentSize - 1; i++) {
			cout << arr[i] << "\n";
		}
		ChoiseMassive();
	}

	int Math() {
		return rand(); 
	}

	void ChoiseElement() {

		cout << "Выберите номер элемента массива, который вы хотите увидеть\n";
		cin >> element; 
		if (element >= 0 && element < currentSize - 1) {
			cout << arr[element] << "\n";
		}
		else {																
			cout << "Некорректный номер элемента, либо он был удален\n";
		}
		ChoiseMassive();
	}

	void DropElement() {

		cout << "Выберите номер элемента массива, который вы хотите удалить\n";
		cin >> element;
		if (element >= 0 && element < currentSize) {
			for (int i = element; i < currentSize - 1; i++) {
				arr[i] = arr[i + 1];
			}
			currentSize--;
			cout << "Элемент удален.\n";
			ChoiseMassive();
		}
		else {
			cout << "Некорректный номер элемента, либо он был удален\n";
		}
	}

	void AddElement() {
		cout << "Выберите номер места в массиве, чтобы добавить туда число.\n";
		cin >> pos;
		if (pos < 0 || pos > currentSize) {
			cout << "Некорректная ввод.\n";
			return;
		}
		cout << "Введите значение элемента.\n";
		cin >> element;
		for (int i = currentSize; i > pos; i--) {
			arr[i] = arr[i - 1];
		}
		arr[pos] = element;
		currentSize++;
		ChoiseMassive();
	}

	void ChoiseMassive() {
		int choise;
			cout << "----------------------------------------------\n";
			cout << "|Выберите пункт:                             |\n";
			cout << "|1. Вывести на экран весь массив.            |\n";
			cout << "|2. Вывести на экран число по номеру массива.|\n";
			cout << "|3. Удалить элемент массива со сдвигом.      |\n";
			cout << "|4. Добавить элемент в массив.               |\n";
			cout << "----------------------------------------------\n";

			cin >> choise;
			while (true) {
				switch (choise)
				{
				case 1:
					OutPutMassive();
					break;
				case 2:
					ChoiseElement();
					break;
				case 3:
					DropElement();
					break;
				case 4:
					AddElement();
					break;
				case 0:

				default:
					break;
				}
			}
		}
	
};

void MathHumanChoise() {
	int answ;
	MassiveDoMath obj;
	Person pers;
	cout << "-----------------------------------\n";
	cout << "|Выберите с чем будем работать:   |\n";
	cout << "|1. С массивом чисел.             |\n";
	cout << "|2. С массивом людей.             |\n";
	cout << "-----------------------------------\n";
	
	cin >> answ;
	switch (answ){
	case 1:
		obj.ChoiseMassive();
		break;
	case 2:
		pers.HumanChoise();
		break;
	default:
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	MathHumanChoise();
}


