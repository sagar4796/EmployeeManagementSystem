/* 
 CPSC 462 
 Project : Employee Management System
 Group : Graduate Group 3
 Team Members : Sagar Ramani, Nirav Patil, Adit Gandhi, Abhiranjan Singh

*/

#pragma once
#include <stdexcept> 
#include <iostream>
#include <iostream>
#include <memory>     
#include <string>


namespace TechnicalServices::Logging
{
  class LoggerHandler
  {
    public:
      struct LoggerException    : std::runtime_error {using runtime_error  ::runtime_error;};
      struct   BadLoggerRequest : LoggerException    {using LoggerException::LoggerException;     };

      static std::unique_ptr<LoggerHandler> create( std::ostream & loggingStream = std::clog );    // must be static


      virtual LoggerHandler & operator<< ( const std::string & message ) = 0;


      virtual ~LoggerHandler() noexcept = 0;


    protected:
      LoggerHandler & operator=( const LoggerHandler  & rhs ) = delete;    // copy assignment
      LoggerHandler & operator=(       LoggerHandler && rhs ) = delete;    // move assignment
  };





  /*****************************************************************************
  ** Inline default implementations
  ******************************************************************************/
  inline LoggerHandler::~LoggerHandler() noexcept = default;
}
