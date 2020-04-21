#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
using namespace std;
int main()
{
	int i=0,B,Q,M,P;
	float S;
	char num;
	setlocale(LC_CTYPE, "rus");
	printf("Калькулятор пропускной способности сот LTE\nВерсия 0.1\nПропускная способность будет зависеть от следующих данных:\nШирина канала, модуляция, схемам MIMO, процент служебной информации\n" );
	printf("Выбор ширины канала:\nНапишите код ширины канала из данных:\n1-1.4 МГц\n2-3 МГц\n3-5 МГц\n4-10 МГц\n5-15 МГц\n6-20 МГц\n");
	do {
		cin >> num;
		if (num != '1' && num != '2' && num != '3' && num != '4' && num != '5' && num != '6') printf("\nВы ввели неверный код, попробуйте снова\n");  else i = 1;
		} 
	while (i != 1);
		switch (num)
		{
		case '1':B = 6; break;
		case '2':B = 15; break;
		case '3':B = 25; break;
		case '4':B = 50; break;
		case '5':B = 75; break;
		case '6':B = 100; break;
		}
		printf("\nВыбор модуляции:\nНапишите код модуляции из данных:\n1-QPSK\n2-16QAM\n3-32QAM\n4-64QAM\n");
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
		printf("\nВыберите схему MIMO:\n1-без MIMO\n2-MIMO 2x2\n3-MIMO 4x4\n");
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
		printf("\nНапишите процент служебной информации(от 0% до 25%)\n");
		i = 0;
		do {
			cin >> P;
			if (P<0 || P>25) printf("\nВы ввели неверный процент, попробуйте снова\n");  else i = 1;
		} while (i != 1);
		S = (B * 84 * 2 * Q * M * (1 - ((float)P / 100)))/1000;
		cout << "Максимальная пропускная способность сот LTE при данных условиях = " << S << "Мбит/с";
}