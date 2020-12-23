// ConsoleApplication9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <locale>
#include <iomanip>
using namespace std;

class Book
{
	char* name; // название книги
public:
	Book(char* NAME)
	{
		name = new char[strlen(NAME) + 1];
		strcpy_s(name, strlen(NAME) + 1, NAME);
		cout << "Конструктор - Книга" << endl;
	}
	~Book()
	{
		delete[] name;
		cout << "деструктор класса книга" << endl;
	}
	void bookprnt() { cout << "Название книги " << name << endl; }
};


class Opisanie : virtual public Book
{
protected:
	char* janr; // жанр книги
	int strn; // количество страниц
public:
	Opisanie(char* NAME, char* JANR, int STRN) : Book(NAME), strn(STRN)
	{
		janr = new char[strlen(JANR) + 1];
		strcpy_s(janr, strlen(JANR) + 1, JANR);
		cout << "Конструктор - Описание(D1)" << endl;
	}
	~Opisanie()
	{
		delete[] janr; ;
		cout << "деструктор класса D1" << endl;
	}
	void bookprnt()
	{
		
		cout << "Жанр книги " << janr << " количество страниц " << janr << endl;
	}
};


class Vipysk : virtual public Book
{
protected:
	int year; // год выпуска
	double count; // кол-во написаных книг
public:
	Vipysk(char* NAME, int YEAR, double COUNT) : Book(NAME), year(YEAR), count(COUNT)
	{
		cout << "Конструктор - Выпуск(D2)" << endl;
	};
	~Vipysk() { cout << "деструктор класса D2" << endl; }

	void bookprnt()
	{
		
		cout << "Год выпуска книг " << year << " кол-во книг " << count << endl;
	}
};


class Aftor : public Opisanie, public Vipysk
{
	char* familia; // Фaмилия автора
public: Aftor(char* NAME, char* JANR, int STRN, int YEAR, double COUNT, char* AFTOR) :
	Opisanie(NAME, JANR, STRN), Vipysk(NAME, YEAR, COUNT), Book(NAME)
{
	familia= new char[strlen(AFTOR) + 1];
	strcpy_s(familia, strlen(AFTOR) + 1, AFTOR);
	cout << "Конструктор - Автор" << endl;
}
	  ~Aftor()
	  {
		  delete[] familia;
		  cout << "деструктор класса D12" << endl;
	  }

};


int main()
{
	setlocale(LC_ALL, "Russian");
	char* name = new char[29];
	cout << "Введите название книги" << endl;
	cin >> name;

	char* col = new char[29];
	cout << "Введите жанр книги" << endl;
	cin >> col;


	char* nm = new char[29];
	cout << "Введите Фамилию автора" << endl;
	cin >> nm;

	int ses = 0;
	cout << "Введите кол-во сраниц" << endl;
	while (!(cin >> ses))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Повторите попытку: ";
	}

	int god = 0;
	cout <<"Введите год выпуска" << endl;
	while (!(cin >> god))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Повторите попытку: ";
	}

	int coun = 0;
	cout << "Введите кол-во книг" << endl;
	while (!(cin >> coun))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Повторите попытку: ";
	}


	Aftor cart(name, col, ses, god, coun, nm); // объект класса Aftor
	Aftor* ptr = &cart; // указатель на созданный объект. 
	cart.Book::bookprnt();
	cart.Opisanie::bookprnt();
	cart.::Vipysk::bookprnt();
	return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
