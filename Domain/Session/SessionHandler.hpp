/* 
 CPSC 462 
 Project : Employee Management System
 Group : Graduate Group 3
 Team Members : Sagar Ramani, Nirav Patil, Adit Gandhi, Abhiranjan Singh

*/


#pragma once

#include <any>
#include <memory>      
#include <stdexcept>   
#include <string>
#include <vector>

#include "TechnicalServices/Persistence/PersistenceHandler.hpp"




namespace Domain::Session
{
  using TechnicalServices::Persistence::UserCredentials;


  class SessionHandler
  {
    public:
      struct SessionException : std::runtime_error {using runtime_error   ::runtime_error;   };
      struct   BadCommand     : SessionException   {using SessionException::SessionException;};

      static std::unique_ptr<SessionHandler> createSession( const UserCredentials & credentials );


      virtual std::vector<std::string> getCommands   ()                                                                     = 0; // retrieves the list of actions (commands)
      virtual std::any                 executeCommand( const std::string & command, const std::vector<std::string> & args ) = 0; // Throws BadCommand

    
      virtual ~SessionHandler() noexcept = 0;


    protected:
      SessionHandler & operator=( const SessionHandler &  rhs ) = default;  // copy assignment
      SessionHandler & operator=(       SessionHandler && rhs ) = default;  // move assignment

  };    
} 
