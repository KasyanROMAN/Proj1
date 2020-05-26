#include <iostream> 
#include<iomanip>
#include<string>
#include<map>
using namespace std;
template<typename T>
class vectorClass
{
	int* arr;
	int capacity;
	int current;
public:
	vectorClass()
	{
		arr = new int[1];
		capacity = 1;
		current = 0;
	}
	void push(int data)
	{
		if (current == capacity)
		{
			int* temp = new int[2 * capacity];
			for (int i = 0; i < capacity; i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			capacity *= 2;
			arr = temp;
		}
		arr[current] = data;
		current++;
	}
	void push(int data, int index)
	{
		if (index == capacity)
			push(data);
		else
			arr[index] = data;
	}
	int get(int index)
	{
		if (index < current)
			return arr[index];
	}
	void pop()
	{
		current--;
	}
	int size()
	{
		return current;
	}
	int getcapacity()
	{
		return capacity;
	}
	void print()
	{
		for (int i = 0; i < current; i++) {

			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
template< typename VALUE, typename D, typename A, typename R>
class MyMap
{
public:
	VALUE a;
	D b;
	A c;
	R d;

public:
	void push(VALUE a, D b, A c, R d)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
	void print()
	{
		const int bh = 3;
		int DR[bh] = { b,c,d };
		for (int i = 0; i < bh; i++)
		{
			cout << DR[i] << endl;
		}

	}
	void sum()
	{
		double sum = 0;
		const int bh = 3;
		int DR[bh] = { b,c,d };
		for (int i = 0; i < bh; i++)
		{
			sum += DR[i];
		}
		cout << "Сума:" << a << "-" << sum << endl;
	}
	void averagevalue()
	{
		double sum = 0;
		const int bh = 3;
		int DR[bh] = { b,c,d };
		for (int i = 0; i < bh; i++)
		{
			sum += DR[i];
		}
		sum = sum / bh;
		cout << "Середнє значення:" << a << "-" << sum << endl;
	}
	void sort()
	{
		const int bh = 3;
		int DR[bh] = { b,c,d };

		double sum = 0;

		for (int i = 1; i < bh; ++i)
		{
			for (int r = 0; r < bh - i; r++)
			{
				if (DR[r] < DR[r + 1])
				{

					int temp = DR[r];
					DR[r] = DR[r + 1];
					DR[r + 1] = temp;
				}
			}
		}
		cout << "Сортування данних:" << a << "-";
		for (int i = 0; i < bh; i++)
		{

			cout << DR[i] << setw(5);
		}
		cout << endl;
	}
};
std::istream& operator >> (std::istream& in, MyMap<char[30], double, double, double>& p)
{
	in >> p.a >> p.b >> p.c >> p.d;
	return in;
}
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Меню" << endl;
	cout << "1-Вывести данные Vector" << endl;
	cout << "2-Вводить данные самостоятельно" << endl;
	MyMap<string, double, double, double>p;
	while (1)
	{
		int g;
		cin >> g;
		switch (g)
		{
		case 1:
		{
			vectorClass<double> v;
			v.push(10);
			v.push(20);
			v.push(30);
			v.push(40);
			v.push(50);
			cout << "Vector Size :" << v.size() << endl;
			cout << "Vector capacity : " << v.getcapacity() << endl;
			cout << "Vector elements : ";
			v.print();
			v.push(100, 1);
			cout << "\nAfter updating 1st index" << endl;
			cout << "Vector elements : ";
			v.print();
			cout << "Element at 1st index : " << v.get(1) << endl;
			v.pop();
			cout << "\nAfter deleting last element" << endl;
			cout << "Vector size : "
				<< v.size() << endl;
			cout << "Vector capacity : " << v.getcapacity() << endl;
			cout << "Vector elements : ";
			v.print();
		}
		break;
		case 2:
		{
			MyMap<char[30], double, double, double> bob;
			std::cout << "Введите имя и три числа: ";
			std::cin >> bob;
			bob.sum();
			bob.sort();
			bob.averagevalue();
		}
		break;
		}
	}
	system("pause");
	return 0;
}