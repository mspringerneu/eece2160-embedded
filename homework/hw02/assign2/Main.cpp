#include <iostream>
#include <string>

#include "Bed.h"
#include "Table.h"

using namespace std;

int main() {
	cout << "Creating table..." << endl;
	string tbl_name, wd_type;
	cout << "\t" << "Enter name: ";
	cin >> tbl_name;
	cout << "\t" << "Enter wood type (Pine, Oak): ";
	cin >> wd_type;
	Table new_table = Table(tbl_name, wd_type);
	
	cout << "Creating bed..." << endl;
	string bed_name, bed_size;
	cout << "\t" << "Enter name: ";
	cin >> bed_name;
	cout << "\t" << "Enter size (Twin, Full, Queen, King): ";
	cin >> bed_size;
	Bed new_bed = Bed(bed_name, bed_size);
	
	cout << endl << "Printing objects ..." << endl << endl;
	
	new_table.print();
	new_bed.print();
}
