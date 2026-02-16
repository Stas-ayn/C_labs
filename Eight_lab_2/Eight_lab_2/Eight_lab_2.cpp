#include <iostream>
#include <locale.h>
#include <cmath>
#include <iomanip>
using namespace std;

double rounding(double x) {
	return round(x * 1000) / 1000;
}

double Bij(int i) {
	return ((log((i * i) + 4)) / (cos(i + 2)));
}

double determination(double s[3][3]) {
	return s[0][0] * (s[1][1] * s[2][2] - s[1][2] * s[2][1])
		- s[0][1] * (s[1][0] * s[2][2] - s[1][2] * s[2][0])
		+ s[0][2] * (s[1][0] * s[2][1] - s[1][1] * s[2][0]);
}


void matrix_product(double A[3][3], double B[3][3]) {
	double product[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			double el = 0;
			for (int r = 0; r < 3; r++) {
				el += A[i][r] * B[r][j];
			}
			product[i][j] = el;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << rounding(product[i][j]) << " ";
		}
		cout << endl;
	}
}

void reversed(double s[3][3]) {
	double minor[3][3], transponed_mat[3][3];
	if (determination(s) == 0) {
		cout << "У этой матрицы нет обратной матрицы" << endl;
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int rows[2], cols[2];
			int index1 = 0, index2 = 0;
			for (int r = 0; r < 3; r++) {
				if (r != i) {
					rows[index1] = r;
					index1++;
				}
			}
			for (int c = 0; c < 3; c++) {
				if (c != j) {
					cols[index2] = c;
					index2++;
				}
			}
			double det = (s[rows[0]][cols[0]] * s[rows[1]][cols[1]]) - (s[rows[0]][cols[1]] * s[rows[1]][cols[0]]);
			double sign = ((i + j) % 2 == 0) ? 1 : -1;
			minor[i][j] = sign * det;
		}
	}
	double deter = 1 / determination(s);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			transponed_mat[i][j] = minor[j][i] * deter;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << rounding(transponed_mat[i][j]) << "  ";
		}
		cout << endl;
	}
	cout << "Произведение матриц A+B и обратной ей: " << endl;
	matrix_product(s, transponed_mat);
}

int main() {
	srand(time(0));
	setlocale(LC_ALL, "rus");
	const int rows = 3;
	double arrA[rows][rows], arrB[rows][rows], sum[rows][rows], arrT[rows][rows], arrRever[rows][rows], determinant;
	cout << "Введите элементы матрицы A от -10.0 до 10.0: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			cin >> arrA[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			arrB[i][j] = Bij(i + 1);
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {

		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			sum[i][j] = arrA[i][j] + arrB[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			arrT[i][j] = sum[j][i];
		}
	}
	cout << "Матрица A: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			cout << rounding(arrA[i][j]) << "  ";
		}
		cout << endl;
	}

	cout << "Матрица B: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			cout << rounding(arrB[i][j]) << "  ";
		} 
		cout << endl;
	}

	cout << "Сумма матриц A и B: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			cout << rounding(sum[i][j]) << "  ";
		}
		cout << endl;
	}

	cout << "Транспонированная матрица A+B: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			cout << rounding(arrT[i][j]) << " ";
		}
		cout << endl;
	}

	cout << "Матрица, обратная A+B:" << endl;
	reversed(sum);

	cout << "Произведение матриц A+B и транспонированной A+B: " << endl;
	matrix_product(sum, arrT);

	return 0;
}