#include <stdio.h>

//Lab assignment 6 - returns index of value in array numbers, between indices low and high
//Assumes all values entered are valid (ie; the array will not go out of bounds)
//No consistent behavior if value exists multiple times in range
int search(int numbers[], int low, int high, int value) 
{
	int index = -1; //return variable
	int guess = (low+high)/2; //guessed index (halfway between low and high, rounding down)

	if (low == high && numbers[low] != value) //base case when value does not exist
		index = -1;
	else if (numbers[guess] == value) //base case when value is found
		index = guess;
	else if (numbers[guess] > value) //recursive case when guess is greater than the target value
		index = search(numbers, low, guess - 1, value);
	else if (numbers[guess] < value) //recursive case when guess is less than the target value
		index = search(numbers, guess + 1, high, value);
	else //case for unknown error
		index = -1;
	
	return index;
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}