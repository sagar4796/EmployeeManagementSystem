/* 
 CPSC 462 
 Project : Employee Management System
 Group : Graduate Group 3
 Team Members : Sagar Ramani, Nirav Patil, Adit Gandhi, Abhiranjan Singh

*/


#pragma once

#include <memory>   

#include "Domain/Project/ProjectHandler.hpp"
#include "Domain/Salary/SalaryHandler.hpp"

#include "TechnicalServices/Logging/LoggerHandler.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"

#include "UI/UserInterfaceHandler.hpp"




namespace UI
{
   class SimpleUI : public UI::UserInterfaceHandler
  {
    public:
      SimpleUI();


      void launch() override;


      ~SimpleUI() noexcept override;


    private:

      std::unique_ptr<Domain::Project::ProjectHandler>                _allocateProject;

      std::unique_ptr<Domain::Salary::SalaryHandler>                  _paySalary;


      std::unique_ptr<TechnicalServices::Logging::LoggerHandler>            _loggerPtr;
      TechnicalServices::Persistence::PersistenceHandler                  & _persistentData;


      TechnicalServices::Logging::LoggerHandler                            & _logger = *_loggerPtr;
  };
} 
