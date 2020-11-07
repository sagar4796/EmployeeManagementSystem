/* 
 CPSC 462 
 Project : Employee Management System
 Group : Graduate Group 3
 Team Members : Sagar Ramani, Nirav Patil, Adit Gandhi, Abhiranjan Singh

*/

#pragma once

#include <memory>  
#include <string>
#include <vector>

#include "TechnicalServices/Logging/LoggerHandler.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"




namespace TechnicalServices::Persistence
{
  class SimpleDB : public TechnicalServices::Persistence::PersistenceHandler
  {
    public:
      using PersistenceHandler::PersistenceHandler;   
      SimpleDB();


      std::vector<std::string> findRoles()                                       override;  
      UserCredentials          findCredentialsByName( const std::string & name ) override; 

      const std::string & operator[]( const std::string & key ) const override;


      ~SimpleDB() noexcept override;

    private:
      std::unique_ptr<TechnicalServices::Logging::LoggerHandler> _loggerPtr;

      TechnicalServices::Logging::LoggerHandler & _logger = *_loggerPtr;


      using AdaptationData = std::map<std::string /*Key*/, std::string /*Value*/>;
      AdaptationData _adaptablePairs;

  }; 
}  
