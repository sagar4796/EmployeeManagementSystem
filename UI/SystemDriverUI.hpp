/* 
 CPSC 462 
 Project : Employee Management System
 Group : Graduate Group 3
 Team Members : Sagar Ramani, Nirav Patil, Adit Gandhi, Abhiranjan Singh

*/


#pragma once

#include <memory>   

#include "TechnicalServices/Logging/LoggerHandler.hpp"

#include "UI/UserInterfaceHandler.hpp"




namespace UI
{
  class SystemDriverUI : public UI::UserInterfaceHandler
  {
  public:
    
    SystemDriverUI();


    void launch() override;


    ~SystemDriverUI() noexcept override;


  private:
    std::unique_ptr<TechnicalServices::Logging::LoggerHandler> _loggerPtr;

    TechnicalServices::Logging::LoggerHandler & _logger = *_loggerPtr;
  };
}  
