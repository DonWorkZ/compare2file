#include<stdio.h>

#include<stdlib.h>



int getSeed();

int getLargest();

void fetchRandomNumbers(int *,int,int);

void printArray(int *,int); // to print arrays to test or debug 

int segregateEvenOdd(int *,int );

void sortArray(int *,int,int);

void displayresults(int *,int size);



int main()

{

    //Local Declarations

    int seed; // value of seed

    int largestVal; // largest value 

    int size = 25;



    // accepting inputs

    seed = getSeed();

    largestVal = getLargest();



    // Executive Statements

    //seeding random values

    srand(seed);

    

    // random numbers array

    int randomNumbers[size];

    // populating random numbers arrays with data

    fetchRandomNumbers(randomNumbers,size,largestVal);

    

    // segregating evens and odds

    int partition = segregateEvenOdd(randomNumbers,size);

    

    

    //now we got the arrays partitioned odd/even from [0,p-1] and even/odd from [p,size-1]

    // sorting first half of the array

    sortArray(randomNumbers,0,partition-1);

    // sorting second half of the array

    sortArray(randomNumbers,partition,size-1);

    

    

    // printing dataset in desired order;

    displayresults(randomNumbers,size);

}



int getSeed()

{

    //Local Declarations

    int seedValue; // temporary storage of seed value



    //Excutable Statements

    printf("Enter seed value -> ");

    scanf("%d", &seedValue);



    // Loop until valid input is not given

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



    // Loop until 

    while (largestVal < 2)

    {

        printf("\nError! Largest value to generate must be at least two!\n");

        printf("\nEnter largest value to generate -> ");

        scanf("%d", &largestVal);

    }

    return largestVal;

}



void printArray(int *array,int size){

    for(int i=0;i<size;i++){

        printf("%d ",array[i]);

    }

    printf("\n");

}



int generateRandom(int upper){

    int lower = 1;

    return (rand() % (upper - lower + 1)) + lower;

}





void fetchRandomNumbers(int *numbers,int size,int upper){

    for(int i=0;i<size;i++){

        numbers[i] = generateRandom(upper);

    }

}



void swap(int *first,int *second){

    int temp = *first;

    *first = *second;

    *second = temp;

}



int segregateEvenOdd(int *array,int size){

    // flag decides which among even and odd will come first

    int flag = array[0]%2;

    int count = 0;

    for(int i=0;i<size;i++){

        if (( flag!=0 && array[i]%2!=0) ||( flag==0 && array[i]%2!=0) ){

            swap(&array[count],&array[i]);

            count++;

        }

    }

    return count;

}



void sortArray(int *array,int start,int end){

    for(int i=start;i<=end;i++){

        for(int j=start;j<end;j++){

            if(array[j]>array[j+1]){

                swap(&array[j],&array[j+1]);

            }

        }

    }

}



void displayresults(int *array,int size)

{

    printf("Data set in desired order: ");

    printf("%d ",array[0]);

    for(int i=1;i<size;i++){

        if(array[i]!=array[i-1]){

            printf("%d ",array[i]);

        }

    }

}