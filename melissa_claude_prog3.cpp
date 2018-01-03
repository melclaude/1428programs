/*=====================================================================
Program: Project 3: The Water Tower
Author: Melissa Claude
Class: Computer Science Honors 1428
Instructor: Ziliang Zong
Date: September 22, 2017
Description: This is a program that asks the user to input a number between a range to determine the
            volume of a water tower
Input: The height of the water tower
Output: The volume of water in the water tower
Compilation instructions:
Usage: To figure out the amount of water in water tower
Modifications: 9/27/2017
Date Comment: adding comments
---- ------------------------------------------------
======================================================================*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double radius1, height, volume, newheight; //declaring other variables
    const double PI = 3.1415926; //declaring pi

    // getting height of water tower
    cout << "Enter the height of the water tower:" << endl;
    cin >> height;

    // incorrect range
    if (height <= 0 || height > 50)
    {
        cout << "Incorrect height - range: 0-50." << endl;
        cout << "Enter the height of the water tower, again:" << endl;
        cin >> height;
        // incorrect range again
        if (height <= 0 || height > 50)
        {
            cout << "You are not paying attention. Please read the manual." << endl;
            cout << "Program exiting.";
            return -1; //exit

        }
    }
    //figuring out what calculations to compute based on height
    if (height > 0 && height <= 20)
        {
            volume = PI * pow(15, 2) * height;
            cout << "With a height of " << height << ", the water volume is " << volume << " cubic feet." << endl;
        }
    else if (height > 20 && height <= 30)
            if (height != 30)
                {
                    newheight = height - 20; // leftover height
                    radius1 = 15-newheight; //finding proportional radius
                    volume = (PI * pow(15, 2) * 20); //first 20 feet of water tower
                    volume = volume + ((PI * (pow(radius1,2) + pow(25,2) + (radius1*25)) * newheight) / 3); //remaining height calculations
                    cout << "With a height of " << height << ", the water volume is " << volume << " cubic feet." << endl;
                }
            else
                { //exact height
                    volume = PI * pow(15, 2) * 20; //first 20 feet of water tower
                    volume = volume + (PI * (pow(15,2) + pow(25,2) + (15*25)) * 10) / 3; //next 10 feet of water tower
                    cout << "With a height of " << height << ", the water volume is " << volume << " cubic feet." << endl;
                }
    else if (height > 30 && height <= 40)
            if (height != 40)
                {
                    newheight = height-30; //newheight
                    volume = (PI * pow(15, 2) * 20); //first 20 feet of water tower
                    volume = volume + (PI * (pow(15,2) + pow(25,2) + (15*25)) * 10) / 3; //next 10 feet of water tower
                    volume = volume + (PI * pow(25, 2) * newheight); //remaining height calculations
                    cout << "With a height of " << height << ", the water volume is " << volume << " cubic feet." << endl;
                }
            else
                {//exact height
                    volume = PI * pow(15, 2) * 20; //first 20 feet of water tower
                    volume = volume + (PI * (pow(15,2) + pow(25,2) + (15*25)) * 10) / 3; //next 10 feet of water tower
                    volume = volume + PI * pow(25, 2) * 10; //next 10 feet of water tower
                    cout << "With a height of " << height << ", the water volume is " << volume << " cubic feet." << endl;
                }
    else
            if(height != 50)
                {
                    newheight = height-40; // leftover height
                    radius1 = 25-newheight;
                    volume = PI * pow(15, 2) * 20; //first 20 feet of water tower
                    volume = volume + (PI * (pow(15,2) + pow(25,2) + (15*25)) * 10) / 3; //next 10 feet of water tower
                    volume = volume + PI * pow(25, 2) * 10; //next 10 feet of water tower
                    volume = volume + (PI * (pow(radius1,2) + pow(25,2) + (radius1*25)) * newheight) / 3; //remaining height calculations
                    cout << "With a height of " << height << ", the water volume is " << volume << " cubic feet." << endl;
                }
            else
                {//exact height
                    volume = PI * pow(15, 2) * 20; //first 20 feet of water tower
                    volume = volume + (PI * (pow(15,2) + pow(25,2) + (15*25)) * 10) / 3; //next 10 feet of water tower
                    volume = volume + (PI * pow(25, 2) * 10); //next 10 feet of water tower
                    volume = volume + (PI * (pow(15,2) + pow(25,2) + (15*25)) * 10) / 3; //next 10 feet of water tower
                    cout << "With a height of " << height << ", the water volume is " << volume << " cubic feet." << endl;
                }


    //exit
    return 0;

}
