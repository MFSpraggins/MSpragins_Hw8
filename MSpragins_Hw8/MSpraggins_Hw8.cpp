#include<iostream>
#include <iomanip>
#include <vector>
using namespace std;

void displayArray(int gradesArray[], int size);
void selectionSort(int gradesArray[], int size);
int findMAX(int gradesArray[], int size);
int findMIN(int gradesArray[], int size);
double findAvg(int gradesArray[], int size);
const int ARRAYSIZE = 50;


int main()
{
	int numOfGrades;
	cout << "How many scores do you want to enter? ";
	cin >> numOfGrades;

	int grades[ARRAYSIZE];

	for (int i = 0; i < numOfGrades; i++)
	{
		cout << "Enter score #" << i +1 << ": ";
		cin >> grades[i];
	}

	displayArray(grades, numOfGrades);
	selectionSort(grades, numOfGrades);

	cout << "\nThe scores from Highest to lowest are:";
	for (int j = 0; j < numOfGrades; j++)
	{
		cout << " " << grades[j];
	}

	findMAX( grades, numOfGrades);
	findMIN(grades, numOfGrades);
	findAvg(grades, numOfGrades);

	return 0;
}

void displayArray(int gradesArray[], int size)
{
	cout << "\nOriginal Scores are:";
	for (int i = 0; i < size; i++)
	{
		cout << " " << gradesArray[i];
	}
}

void selectionSort(int gradesArray[], int size)
{
	int maxIndex, maxValue;

	for (int i = 0; i < (size - 1); i++)
	{
		maxIndex = i;
		maxValue = gradesArray[i];
		for (int index = i + 1; index < size; index++)
		{
			if (gradesArray[index] > maxValue)
			{
				maxValue = gradesArray[index];
				maxIndex = index;
			}
		}
		swap(gradesArray[maxIndex], gradesArray[i]);
	}

}

int findMAX(int gradesArray[], int size)
{
	int max;
	max = gradesArray[0];
	for (int i = 1; i < size; i++)
	{
		if (gradesArray[i] > max)
			max = gradesArray[i];
	}
	cout << "\nHighest Score: " << max;

	return max;
}

int findMIN(int gradesArray[], int size)
{
	int min;
	min = gradesArray[0];
	for (int i = 1; i < size; i++)
	{
		if (gradesArray[i] < min)
			min = gradesArray[i];
	}

	cout << "\nLowest Score: " << min;
	return min;
}

double findAvg(int gradesArray[], int size)
{
	double gradesTotal = 0, gradesAverage;


	for (int i = 0; i < size; i++)
	{
		gradesTotal += gradesArray[i];
	}

	gradesAverage = gradesTotal / size;
	cout << "\nAverage of scores: " << fixed << showpoint << setprecision(1) << gradesAverage << endl;

	return gradesAverage;

}