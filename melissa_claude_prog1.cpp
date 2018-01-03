#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    float sideA, sideB, hypotenuse;

    //Get side A
    cout << "Input the length of side A, please: " <<endl;
    cin >> sideA;

    //Get side B
    cout << "Input the length of side B, please: " << endl;
    cin >> sideB;

    //Calculate the hypotenuse
    hypotenuse = sqrt(pow(sideA, 2) + pow(sideB, 2));
    cout << "The length of the hypotenuse is " << hypotenuse << "."<<endl;
    cout << "" << endl; // I'm just making the code separated.
    cout << "" << endl; // Again, I'm separating the code.

    //Reset the values
    sideA=0;
    sideB=0;
    hypotenuse=0;

    //Get the hypotenuse
    cout << "Input the length of the hypotenuse, please: " <<endl;
    cin >> hypotenuse;

    //Get side A
    cout << "Input the length of side A, please: " <<endl;
    cin >> sideA;

    //Calculate side B
    sideB = sqrt(pow(hypotenuse, 2) - pow(sideA, 2));
    cout << "The length of Side B is " << sideB << ".";

    //Exit gracefully
    return 0;

}
