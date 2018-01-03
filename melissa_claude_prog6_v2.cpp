/*=====================================================================
Program: Project 6: Happy Prime Numbers
Author: Melissa Claude
Class: Computer Science Honors 1428
Instructor: Ziliang Zong
Date: November 22, 2017
Description: Finding all the happy, prime numbers
Input: none
Output: the number of happy prime numbers
Compilation instructions:
Usage: to find all the happy prime numbers from 1 to 1000000
Modifications: (optimizing)
Date Comment: 12/1/17

Credit:
Projjwal Maiti: https://www.youtube.com/watch?v=l0vQS3gm8nQ
Daniel Sandor and Dalle:
https://stackoverflow.com/questions/33976983/how-to-make-a-program-that-finds-the-number-of-happy-numbers-between-1-and-1-mil

---- ------------------------------------------------
======================================================================*/
#include <iostream>
using namespace std;

bool isPrime(int i); //initialzing functions
bool isHappy(int i);
int happyCounter();
int happy(int i);

int main(){

    cout << "There are " << happyCounter() << " happy prime numbers between 1 and 1 million."; //calls function and displays result
    return 0;
}
bool isPrime(int i){ //determines if function is prime
    int j;
    for(j =2; j*j <= i; j += ((j%2)+1)) {
        if(i % j == 0) {
            return false; //not prime
        }
    }
    if (j *j > i) {
        return true; //prime
    }
}

bool isHappy(int i){ //identifying numbers to send to next function
    switch(i){
        case 1: return true;
        case 4: return false;
        default: return isHappy(happy(i)); //calls other function
    }
}

int happy(int i){ //determines if number is happy by breaking it down
    int j=0;
    while(i!=0){
        j+=(i%10)*(i%10);
        i-=(i%10);
        i/=10;
    }
    return j;
}

int happyCounter(){ //counts number of happy numbers
    int happyElements=0;
    int i;
    #pragma omp parallel for private(i), reduction(+:happyElements) // speed up
    for(i=2; i<=1000000; i++){ //checking from one to one million
        if(isHappy(i)){ //calls happy, if true...
            if(isPrime(i)){ //calls prime, if true...
                ++happyElements; //add one
            }
        }
    }
    return happyElements;
}
