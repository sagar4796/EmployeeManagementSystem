#pragma once

namespace Domain::Salary
{
  // Library Package within the Domain Layer Abstract class
  class PaySalaryHandler
  {
    public:
      // Operations
      //   Work in progress ...


      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
      virtual ~PaySalaryHandler() noexcept = 0;

    protected:
      // Copy assignment operators, protected to prevent mix derived-type assignments
      PaySalaryHandler & operator=( const PaySalaryHandler &  rhs ) = default;  // copy assignment
      PaySalaryHandler & operator=(       PaySalaryHandler && rhs ) = default;  // move assignment

  };    // class MaintainBooksHandler





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline PaySalaryHandler::~PaySalaryHandler() noexcept = default;


} // namespace Domain::Library
