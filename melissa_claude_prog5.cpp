/*=====================================================================
Program: Project 5: Ticket Sales
Author: Melissa Claude
Class: Computer Science Honors 1428
Instructor: Ziliang Zong
Date: November 2, 2017
Description: A ticket system that allows the user to choose what
            day, floor, and seat number ticket to purchase
Input: Day, Floor, and Seat Number
Output: The approved or denied ticket
Compilation instructions:
Usage: To show the available tickets available so the user
        can choose what ticket to purchase in relation to the
        day, floor level, and seat number
Modifications: (see below)
Date Comment:
11/2/17 - Starting over
11/3/17- displaying totals
11/4/17 - adding comments

---- ------------------------------------------------
======================================================================*/
#include <iostream>
#include <iomanip>
using namespace std;

//arrays
char thurs[3][20];
char fri[3][20];
char sat[3][20];

//functions
char get_menu_choice(char choice);
void cashier(int & day_num, int & floor_num, int & seat_num);
void sell_ticket(int & day_num, int & floor_num, int & seat_num);
void print_chart();
void print_day_list();
void print_section_list();

int main(){
    char choice;
	int day, floor, seat; // formal parameters
	bool menu = true; // displaying menu choice

	for(int i= 0;i<3;i++){      //Thursday's array
        for (int j=0;j<20;j++){
            thurs[i][j] = '-';
        }
    }

    for(int x= 0;x<3;x++){      //Friday's array
        for (int y=0;y<20;y++){
            fri[x][y] = '-';
        }
    }

    for(int a= 0;a<3;a++){      //Saturday's array
        for (int b=0;b<20;b++){
            sat[a][b] = '-';
        }
    }

    cout << "Start to initialize seating chart." <<endl;
    cout << "All seats have been initialized." <<endl;

    while (menu == true){ //keeps displaying menu
        choice = get_menu_choice(choice); //get choice
        switch(choice)
        {
            case 'S':
                cashier(day, floor, seat); // ask for seat
                sell_ticket(day, floor, seat); // checking if seat is available
                break;
            case 'C':
                print_chart(); // shows which seat is available
                break;
            case 'D':
                print_day_list(); // prints totals by day
                break;
            case 'F':
                print_section_list(); // prints totals by section
                break;
            case 'Q':
                cout << "Thank you. Please come again and goodbye." << endl;
                menu = false; // stops displaying menu
                return 0; // exits program
                break;
            default:
                cout << "'" << choice << "' is not a valid choice. Please enter a valid option. " << endl; //asks for choice over again

        }
    }
}

char get_menu_choice(char choice)
{
            cout << endl;
			cout << "      *** Main Menu ***" << endl;
			cout << "S - Sell a Ticket" << endl;
			cout << "C - Display Seating Chart" << endl;
			cout << "D - Display Sales Summary - Day Listing" << endl;
			cout << "F - Display Sales Summary - Floor Listing" << endl;
			cout << "Q - Quit" << endl << endl;
			cout << "Your choice: ";
			cin >> choice;
			choice = toupper(choice); // converts choice to uppercase
			return choice;
}

void cashier(int & day_num, int & floor_num, int & seat_num){     // Asking for seat & validating it
    bool days = true, floors = true, seats = true; // if input is incorrect, it will ask for it again
    char day, floor;

    while (days==true)
    {
        cout << "Enter seat request by day: (T)hursday, (F)riday, or (S)aturday" << endl;
        cin >> day;
        day = toupper(day); // converts to uppercase
        switch(day)
        {
            case 'T':
                day_num = 0; // converting to an integer to distinguish what to do for this set of data
                days = false; // moves onto next input
                break;
            case 'F':
                day_num = 1;
                days = false;
                break;
            case 'S':
                day_num = 2;
                days = false;
                break;
            default:
                cout << "You made the wrong day choice. Try again." <<endl; //ask again if input is invalid
        }
    }
    while (floors == true)
    {
        cout << "Enter the floor section by: (F)loor, (B)alcony, (U)pper Balcony." << endl;
        cin >> floor;
        floor = toupper(floor);
        switch(floor)
        {
            case 'F':
                floor_num = 0; // converts to integer so it can be used as index for arrays
                floors=false; // moves onto next set of data
                break;
            case 'B':
                floor_num = 1;
                floors=false;
                break;
            case 'U':
                floor_num = 2;
                floors=false;
                break;
            default:
                cout << "You made the wrong floor choice. Try again." << endl; //asks again if input is invalid
        }
    }
    while (seats==true)
    {
        cout << "Enter the seat number (1-20)" << endl;
        cin >> seat_num;
        if (seat_num > 0 && seat_num <21)
            seats = false; // finishes asking for parts of the seat
        else
            cout << "Your seat number is incorrect. Please enter an appropriate seat number." << endl; //asks again if input is invalid
    }


    cout << endl << "Seat:" << day << floor << seat_num << endl; // outputs what seat they inputted
    seat_num = seat_num-1; // changes seat number to index used in array
    days = true; //sets variables back to true so it can continuously be used for next set
    floors = true;
    seats = true;

}


void sell_ticket(int & day_num, int & floor_num, int & seat_num){ // checks seat availability
    if (day_num == 0){ //Thursday
        if (thurs[floor_num][seat_num] == '*'){ //checks seat for Thursday
            cout << "This seat is taken. Please select another." << endl;; //seat is taken
        }
        else{
            thurs[floor_num][seat_num]= '*'; //marks seat as sold
            cout << "Congratulations! You got the seat." << endl;
        }
    }
    else if (day_num == 1){ //Friday
        if (fri[floor_num][seat_num] == '*'){ //checks seat for Friday
            cout << "This seat is taken. Please select another." << endl;;
        }
        else{
            fri[floor_num][seat_num] = '*'; //marks as sold
            cout << "Congratulations! You got the seat." << endl;
        }
    }
    else if (day_num == 2){ //Saturday
        if (sat[floor_num][seat_num] == '*'){ //checks seat for Saturday
            cout << "This seat is taken. Please select another." << endl;;
        }
        else{
            sat[floor_num][seat_num] = '*'; // marks as sold
            cout << "Congratulations! You got the seat." << endl;
        }
    }
}

void print_chart(){ //shows seating chart
    cout.setf(ios::showpoint | ios::fixed);
    cout << "Thursday" << endl;
    cout << setw(10) << "Floor" << setw(11) << ":";
    for(int i=0;i<1;i++){
        for(int j=0;j<20;j++){
            cout << " " << thurs[i][j]; //displays floor for Thursday
        }
	}
    cout << endl<< setw(12) << "Balcony" << setw(9) << ":";
    for(int i=1;i<2;i++){
        for(int j=0;j<20;j++){
            cout << " " << thurs[i][j]; //displays balcony for Thursday
		}
	}
    cout << endl<< setw(18) << "Upper Balcony" << setw(3) << ":";
    for(int i=2;i<3;i++){
        for(int j=0;j<20;j++){
            cout << " " << thurs[i][j]; //displays upper balcony for Thursday
		}
	}
	cout << endl << endl;
    cout << "Friday" << endl;
    cout << setw(10) << "Floor" << setw(11) << ":";
    for(int x=0;x<1;x++){
        for(int y=0;y<20;y++){
            cout << " " << fri[x][y]; //displays floor for Friday
		}
	}
        cout << endl<< setw(12) << "Balcony" << setw(9) << ":";
        for(int x=1;x<2;x++){
            for(int y=0;y<20;y++){
                cout << " " << fri[x][y]; //displays balcony for Friday
		}
	}
        cout << endl<< setw(18) << "Upper Balcony" << setw(3) << ":";
        for(int x=2;x<3;x++){
            for(int y=0;y<20;y++){
                cout << " " << fri[x][y]; //displays upper balcony for Friday
		}
	}
	cout << endl << endl;
        cout << "Saturday" << endl;
        cout << setw(10) << "Floor" << setw(11) << ":";
        for(int a=0;a<1;a++){
            for(int b=0;b<20;b++){
                cout << " " << sat[a][b]; //displays floor for Saturday
		}
	}
        cout << endl<< setw(12) << "Balcony" << setw(9) << ":";
        for(int a=1;a<2;a++){
            for(int b=0;b<20;b++){
                cout << " " << sat[a][b]; //displays balcony for Saturday
		}
	}
        cout << endl<< setw(18) << "Upper Balcony" << setw(3) << ":";
        for(int a=2;a<3;a++){
            for(int b=0;b<20;b++){
                cout << " " << sat[a][b]; //displays upper balcony for Saturday
		}
	}
	cout << endl << endl;
}

void print_day_list(){ //displays sales by day
    cout.setf(ios::showpoint | ios::fixed );
    int i, j, tickets;
    int ticket_price = 0; //maintains ticket price total
    int total_tickets = 0; //maintains amount of seats sold

    cout << "Thursday" << endl; //Thursday ONLY
    cout.fill(' ');
    for (i = 0; i < 3; i++){
            tickets = 0; //sets counter back to zero
        for(j = 0; j < 20; j++){
        if (thurs[i][j] == '*'){ //if a seat is sold...
            tickets++;}//...add one ticket
        }
        switch(i){ //distinguishes what to do with ticket sales based on the index of the floor
            case 0:
                cout << setw(14) << "Floor" << setw(23) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
                cout << setw(5) << "$" << (tickets * 30) << endl; // floor
                break;
            case 1:
                cout << setw(16) << "Balcony" << setw(21) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
                cout << setw(5) << "$" << (tickets * 20) << endl; // balcony
                break;
            case 2:
                cout << setw(22) << "Upper Balcony" << setw(15) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
                cout << setw(5) << "$" << (tickets * 10) << endl; //upper balcony
                break;
        }
    }
    cout << "Friday" << endl; // Friday ONLY
    cout.fill(' ');
    for (i = 0; i < 3; i++){
            tickets = 0; //sets counter back to zero
        for(j = 0; j < 20; j++){
        if (fri[i][j] == '*'){ // if seat is taken...
            tickets++;} // ...add one ticket
            }
        switch(i){
            case 0:
                cout << setw(14) << "Floor" << setw(23) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
                cout << setw(5) << "$" << (tickets * 30) << endl; //floor
                break;
            case 1:
                cout << setw(16) << "Balcony" << setw(21) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
                cout << setw(5) << "$" << (tickets * 20) << endl; //balcony
                break;
            case 2:
                cout << setw(22) << "Upper Balcony" << setw(15) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
                cout << setw(5) << "$" << (tickets * 10) << endl; //upper balcony
                break;
        }
    }

    cout << "Saturday" << endl; // Saturday ONLY
    cout.fill(' ');
    for (i = 0; i < 3; i++){
            tickets = 0; //sets counter back to zero
        for(j = 0; j < 20; j++){
        if (sat[i][j] == '*'){ // if seat is taken...
            tickets++;} // ...add one ticket
        }
        switch(i){
            case 0:
                cout << setw(14) << "Floor" << setw(23) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
                cout << setw(5) << "$" << (tickets * 30) << endl; //floor
                break;
            case 1:
                cout << setw(16) << "Balcony" << setw(21) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
                cout << setw(5) << "$" << (tickets * 20) << endl; //balcony
                break;
            case 2:
                cout << setw(22) << "Upper Balcony" << setw(15) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
                cout << setw(5) << "$" << (tickets * 10) << endl; // upper balcony
                break;
        }
    }

    cout << endl;
    for (i = 0; i < 3; i++){ //total sales
        tickets = 0; //resets to zero
        for(j = 0; j < 20; j++){
            if (thurs[i][j] == '*'||fri[i][j] == '*' || sat[i][j] == '*'){ //checks all three arrays
                tickets++; //adds a ticket
                total_tickets++;} //adds all the tickets
        }
        switch(i){
        case 0:
            ticket_price = tickets * 30; //keeps track of total price
            break;
        case 1:
            ticket_price = ticket_price + (tickets *20); //adds additional prices to current total
            break;
        case 2:
            ticket_price = ticket_price + (tickets*10); // adds additional prices to current total
            cout << "Total ticket sales for all shows" << setw(5) << ":" << setw(20) << "Tickets Sold:" << setw(5) << total_tickets;
            cout << setw(5) << "$" << ticket_price << endl;
            ticket_price = 0; //resets ticket price for next loop
            total_tickets = 0; //resets total tickets for next loop
            break;
            }
        }
}

void print_section_list(){ //displays sales by floor
    cout.setf(ios::showpoint | ios::fixed );
    int tickets= 0; // counter for tickets sold
    int total_tickets = 0; // counter for total tickets
    int ticket_price = 0; //counter for total price

    cout << "Floor" << endl;
    cout.fill(' ');
    for (int i = 0; i < 1; i++){ //checks floor for Thursday ONLY
        for(int j = 0; j < 20; j++){
        if (thurs[i][j] == '*'){ // if seat is taken...
            tickets++;} // ...add one ticket
        }
            cout << setw(22) << "Thursday" << setw(15) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
            cout << setw(5) << "$" << (tickets * 30) << endl;
            tickets = 0; //resetting tickets
    }
    for (int x = 0; x < 1; x++){ //checks floor for Friday ONLY
        for(int y = 0; y < 20; y++){
        if (fri[x][y] == '*'){ // if seat is taken...
            tickets++;} //... add one ticket
        }
            cout << setw(20) << "Friday" << setw(17) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
            cout << setw(5) << "$" << (tickets * 30) << endl;
            tickets = 0; //resetting tickets
    }
    for (int a = 0; a < 1; a++){ //checks floor for Saturday ONLY
        for(int b = 0; b < 20; b++){
        if (sat[a][b] == '*'){ // if seat is taken...
            tickets++;} // ...add one ticket
        }
            cout << setw(22) << "Saturday" << setw(15) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
            cout << setw(5) << "$" << (tickets * 30) << endl;
            tickets = 0; //resetting tickets
    }
    cout << "Balcony" << endl;
    for (int i = 1; i < 2; i++){ //checking balcony for Thursday ONLY
        for(int j = 0; j < 20; j++){
        if (thurs[i][j] == '*'){ // if seat is taken...
            tickets++;} // ...add one ticket
        }
            cout << setw(22) << "Thursday" << setw(15) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
            cout << setw(5) << "$" << (tickets * 20) << endl;
            tickets = 0; //resetting tickets
    }
    for (int x = 1; x < 2; x++){ //checking balcony for Friday ONLY
        for(int y = 0; y < 20; y++){
        if (fri[x][y] == '*'){ // if seat is taken...
            tickets++;} // ...add one ticket
        }
            cout << setw(20) << "Friday" << setw(17) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
            cout << setw(5) << "$" << (tickets * 20) << endl;
            tickets = 0; //resetting tickets
    }
    for (int a = 1; a < 2; a++){ //checking balcony for Saturday ONLY
        for(int b = 0; b < 20; b++){
        if (sat[a][b] == '*'){ // if seat is taken...
            tickets++;} // ...add one ticket
        }
            cout << setw(22) << "Saturday" << setw(15) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
            cout << setw(5) << "$" << (tickets * 20) << endl;
            tickets = 0; //resetting tickets
    }
    cout << "Upper Balcony" << endl;
    for (int i = 2; i < 3; i++){ //checking upper balcony for Thursday ONLY
        for(int j = 0; j < 20; j++){
        if (thurs[i][j] == '*'){ // if seat is taken...
            tickets++;} // ...add one ticket
        }
            cout << setw(22) << "Thursday" << setw(15) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
            cout << setw(5) << "$" << (tickets * 10) << endl;
            tickets = 0; //resetting tickets
    }
    for (int x = 2; x < 3; x++){ //checking upper balcony for Friday ONLY
        for(int y = 0; y < 20; y++){
        if (fri[x][y] == '*'){ // if seat is taken...
            tickets++;} // ...add one ticket
        }
            cout << setw(20) << "Friday" << setw(17) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
            cout << setw(5) << "$" << (tickets * 10) << endl;
            tickets = 0; //resetting tickets
    }
    for (int a = 2; a < 3; a++){ // checking upper balcony for Saturday ONLY
        for(int b = 0; b < 20; b++){
        if (sat[a][b] == '*'){ // if seat is taken...
            tickets++;} // ...add one ticket
        }
            cout << setw(22) << "Saturday" << setw(15) << ":" << setw(20) << "Tickets Sold:" << setw(5) << tickets;
            cout << setw(5) << "$" << (tickets * 10) << endl;
            tickets = 0; //resetting tickets
    }
    cout << endl;
    for (int i = 0; i < 3; i++){  //total sales
            tickets = 0;
            for(int j = 0; j < 20; j++){
                if (thurs[i][j] == '*'||fri[i][j] == '*' || sat[i][j] == '*'){ //checks seats for all arrays
                    tickets++; // add a ticket
                    total_tickets++;} // accumulating tickets
            }
            switch(i){
            case 0:
                ticket_price = tickets * 30; // add ticket prices
                break;
            case 1:
                ticket_price = ticket_price + (tickets *20); // add ticket price to current ticket price
                break;
            case 2:
                ticket_price = ticket_price + (tickets*10); //add ticket price to current ticket price
                cout << "Total ticket sales for all shows" << setw(5) << ":" << setw(20) << "Tickets Sold:" << setw(5) << total_tickets;
                cout << setw(5) << "$" << ticket_price << endl;
                ticket_price = 0; // resets both variables for next loop
                total_tickets = 0;
                break;
            }
        }
}
