/* 
 CPSC 462 
 Project : Employee Management System
 Group : Graduate Group 3
 Team Members : Sagar Ramani, Nirav Patil, Adit Gandhi, Abhiranjan Singh

*/


#pragma once
#include <array>
#include <iostream>
#include <string>

namespace Domain::Salary
{
  class SalaryHandler
  {
  protected:
    std::array<std::string, 2> salaryOptions;


  public:
    SalaryHandler();
    SalaryHandler( const SalaryHandler & original ) = default;    //Copy const
    SalaryHandler( SalaryHandler && original )      = default;    //Move Constructor can be removed later
    ~SalaryHandler() noexcept;




    std::array<std::string, 2> get_salary_options();
  };
}
