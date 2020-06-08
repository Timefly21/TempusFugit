#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
using namespace std;

int bandwich(int ban)
{
	int i, B, num;
	B1:
		cin >> num;
		if (num < 1 || num > 6) {
			printf("\nВы ввели неверный код, попробуйте снова\n");
			goto B1;
		}
		if (num == 1 && (ban == 1 || ban == 7 || ban == 11 || ban == 13 || ban == 14 || ban == 17 || ban == 18 || ban == 19 || ban == 20 || ban == 21 || ban == 24 || ban == 28 || ban == 30))
		{
			printf("В данном бэнде эта ширина канала недоступна\n");
			goto B1;
		}
		if (num == 2 && (ban == 1 || ban == 7 || ban == 11 || ban == 13 || ban == 14 || ban == 17 || ban == 18 || ban == 19 || ban == 20 || ban == 21 || ban == 24 || ban == 30))
		{
			printf("В данном бэнде эта ширина канала недоступна\n");
			goto B1;
		}
		if (num == 4 && ban == 31)
		{
			printf("В данном бэнде эта ширина канала недоступна\n");
			goto B1;
		}
		if (num == 5 && (ban == 5 || ban == 8 || ban == 11 || ban == 12 || ban == 13 || ban == 14 || ban == 17 || ban == 24 || ban == 29 || ban == 30 || ban == 31))
		{
			printf("В данном бэнде эта ширина канала недоступна\n");
			goto B1;
		}
		if (num == 6 && (ban == 5 || ban == 8 || ban == 11 || ban == 12 || ban == 13 || ban == 14 || ban == 17 || ban == 18 || ban == 19 || ban == 21 || ban == 24 || ban == 26 || ban == 29 || ban == 30 || ban == 31))
		{
			printf("В данном бэнде эта ширина канала недоступна\n");
			goto B1;
		}
	switch (num)
	{
	case 1:B = 6; break;
	case 2:B = 15; break;
	case 3:B = 25; break;
	case 4:B = 50; break;
	case 5:B = 75; break;
	case 6:B = 100; break;
	}
	return(B);
}
int modulation() {
	char num;
	int i, Q;
	num = 0; i = 0;
	do {
		cin >> num;
		if (num != '1' && num != '2' && num != '3' && num != '4') printf("\nВы ввели неверный код, попробуйте снова\n");  else i = 1;
	} while (i != 1);
	switch (num)
	{
	case '1':Q = 2; break;
	case '2':Q = 4; break;
	case '3':Q = 5; break;
	case '4':Q = 6; break;
	}
	return(Q);
}
int MIMO() {
	char num;
	int i, M;
	num = 0; i = 0;
	do {
		cin >> num;
		if (num != '1' && num != '2' && num != '3') printf("\nВы ввели неверный код, попробуйте снова\n");  else i = 1;
	} while (i != 1);
	switch (num)
	{
	case '1':M = 1; break;
	case '2':M = 2; break;
	case '3':M = 4; break;
	}
	return(M);
}
int percent() {
	int i, P;
	i = 0;
	do {
		cin >> P;
		if (P < 0 || P>25) printf("\nВы ввели неверный процент, попробуйте снова\n");  else i = 1;
	} while (i != 1);
	return (P);
}
int bandf(int Yes)
{
	int i = 0, B, Q, M, P, bandnum, SYM=7;
	float Thr;
	if (Yes == 1)
	{
		printf("\nВыберите циклический префикс\n6 - расширенный\n7 - нормальный\n");
		do {
			cin >> SYM;
			if (SYM != 6 && SYM != 7)
				printf("\nВы ввели неверное количество, попробуйте снова\n");
			else i = 1;
		} while (i != 1);
	}
	printf("\nВыберите номер бэнда \n(1,2,3,4,5,7,8,11,12,13,14,17,18,19,20,21,24,25,26,28,29,30,31):\n");
	i = 0;
	do {
		cin >> bandnum;
		if (bandnum < 1 || bandnum> 31 || bandnum == 6 || bandnum == 9 || bandnum == 10 || bandnum == 15 || bandnum == 16 || bandnum == 22 || bandnum == 23 || bandnum == 27)
			printf("\nВы ввели неверный номер, попробуйте снова\n"); 
		else i = 1;
	} while (i != 1);
	printf("Выбор ширины канала:\nНапишите код ширины канала из данных:\n1-1.4 МГц\n2-3 МГц\n3-5 МГц\n4-10 МГц\n5-15 МГц\n6-20 МГц\n");
	B = bandwich(bandnum);
	printf("\nВыбор модуляции:\nНапишите код модуляции из данных:\n1-QPSK\n2-16QAM\n3-32QAM\n4-64QAM\n");
	Q = modulation();
	printf("\nВыберите схему MIMO:\n1-без MIMO\n2-MIMO 2x2\n3-MIMO 4x4\n");
	M = MIMO();
	printf("\nНапишите процент служебной информации(от 0% до 25%)\n");
	P = percent();
	Thr = (B * 12 * SYM * 2 * Q * M * (1 - ((float)P / 100))) / 1000;
	return(Thr);
}
int main()
{
	int i = 0, BANDamount, Addsym;
	float S=0;
	char num;
	setlocale(LC_CTYPE, "rus");
	printf("Калькулятор пропускной способности сот LTE\nВерсия 1.1 \nПропускная способность будет зависеть от следующих данных:\nШирина канала, модуляция, схемам MIMO, процент служебной информации\n" );
	printf("\nБудет ли учитываться возможность выбора циклического префикса?\nНапишите 0, если не будет или 1, если будет\n");
	do {
		cin >> Addsym;
		if (Addsym != 1 && Addsym != 0)
			printf("\nВы ввели неверный код, попробуйте снова\n");
		else i = 1;
	} while (i != 1);
	i = 0;
	printf("\nВведите количество бэндов (от 1 до 32):\n");
	do {
		cin >> BANDamount;
		if (BANDamount < 1 || BANDamount>32)
		printf("\nВы ввели неверное количество, попробуйте снова\n");  
		else 
			i = 1;
	} while (i != 1);
	for (i = 0; i < BANDamount; i++)
	{
		printf("\nЗаполнение %i бэнда:", i+1);
		S = S + bandf(Addsym);

	}
	
	cout << "Максимальная пропускная способность сот LTE при данных условиях = " << S << "Мбит/с";
	printf("\n(c) Гришко Е.А. 2020\nВсе права защищены");
	cin >> S;
}
