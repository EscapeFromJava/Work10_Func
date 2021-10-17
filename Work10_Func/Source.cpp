#include <iostream>
#include <math.h>

using namespace std;

const int SIZE = 7;
void printArray(int mas[SIZE]);
void inputArray(int mas[SIZE]);
int sumArray(int mas[SIZE]);
int sumNegArray(int mas[SIZE]);
int maxElemArray(int mas[SIZE]);
int searchMaxNeg(int mas[SIZE]);
void swapMinMaxArray(int mas[SIZE]);
void volumeNumArray(int mas[SIZE]);
void volumeNearNumArray(int mas[SIZE]);
int averageMin2MaxArray(int mas[SIZE]);
void deviationArray(int mas[SIZE]);

int main() {
	setlocale(LC_ALL, "rus");
	int massive[SIZE];
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
		massive[i] = rand() % 10 - 5;
	/*massive[0] = 123;
	*massive += 2;
	cout << massive[0] << endl;
	massive[SIZE - 1] = 444;
	*(massive + SIZE - 1) *= 2;
	cout << massive[SIZE - 1] << endl;
	printArray(massive);
	inputArray(massive);*/
	printArray(massive);
	cout << "[1] Сумма элементов массива = " << sumArray(massive) << endl; //[1]
	cout << "[2] Сумма отрицательных элементов массива = " << sumNegArray(massive) << endl; //[2]
	cout << "[3] Максимальный элемент массива = " << maxElemArray(massive) << endl; //[3]
	cout << "[4] Номер минимального элемента массива = " << searchMaxNeg(massive) << endl; //[4]
	swapMinMaxArray(massive); //[5]
	volumeNumArray(massive); //[6]
	volumeNearNumArray(massive); //[7]
	cout << "[8] Cреднее арифметическое всех элементов массива, за исключением двух максимальных = " << averageMin2MaxArray(massive) << endl; //[8]
	deviationArray(massive); //[9]
	return 0;
}

void printArray(int mas[SIZE])
{
	for (int i = 0; i < SIZE; i++)
		cout << mas[i] << " ";
	cout << endl;
}

void inputArray(int mas[SIZE])
{
	cout << "Введите 7 чисел:" << endl;
	for (int i = 0; i < SIZE; i++)
		cin >> mas[i];
}

int sumArray(int mas[SIZE]) //1
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += mas[i];
	}
	return sum;
}

int sumNegArray(int mas[SIZE]) //2
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++) {
		if (mas[i] < 0) {
			sum += mas[i];
		}
	}
	return sum;
}

int maxElemArray(int mas[SIZE]) //3
{
	int max = 0;
	for (int i = 0; i < SIZE; i++) {
		if (mas[i] > max) {
			max = mas[i];
		}
	}
	return max;
}

int searchMaxNeg(int mas[SIZE]) //4
{
	int maxNeg = 0, m = 0;
	for (int i = 0; i < SIZE; i++) {
		if (mas[i] < maxNeg) {
			maxNeg = mas[i];
			m = i;
		}
	}
	return m;
}

void swapMinMaxArray(int mas[SIZE]) //5
{
	cout << "[5] Поменять местами минимальный и максимальный элементы массива ";
	int maxNeg = mas[0], maxPos = mas[0], reserv = mas[0], nMaxNeg = 0, nMaxPos = 0;
	for (int i = 0; i < SIZE; i++) {
		if (mas[i] < maxNeg) {
			maxNeg = mas[i];
			nMaxNeg = i;
		}
		if (mas[i] > maxPos) {
			maxPos = mas[i];
			nMaxPos = i;
		}
	}
	mas[nMaxNeg] = reserv;
	mas[nMaxPos] = maxNeg;
	mas[nMaxNeg] = maxPos;
	for (int i = 0; i < SIZE; i++)
		cout << mas[i] << " ";
	cout << " " << endl;
}

void volumeNumArray(int mas[SIZE]) //6
{
	int x, volume = 0;
	cout << "[6] Введите число для подсчета количества вхождений: ";
	cin >> x;
	for (int i = 0; i < SIZE; i++) {
		if (mas[i] == x) {
			volume++;
		}
	}
	cout << "[6] Количество вхождений числа " << x << " равно = " << volume << endl; //[6]
}

void volumeNearNumArray(int mas[SIZE])
{
	int x, temp1, temp2 = -32768, masI = 0;
	cout << "[7] Введите число: ";
	cin >> x;
	for (int i = 0; i < SIZE; i++) {
		temp1 = x - mas[i];
		if (abs(temp1) < abs(temp2)) {
			temp2 = temp1;
			masI = i;
		}
	}
	cout << "[7] Номер элемента, наиболее близкого к числу " << x << " равен = " << masI << " " << endl; //[6]
}

int averageMin2MaxArray(int mas[SIZE]) //8
{
	int temp;
	double sum = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE - 1; j++) {
			if (mas[j] > mas[j + 1]) {
				temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < (SIZE - 2); i++) {
		sum += mas[i];
	}
	sum /= (SIZE - 2);
	return sum;
}

void deviationArray(int mas[SIZE]) //9
{
	double deviation;
	double sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += mas[i];
	}
	sum /= SIZE;
	cout << "[9] Cреднее арифметическое всех элементов массива = " << sum << endl;
	for (int i = 0; i < SIZE; i++) {
		deviation = (mas[i] / sum) * 100;
		cout << "Отколонение [" << i << "] элемента = " << mas[i] << " от среднего значения = " << abs(deviation) << "%" << endl;
	}
}