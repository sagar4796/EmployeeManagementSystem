#include "Domain/Session/Session.hpp"

#include <string>
#include <any>
#include <vector>

namespace  // anonymous (private) working area
{
  // 1)  First define all system events (commands, actions, requests, etc.)
  #define STUB(functionName)  std::any functionName( Domain::Session::SessionBase & /*session*/, const std::vector<std::string> & /*args*/ ) \
                              { return {}; }  // Stubbed for now

  STUB( addManager    )
  STUB( removeManager )
  STUB( changeAccountPassword  )
  STUB( applyLoan    )
  STUB( updateProfile )
  STUB( approveLeave     )
  STUB( promoteEmployee  )
  STUB( scheduleMeeting  )




std::any allocateProject( Domain::Session::SessionBase & session, const std::vector<std::string> & args )
  {
    std::string results = "Project \"" + args[0] + "\" is allocated to employee \"" + args[1] + "\" as a role of \""+ args[2]  +"\" by manager \"" + session._credentials.userName + "\" successfully";
    session._logger << "ProjectAllocation:  " + results;
    return results;
  }


  std::any paySalary( Domain::Session::SessionBase & session, const std::vector<std::string> & args )
  {
    int  salary  = std::stoi( args[1] );
    int  bonusSalary = std::stoi( args[2] );
    int         totalSalary  = salary + bonusSalary;
    std::string results     = "Salary \"" + std::to_string( totalSalary ) + "\" is paid to employee \"" + args[0] + "\" by manager \"" + session._credentials.userName + "\" successfully";
    session._logger << "PaySalary:  " + results;
    return results;
  }



  std::any requestLeave( Domain::Session::SessionBase & session, const std::vector<std::string> & args )
  {
    std::string results = "Employee \"" + session._credentials.userName + "\" have made request of " + args[4] + " leave of total \"" + args[2] + "\"  days from start date : (" + args[0] + ") to end date : (" + args[1] + ") because of \"" + args[3] + "\"";
    session._logger << "RequestLeave:  " + results;
    return results;
  }








}    // anonymous (private) working area










namespace Domain::Session
{
  SessionBase::SessionBase( const std::string & description, const UserCredentials & credentials ) : _credentials( credentials ), _name( description )
  {
    _logger << "Session \"" + _name + "\" being used and has been successfully initialized";
  }




  SessionBase::~SessionBase() noexcept
  {
    _logger << "Session \"" + _name + "\" shutdown successfully";
  }




  std::vector<std::string> SessionBase::getCommands()
  {
    std::vector<std::string> availableCommands;
    availableCommands.reserve( _commandDispatch.size() );

    for( const auto & [command, function] : _commandDispatch ) availableCommands.emplace_back( command );

    return availableCommands;
  }




  std::any SessionBase::executeCommand( const std::string & command, const std::vector<std::string> & args )
  {
    std::string parameters;
    for( const auto & arg : args )  parameters += '"' + arg + "\"  ";
    _logger << "Responding to \"" + command + "\" request with parameters: " + parameters;

    auto it = _commandDispatch.find( command );
    if( it == _commandDispatch.end() )
    {
      std::string message = __func__;
      message += " attempt to execute \"" + command + "\" failed, no such command";

      _logger << message;
      throw BadCommand( message );
    }

    auto results = it->second( *this, args);

    if( results.has_value() )
    {
      // The type of result depends on function called.  Let's assume strings for now ...
      _logger << "Responding with: " + std::any_cast<const std::string &>( results );
    }

    return results;
  }








  AdminSession::AdminSession( const UserCredentials & credentials) : SessionBase( "Admin", credentials ){
      _commandDispatch = { {"Add MAnager",            addManager        },
                         {"Remove Manager",   removeManager},
                         {"change account password",   changeAccountPassword  } };
  }

  ManagerSession::ManagerSession( const UserCredentials & credentials) : SessionBase( "Manager", credentials ){
      _commandDispatch = { {"Pay Salary",            paySalary        },
                         {"Allocate Project",   allocateProject},
                         {"Approve Leave", approveLeave    },
                         {"Promote Employee", promoteEmployee    },
                         {"Schedule Meeting", scheduleMeeting    } };
  }


  EmployeeSession::EmployeeSession( const UserCredentials & credentials) : SessionBase( "Employee", credentials ){
      _commandDispatch = { {"Request Leave",            requestLeave        },
                         {"Apply Loan",   applyLoan},
                         {"Update Profile", updateProfile    } };
  }



}    // namespace Domain::Session
