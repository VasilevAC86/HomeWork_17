# include <iostream>
#include<cstdlib>
#include<ctime>

// Глобально объявляем переменные для хранения начала и конца диапазона чисел для формирования значений элементов массива в задачах 2 и 4
int range_Start, range_End; 

double mean(double a, double b) { // Функция расчёта среднего арифметического двух чисел для задачи 1
	return (a + b) / 2;
}

char choice_Array_Formation() { // Функция выбора способа формирования массива для задач 2 и 4
	std::cout << "Specify how to fill the array:\nPress \'\033[94m1\033[0m\' to manually populate the array \033[90mor\033[0m \033[94mother key\033[0m to to fill the array with random numbers\nYour choice - >";
	char choice;
	std::cin >> choice;
	std::cout << std::endl;
	return choice;
}

void range() { // Процедура для формирования диапазона значений элементов массива в задачах 2 и 4
	std::cout << "Enter the start of the range = ";
	std::cin >> range_Start;
	std::cout << "Enter the end of the range = ";
	std::cin >> range_End;
	while (range_End < range_Start) {
		std::cout << "Input error! The end of the range cannot be less than its beginning!\nEnter the start of the range = ";
		std::cin >> range_Start;
		std::cout << "Enter the end of the range = ";
		std::cin >> range_End;
	}
}

void array_Formation(char choice_Array_Formation, int array[], const int length) { // Процедура формирования массива для задач 2 и 4	
	switch (choice_Array_Formation) {
	case '1':
		for (short i = 0; i < length; i++) {
			std::cout << "Enter array element N " << i << " = ";
			std::cin >> array[i];
		}
		break;
	default:
		range();
		srand(time(NULL));
		for (short i = 0; i < length; i++)
			array[i] = rand() % (range_End - range_Start + 1) + range_Start;
	}	
}

void print_Array(int array[], const int length) { // Процедура вывода массива для задач 2 и 4	
	for (short i = 0; i < length; i++)
		std::cout << array[i] << ", ";
	std::cout << "\b\b\n\n";
}

double mean_Arr(int array[], const int length) { // Функция расчёта средне арифметического значения массива для задачи 2 
	int sum = 0, counter = 0; // Переменные для хранения суммы элементов массива и счётчик кол-ва элементов
	for (short i = 0; i < length; i++) {
		sum += array[i];
		counter++;
	}
	double result = sum / double(counter);
	return result;
}

void powers(double N, short M) { // Процедура вывода числа N во всех степенях до M включительно для задачи 3
	std::cout << "\033[92mPowers of " << N << " up to " << M << " inclusive:\033[0m\n";
	for (short i = 0; i <= M; i++)
		std::cout << N << " to the power of " << i << " is " << pow(N, i) << '\n';
}

void positive_Arr(int arr[], const int length) { // Процедура проверки каждого элемента массива и замена его на положительное значение в случае, если элемент отрицательный
	for(short i = 0; i < length; i++)
		if (arr[i] < 0)
			arr[i] = abs(arr[i]);
}

int main() {

	// Задача 1. Среднее арифметическое двух чисел.
	std::cout << "\033[91mTask 1. Arithmetic mean of two numbers\033[0m\n\n";
	double number_1, number_2;
	std::cout << "Enter the first number -> ";
	std::cin >> number_1;
	std::cout << "Enter the second number -> ";
	std::cin >> number_2;
	std::cout << "\033[92mArithmetic mean of numbers " << number_1 << " and " << number_2 << " is " << mean(number_1, number_2) << "\033[0m\n\n";

	// Задача 2. Среднее арифметическое значение всех элементов массива
	std::cout << "\033[91mTask 2. Arithmetic mean of all array elements\033[0m\n\n";
	const int length_Array = 10; // Размер массива		
	int array[length_Array]{}; // Объявляем одномерный массив	
	array_Formation(choice_Array_Formation(), array, length_Array);
	std::cout << "\n\033[92mSource array:\033[0m\n\n";
	print_Array(array, length_Array);
	std::cout << "\033[92mArithmetic mean of all array elements is " << mean_Arr(array, length_Array) << "\033[0m\n\n";

	// Задача 3. Возведение в степень
	std::cout << "\033[91mTask 3. Exponentiation\033[0m\n\nEnter the number = ";
	double N; // Переменная для хранения числа
	short M; // Переменная для хранения степени числа
	std::cin >> N;
	std::cout << "Enter the power of a number = ";
	std::cin >> M;
	std::cout << std::endl;
	powers(N, M);
	std::cout << "\n\n";

	// Задача 4. Замена отрицательных значений элементов массива на положительные
	std::cout << "\033[91mTask 4. Replacing negative values of array elements with positive ones\033[0m\n\n";
	const int length_Arr = 11; // Размер массива		
	int arr[length_Arr]{}; // Объявляем одномерный массив	
	array_Formation(choice_Array_Formation(), arr, length_Arr);
	std::cout << "\n\033[92mSource array:\033[0m\n\n";
	print_Array(arr, length_Arr);
	positive_Arr(arr, length_Arr);
	std::cout << "\033[92mFinal array:\033[0m\n\n";
	print_Array(arr, length_Arr);

	return 0;
}