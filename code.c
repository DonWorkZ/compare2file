#include<stdio.h>
#include<stdlib.h>
#define ARRAYSIZE 25

int getSeed();
int getLargest();
void fetchRandomNumbers(int*, int);
int segregateEvenOdd(int*);
void sortArray(int*, int, int);
void displayresults(int*);

int main()
{
    //Local Declarations
    int seed; // value of seed
    int largestVal; // largest value
    int randomNumbers[ARRAYSIZE]; // random numbers array
    int partition; // count of seperation

    // Executable Statements
    seed = getSeed();
    largestVal = getLargest();
    srand(seed);
    fetchRandomNumbers(randomNumbers, largestVal);
    partition = partition = segregateEvenOdd(randomNumbers);
    sortArray(randomNumbers, 0, partition - 1);
    sortArray(randomNumbers, partition, ARRAYSIZE - 1);
    displayresults(randomNumbers);

    return 0;
}

int getSeed()
{
    // Local Declarations
    int seedValue; // temporary storage of seed value

    // Executable Statements 
    printf("Enter seed value -> ");
    scanf("%d", &seedValue);
    while (seedValue < 1)
    {
        printf("\nError! Seed must be a positive value!\n");
        printf("\nEnter seed value -> ");
        scanf("%d", &seedValue);
    }
    return seedValue;
}

int getLargest()
{
    // Local Declarations
    int largestVal; // temporary storage of largest value

    // Executable Statements

    printf("Enter largest value to generate -> ");
    scanf("%d", &largestVal);
    while (largestVal < 2)
    {
        printf("\nError! Largest value to generate must be at least two!\n");
        printf("\nEnter largest value to generate -> ");
        scanf("%d", &largestVal);
    }

    return largestVal;
}

int generateRandom(int upper)
{
    // Local Declarations
    int lower = 1; // lower bound

    return (rand() % (upper - lower + 1)) + lower;
}

void fetchRandomNumbers(int* numbers, int upper)
{
    //Local Declarations
    int i; //loop control variable

     //Executable Statements
    for (i = 0; i < ARRAYSIZE; i++)
    {
        numbers[i] = generateRandom(upper);
    }
}

void swap(int* first, int* second)
{
    //Local Declarations
    int temp = *first; // temporary variable storage

    // Executable Statements
    *first = *second;
    *second = temp;
}

int segregateEvenOdd(int* array)
{
    //Local Declarations
    int flag = array[0] % 2; // odd or even determination
    int count = 0; // count of numbers
    int i; // loop control variable

    //Executable Statements
    for (i = 0; i < ARRAYSIZE; i++)
    {
        if (flag != 0 && array[i] % 2 != 0)
        {
            swap(&array[count], &array[i]);
            count++;
        }
    }
    if (flag == 0 && array[i] % 2 == 0)
    {
        swap(&array[i], &array[count]);
        count++;
    }
    return count;
}

void sortArray(int* array, int start, int end)
  {
     //Local Declarations
     int i; //outer loop control variable
     int j; //inner loop control variable
    
      //Executable Statements
       for (i = start; i <= end; i++)
          {
            for (j = start; j < end; j++)
               {
                 if (array[j] > array[j + 1])
                    {
                          swap(&array[j], &array[j + 1]);
                    }
               }
           }
    }

void displayresults(int* array)
  {
       //Local Declarations
       int i; //loop control variable
    
            //Executable Statements
           printf("\nData set in desired order: ");
        printf("%d ", array[0]);
        for (i = 1; i < ARRAYSIZE; i++)
            {
              if (array[i] != array[i - 1])
                {
                 printf("%d ", array[i]);
                 }
            }
        printf("\n");
      }