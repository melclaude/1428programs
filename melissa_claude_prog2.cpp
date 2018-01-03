//Melissa Claude
//Project 2


#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int x, y;

    ifstream fin;
    fin.open ("points.txt");

    // Error Message
    if (!fin){
        cout << "Error opening file.";
        return -1;
    }

    cout << "Reading the file...";
    cout << endl;

    fin >> x >> y;
    fin.close();

    ofstream fout;
    fout.open("points.txt", ios:: app);

    //Error Message
    if (!fout){
        cout << "Error opening file.";
        return -1;
    }

    fout << endl;

    cout << "Writing to the file...";

    if (x > 0 && y > 0)
        fout << "The point (" << x << ", " << y << ") lies in Quadrant 1.";
    else if (x > 0 && y < 0)
        fout << "The point (" << x << ", " << y << ") lies in Quadrant 4.";
    else if (x < 0 && y < 0)
        fout << "The point (" << x << ", " << y << ") lies in Quadrant 3.";
    else if (x < 0 && y > 0)
        fout << "The point (" << x << ", " << y << ") lies in Quadrant 2.";
    else if (x == 0 && y != 0)
        fout << "The point (" << x << ", " << y << ") lies on the Y- axis.";
    else if (y == 0 && x != 0)
        fout << "The point (" << x << ", " << y << ") lies on the X- axis.";
    else
        fout << "The point (" << x << ", " << y << ") lies on the origin";


    fout.close();

    cout << endl;
    cout << "Writing to the file has been completed...";


    return 0;
}
