#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
#include <cstdlib>
#include <ctime>
using namespace std;
enum Spec { KN, ME, IT };
string specStr[] = { "КН", "МЕ", "ІТ" };
struct Students
{
	string prizv;
	int kurs;
	Spec spec;
	int phyg;
	int mag;
	int ing;
};
void Create(Students* s, const int N);
void Print(Students* s, const int N);
void CountG(Students* s, const int N);
void Findpr(Students* s, const int N);
int main()
{ 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
	srand((unsigned)time(NULL));
	int N;
	cout << "Введіть N: "; cin >> N;

	Students* s = new Students[N];
	Create(s, N);
	Print(s, N);
	CountG(s, N);
	cout << endl;
	Findpr(s, N);
	cout << endl;
	return 0;
}
void Create(Students* s, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); 
		cin.sync(); 

		cout << " прізвище: "; getline(cin, s[i].prizv);
		cout << " курс: "; cin >> s[i].kurs;
		cout << " спеціальність( 0-KH, 1-ME, 2-IT): ";
		cin >> spec;
		s[i].spec = (Spec)spec;
		s[i].phyg = rand() % 4 + 2;
		s[i].mag = rand() % 4 + 2;
		s[i].ing = rand() % 4 + 2;
		cout << endl;
	}
}
void Print(Students* s, const int N)
{
	cout << "============================================================="
		<< endl;
	cout << "| № |  Прізвище  | Курс | Спец. | Фізика | Матем. | Інформ. |"
		<< endl;
	cout << "-------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(11) << left << s[i].prizv
			<< "| " << setw(4) << right << s[i].kurs << " "
			<< "| " << setw(6) << left << specStr[s[i].spec] << "| " << setw(6) << setprecision(2) << fixed << right
				<< s[i].phyg << " |" << " " << setw(6) << right
				<< s[i].mag << " |" << setw(8) << right << s[i].ing << " "
			<< "| " << endl;
	}
	cout << "=============================================================" << endl;
	cout << endl;
}
void CountG(Students* s, const int N)
{
	cout << "Кількість оцінок 5, 4, 3 з математики: " << endl;
	int kfive = 0, kfour = 0, kthree = 0;
	for (int i = 0; i < N; i++)
	{
		if (s[i].mag == 5)
			kfive++;
		if (s[i].mag == 4)
			kfour++;
		if (s[i].mag == 3)
			kthree++;
	}
	cout << "5: " << kfive << "  4: " << kfour << "  3: " << kthree << endl;
}
void Findpr(Students* s, const int N)
{
	cout << "Прізвища студентів, які отримали і з фізики і з математики оцінку 5: " << endl;
	for (int i = 0; i < N; i++)
	{
		if (s[i].phyg == 5 && s[i].mag == 5)
			cout << s[i].prizv << endl;
	}
}