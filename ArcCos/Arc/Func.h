#define _USE_MATH_DEFINES
#include<iostream>
#include <cmath>
using namespace std;

float MyCos(float x, float c)
{
	return cos((double)x) - c;
}

int GetSign(float n)  //Рассчет знака
{
	if (n > 0) { return 1; }
	else
	{
		if (n < 0){ return -1; }
		else { return 0; }
	}
}
float arccos(float a, float b, float c, float e) //Метод Половинного деления (перегрузка #1 arccos)
{
	float x;
	float a1,a2; //временные переменные
	while (fabs(a - b) > e*fmax(fabs(a), fabs(b)))
	{
		x = (a + b) / 2.0f;
		a1 = MyCos(a, c);
		a2 = MyCos(x, c);
		if (GetSign(a1)*GetSign(a2)>0)
			a = x;
		else
			b = x;
	}
	x *= 180.0f / M_PI;
	return x;
}

float arccos(float c, float e) //Метод Ньютона (перегрузка #2 arccos)
{
	float x = 1.0f;
	float x1 = x - (cos(x) - c) / (-1.0f*sin(x));
	while (fabs(x - x1)>e*fmax(fabs(x), fabs(x1)))
	{
		x = x1;
		x1 = x1 - MyCos(x1, c) / (-1.0f*sin(x1));
	}
	x1 *= 180.0f / M_PI;
	return x1;
}