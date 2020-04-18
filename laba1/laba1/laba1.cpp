#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
using namespace std;
int main() {
	int N, a, b = 0;
	setlocale(LC_CTYPE, "rus"); // Подключаем кириллицу
	printf("Автор: Гришко Егор Александрович, группа РИ-190008. \n Задача: определить является ли число натуральное число N палиндромом");
	printf("Введите натуральное число N \n");
	cin >> N;
	if (N <= 0) printf("Вы ввели ненатуральное число"); else
	{
		a = N;
		do {
			b = b * 10 + a % 10;
			a = a / 10;
		} while (a != 0);
		if (b == N) printf("Число N = %i - палиндром", N);
		else printf("Число N = %i - не палиндром", N);

	}
	return 0;
}

