#pragma once

#include <any>
#include <memory>
#include <string>
#include <vector>

#include "Domain/Session/SessionHandler.hpp"
#include "TechnicalServices/Logging/LoggerHandler.hpp"


namespace Domain::Session
{
  class SessionBase : public SessionHandler
  {
    public:
      SessionBase( const std::string & description,  const UserCredentials & credentials );

      std::vector<std::string> getCommands   ()                                                                     override;    // retrieves the list of actions (commands)
      std::any                 executeCommand( const std::string & command, const std::vector<std::string> & args ) override;    // executes one of the actions retrieved


      ~SessionBase() noexcept override = 0;

  protected: 
  public:  
    using DispatchTable = std::map<std::string, std::any (*)( Domain::Session::SessionBase &, const std::vector<std::string> & )>;
    friend class Policy;

    std::unique_ptr<TechnicalServices::Logging::LoggerHandler> _loggerPtr = TechnicalServices::Logging::LoggerHandler::create();
    TechnicalServices::Logging::LoggerHandler &                _logger    = *_loggerPtr;

    UserCredentials const                                      _credentials;
    std::string     const                                      _name      = "Undefined";
    DispatchTable                                              _commandDispatch;
  };    


  struct AdminSession        : SessionBase{ AdminSession       ( const UserCredentials & credentials ); };
  struct ManagerSession      : SessionBase{ ManagerSession     ( const UserCredentials & credentials ); };
  struct EmployeeSession     : SessionBase{ EmployeeSession    ( const UserCredentials & credentials ); };

} 
