#pragma once
#include <array>
#include <iostream>
#include <string>

#include "SalaryHandler.hpp";

namespace Domain::Salary
{
  SalaryHandler::SalaryHandler()
  {
    salaryOptions = { "All Employee",
                          "Select Employee"};

  }

  SalaryHandler::~SalaryHandler() noexcept {}


  std::array<std::string, 2> SalaryHandler::get_salary_options()
  {
    return salaryOptions;
  }

}
