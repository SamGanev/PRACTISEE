/**
* @file practice.c
* @author ����� �.�., ��. 515�
* @date 21 ���� 2021
* @brief ��������
*/
#include<stdio.h>
#include<locale.h>
#include<math.h>
/**
* ���������� ������� ����������� ���� ����������� �� ���������
*
* @param x1 ���������� ������ ������ ����������
* @param y1 ���������� ������ ������ ����������
* @param R1 ������ ������ ����������
* @param x2 ���������� ������ ������ ����������
* @param y2 ���������� ������ ������ ����������
* @param R2 ������ ������ ����������
* @param S ������� �����������
* @return 1, ���� �������� �������
* @return 0, ���� �������� �� �������
*/

double find_area(double x1, double y1, double R1, double x2, double y2, double R2, double* S);

int main() {
	setlocale(LC_CTYPE, "rus");

	double x1, y1, x2, y2, R1, R2;
	double S;

	printf_s("������� ���������� ������ 1-�� ����������: \n");
	printf_s("x1 = "); scanf_s("%lf", &x1);
	printf_s("y1 = "); scanf_s("%lf", &y1);
	printf_s("������� ���������� ������ 2-�� ����������: \n");
	printf_s("x2 = "); scanf_s("%lf", &x2);
	printf_s("y2 = "); scanf_s("%lf", &y2);
	printf_s("������� ������ 1-�� ����������: "); scanf_s("%lf", &R1);
	printf_s("������� ������ 2-�� ����������: "); scanf_s("%lf", &R2);

	if (R1 <= 0 || R2 <= 0) { printf_s("������ �� ����� ���� ������� ��� �������������"); return 1; };

	int k = find_area(x1, y1, R1, x2, y2, R2, &S);
	if (!k) printf_s("\n���������� �� ������������");
	else {
		printf_s("\n������� ����������� ����������� = %.2f", S);
	}

	return 0;
}


double find_area(double x1, double y1, double R1, double x2, double y2, double R2, double* S) {
	// ���������� ����� �������� �����������
	double D = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	double F1, F2;
	double S1, S2;

	if (D >= R1 + R2) {
		// ���� �� ������������
		return 0;
	}
	else if (D <= fabs(R1 - R2)) {
		// ���� ���������� ������ ������
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

