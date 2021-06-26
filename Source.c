/**
* @file practice.c
* @author Ганев С.М., гр. 515Б
* @date 21 июня 2021
* @brief Практика
*/
#include<stdio.h>
#include<locale.h>
#include<math.h>
/**
* Вычисление площади пересечения двух окружностей на плоскости
*
* @param x1 координата центра первой окружности
* @param y1 координата центра первой окружности
* @param R1 радиус первой окружности
* @param x2 координата центра второй окружности
* @param y2 координата центра второй окружности
* @param R2 радиус второй окружности
* @param S площадь пересечения
* @return 1, если операция успешна
* @return 0, если операция не успешна
*/

double find_area(double x1, double y1, double R1, double x2, double y2, double R2, double* S);

int main() {
	setlocale(LC_CTYPE, "rus");

	double x1, y1, x2, y2, R1, R2;
	double S;

	printf_s("Введите координаты центра 1-ой окружности: \n");
	printf_s("x1 = "); scanf_s("%lf", &x1);
	printf_s("y1 = "); scanf_s("%lf", &y1);
	printf_s("Введите координаты центра 2-ой окружности: \n");
	printf_s("x2 = "); scanf_s("%lf", &x2);
	printf_s("y2 = "); scanf_s("%lf", &y2);
	printf_s("Введите радиус 1-ой окружности: "); scanf_s("%lf", &R1);
	printf_s("Введите радиус 2-ой окружности: "); scanf_s("%lf", &R2);

	if (R1 <= 0 || R2 <= 0) { printf_s("Радиус не может быть нулевым или отрицательным"); return 1; };

	int k = find_area(x1, y1, R1, x2, y2, R2, &S);
	if (!k) printf_s("\nОкружности не пересекаются");
	else {
		printf_s("\nПлощадь пересечения окружностей = %.2f", S);
	}

	return 0;
}


double find_area(double x1, double y1, double R1, double x2, double y2, double R2, double* S) {
	// Расстояние между центрами окружностей
	double D = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	double F1, F2;
	double S1, S2;

	if (D >= R1 + R2) {
		// Если не пересекаются
		return 0;
	}
	else if (D <= fabs(R1 - R2)) {
		// Если окружность внутри другой
		return 0;
	}
	else {

		F1 = 2 * acos((R1 * R1 - R2 * R2 + D * D) / (2 * R1 * D));
		F2 = 2 * acos((R2 * R2 - R1 * R1 + D * D) / (2 * R2 * D));
		S1 = (R1 * R1 * (F1 - sin(F1))) / (2);
		S2 = (R2 * R2 * (F2 - sin(F2))) / (2);

		*S = S1 + S2;
		return 1;
	}

}

