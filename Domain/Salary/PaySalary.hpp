#pragma once

#include "Domain/Salary/PaySalaryHandler.hpp"

namespace Domain::Salary
{
  class PaySalary : public Domain::Salary::PaySalaryHandler
  {
    public:
      // Constructors
      using PaySalaryHandler::PaySalaryHandler;  // inherit constructors

      // Operations

     ~PaySalary() noexcept override;
  }; // class Books


  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline PaySalary::~PaySalary() noexcept
  {}


}  // namespace Domain::Library
