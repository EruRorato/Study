#define _USE_MATH_DEFINES
#include "Func.h"
#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	int key = 1; // Для цикла
	do
	{
		float c; //Вводимое значение
		float x; //Вычисяемый угол для половинного деления
		float x1; //Вычисяемый угол для метода Ньютона
		float a; //Левая Граница
		float b; //Правая граница
		float e; //Относительная ошибка (1e-006)

		printf_s("Input value for calculate: ");
		
		//Инициализация
		a = M_PI;
		b = 0.0f;
		e = 0.000001f;
		
		do
		{
			scanf_s("%f", &c);
			if (c < -1.0f || c > 1.0f) { printf_s("Value should be in range [-1;1]. Try again: "); }
		} while (c < -1.0f || c > 1.0f);

		//Начало рассчетов
		
			x = arccos(a, b, c, e);
			x1 = arccos(c, e);

		//Вывод результатов
		printf_s("\nBinary Search ArcCos = %f",x);						 //Метод половинного деления
		printf_s("\nNewton Search ArcCos = %f", x1);					 //Метод Ньютона
		printf_s("\nBinary Search ArcCos = %f", acos(c)*180.0f / M_PI);  //Реальное значение
		printf("\nTry again?(1 - Yes,0 - No): ");
		scanf_s("%d", &key);
		system("cls");
	} while (key != 0);
	return 0;
}
