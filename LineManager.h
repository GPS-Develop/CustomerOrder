// Name: Gurpreet Singh
// Seneca Student ID: 074913146
// Seneca email: gsingh432@myseneca.ca
// Date of completion: Nov 28/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <iostream>
#include <vector>
#include "Workstation.h"

class LineManager
{
public:
    LineManager(std::string, std::vector<Workstation*>&, std::vector<CustomerOrder> &);
    bool run(std::ostream&);
    void displayCompletedOrders(std::ostream&) const;
    void displayStations() const;
    void displayStationsSorted() const;
private:
    std::vector<Workstation*> AssemblyLine;
    std::deque<CustomerOrder> ToBeFilled;
    std::deque<CustomerOrder> Completed;
    unsigned int m_cntCustomerOrder;
    Workstation* m_firstStation = nullptr;

};
#endif
