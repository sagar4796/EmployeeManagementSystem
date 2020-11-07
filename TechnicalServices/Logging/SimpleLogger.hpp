/* 
 CPSC 462 
 Project : Employee Management System
 Group : Graduate Group 3
 Team Members : Sagar Ramani, Nirav Patil, Adit Gandhi, Abhiranjan Singh

*/


#pragma once

#include <iostream>
#include <chrono>
#include <iomanip>

#include "TechnicalServices/Logging/LoggerHandler.hpp"


namespace TechnicalServices::Logging
{
  class SimpleLogger : public TechnicalServices::Logging::LoggerHandler
  {
    public:
      
      SimpleLogger( std::ostream & loggingStream = std::clog);

      
      SimpleLogger & operator<< ( const std::string & message ) override;

      
      ~SimpleLogger() noexcept override;

    
    protected:
      std::ostream & _loggingStream;
  }; 






  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline SimpleLogger::SimpleLogger( std::ostream & loggingStream )
    : _loggingStream( loggingStream )
  {
    _loggingStream << std::unitbuf;

    *this << "Simple Logger being used and has been successfully initialized";
  }


  inline SimpleLogger::~SimpleLogger() noexcept
  {
    *this << "Simple Logger shutdown successfully";
  }



  inline SimpleLogger & SimpleLogger::operator<< ( const std::string & message )
  {
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    _loggingStream << std::put_time( std::localtime( &now ), "%Y-%m-%d %X" ) << " | ";
    _loggingStream << message << '\n';

    return *this;
  }

} 
