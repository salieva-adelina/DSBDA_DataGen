// DSBDA_HW1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	ofstream outputfile;
	do {
		string fileName;
		cout << "Vvedite imya fayla zapisi: ";
		cin >> fileName;
		outputfile = ofstream(fileName);
	} while (!outputfile.is_open());

	double size = 0;
	while (size <= 0 || size > 100) {
		cout << "Vvedite ob'em dannih v Mb (moget bit ne celym, > 0, < 100 Mb): ";
		cin >> size;
	}
	size *= 1024 * 1024; //razmer v baytah 
	int count = (int)size / 4; //kol-vo elementov, razmer odnogo chisla = 4 bayta

	srand(time(0));

	while (count > 0) {
		int width = rand() % 20 + 10;
		int height = rand() % 20 + 10;
		if (width * height > count) { //когда последняя матрица уже не влезает по размерам - подгоняем размеры
			width = (int)sqrt(count);
			height = count / width;
			count = 0;
		}
		outputfile << setw(4) << width << setw(4) << height << endl;
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j)
				outputfile << setw(4) << rand() % 100 - 50;
			outputfile << endl;
		}
		count -= width * height;
	}
	outputfile.close();
	cout << "fail zapisan" << endl;
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
