/*Restaurant project 
done by : Balen Ahmed
Date :    19 / 6/ 2021
time :    11:31 PM
All rights reserved to Balen Ahmed
*/

#include <iostream>
#include <iomanip>   // setw() function is in iomanip library

using namespace std;

const int K = 100;
struct menuItemType { //intializing a struct data type
    string menuitem;
    int menuprice;
};
// function prototypes
void showMenu();                     //This function shows the different items offered by the restaurant and tells the user how to select the items.
void getData();                      //getData: This function loads the data into the array menuList.
void printCheck(string[] , int[] );  //This function calculates and prints the check. (Note that the billing amount should include a 10 % tax.)


// global variables
menuItemType menuList[K];
int choice[K] , quantity[K], i = 0;
static int chosenquantity[6];
string chosenitem[6];

//main function
int main()
{
    cout << "Welcome to the Kurdistan international restaurant & cafe\n";
    getData();
    showMenu();
    while (true) {
        cout << "Choose your item & (press 0 to stop): ";
        cin >> choice[i];
        if (choice[i] == 0)
            break;
        if (choice[i] > 6 || choice[i] < 0) {     // to limit the range between 1-6
            cout << "invalid input!!" << endl;
            continue;
        }
        chosenitem[choice[i] - 1] = menuList[choice[i]-1].menuitem; // to save the name of similiar chosen products into their specific index
        cout << "Enter quantity: ";
        cin >> quantity[i];
        chosenquantity[choice[i] - 1] += quantity[i];              //// to save the quantity of similiar chosen products into their specific index
        i++;
    }
    printCheck(chosenitem, chosenquantity);     // to print the invoice after exiting the loop
    return 0;
}

// getData function used to save products and their prices accordingly
void getData() {
    menuList[0].menuitem = "Plain egg";
    menuList[0].menuprice = 750;

    menuList[1].menuitem = "Omelet";
    menuList[1].menuprice = 1500;

    menuList[2].menuitem = "cheese";
    menuList[2].menuprice = 1000;

    menuList[3].menuitem = "butter";
    menuList[3].menuprice = 500;

    menuList[4].menuitem = "Fruit basket";
    menuList[4].menuprice = 500;

    menuList[5].menuitem = "Tea";
    menuList[5].menuprice = 250;

}

// to print the menu of products
void showMenu() {
   
   
    for (int i = 0; i <= 5; i++) {
        cout << i + 1 << "- " << menuList[i].menuitem << setw(20 - menuList[i].menuitem.length());  // I used setw() function for space regulating, so that the menu will be printed neatly
        cout << menuList[i].menuprice << " IQD"; // to print the prices accordingly 
        cout << "\n";
    }
    

}

// for printing the invoice
void printCheck(string item[], int qu[]) {
    cout << "\n------Welcome to the Kurdistan international restaurant & Cafe------\n";
    

    // for printing selected items
    cout << "Selected items are: \n";
    for (int s = 0; s < 6  ; s++) {      
        if (qu[s] != 0)              // to only print the items that have quantity greater than 0
        cout << qu[s] << "  " << item[s] << setw(17 - (item[s].length())) << menuList[s].menuprice << " IQD\n";   // again setw used for space regulation 17 is the constant space given
    }
    
    //for calculating the sum, tax ,and total;
    int sum = 0;
    for (int j = 0; j < 6; j++) {               // for loop is used calculating the summation of selected items' money
        sum += (menuList[j].menuprice * qu[j]);
    }
    cout << "\n-------------------------------\n";
    cout << "SUM     " << sum << " IQD"<< endl;
    cout << "Tax     " << (sum * 0.1) << " IQD" << endl;     // tax = 10/100 = 0.1    (sum * tax)
    cout << "Total   " << sum + (sum * 0.1) << " IQD\n";     // total = sum + tax
}
