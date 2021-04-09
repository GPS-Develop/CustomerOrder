// Name: Gurpreet Singh
// Seneca Student ID: 074913146
// Seneca email: gsingh432@myseneca.ca
// Date of completion: Nov 28/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Utilities.h"
#include "Station.h"

using namespace std;
size_t Station::field_width = 0;
size_t Station::id_generator = 1;

Station::Station(const string& str) {
    m_id = id_generator;

    Utilities utility;
    size_t next_pos = 0;
    bool more = true;

    try {
        m_itemName = utility.extractToken(str, next_pos, more);
        m_serialNumber = stoi(utility.extractToken(str, next_pos, more));
        m_quantity = stoi(utility.extractToken(str, next_pos, more));
        field_width = max(utility.getFieldWidth(), field_width);
        m_description = utility.extractToken(str, next_pos, more);
    }
    catch (string& msg) {
        cout << msg;
    }
    id_generator++;
}

void Station::display(ostream& os, bool full)const
{
    ios init(NULL);
    init.copyfmt(cout);
    os << right;
    os << "[";
    os << setw(3);
    os << setfill('0');
    os << m_id;
    os << "]";
    os << left;

    os << " Item: ";
    os << setw(field_width);
    os << setfill(' ');
    os << m_itemName;
    os << right;

    os << " [";
    os << setw(6);
    os << setfill('0');
    os << m_serialNumber;
    os << "]";
    os << left;

    if (full == false) {
        os << endl;

    }
    else {
        os << " Quantity: ";
        os << setw(field_width);
        os << setfill(' ');
        os << m_quantity;

        os << " Description: ";
        os.copyfmt(init);
        os << m_description;
        os << endl;


    }
}

const string& Station::getItemName() const
{
    return m_itemName;
}
unsigned int Station::getNextSerialNumber()
{
    m_serialNumber++;
    return m_serialNumber - 1;
}
unsigned int Station::getQuantity() const
{
    return m_quantity;
}
void Station::updateQuantity()
{
    m_quantity--;
    if (m_quantity < 0) {
        m_quantity = 0;
    }
}
