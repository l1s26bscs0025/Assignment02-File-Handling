/*
  * Name       : HASEEB AHMED 
  * Reg No     : L1S26BSCS0025
  * Assignment : 02 - File Handling
  * Question   : Q1 - Stock Debug
*/


#include <iostream>
using namespace std;
// FIX 1: <fstream> was missing, so ifstream and ofstream were unknown.
#include <fstream>

int main() {
    ifstream inFile("stock.txt");
    // Fix 2: condition was reversed 
    if (!inFile)
    {
        cout << "stock.txt not found!" << endl;
        return 1;
    }
    //fix 3 ios::app
    ofstream reorder("reorder.txt",ios::app);

    char code[10];
    int qty, count = 0, low = 0;
    
    double price=0;
    // FIX 4: double is needed to preserve decimal values in the total.
    double total = 0;
    // FIX 5: The first line contains headings, so skip it before reading items.
    inFile.ignore(1000, '\n');

    while (count < 50 && inFile >> code >> qty >> price) {
        count++;
        total = total + qty * price;
        if (qty < 10) {
            // FIX 6: endl puts each low-stock item on a separate line.
            reorder << code << " " << qty<<endl;
            low++;
        }
    }
    inFile.close();
    reorder.close();

    cout << "Items: " << count << endl;
    cout << "Total stock value: " << total << endl;
    cout << "Low stock items: " << low << endl;
    return 0;
}