// Name: Gurpreet Singh
// Seneca Student ID: 074913146
// Seneca email: gsingh432@myseneca.ca
// Date of completion: Nov 28/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <iostream>
#include <deque>
#include <string>
#include "Station.h"
#include "CustomerOrder.h"
class Workstation : public Station
{
public:
    Workstation(std::string &);
    Workstation(Workstation&) = delete;
    Workstation& operator=(Workstation&) = delete;
    Workstation(Workstation&&) = delete;
    Workstation& operator=(Workstation&&) = delete;
    
    void runProcess(std::ostream &);
    bool moveOrder();
    bool getIfCompleted(CustomerOrder&);
    void setNextStation(Workstation&);
    const Workstation* getNextStation() const;
    void display(std::ostream&) const;
    Workstation &operator+=(CustomerOrder &&);
private:
    std::deque<CustomerOrder> m_orders;
    Workstation *m_pNextStation;

};

#endif
