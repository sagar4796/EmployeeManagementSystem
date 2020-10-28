#include "UI/SystemDriverUI.hpp"

#include "Domain/Session/SessionHandler.hpp"

#include "TechnicalServices/Logging/LoggerHandler.hpp"




namespace UI
{
  // Default constructor
  SystemDriverUI::SystemDriverUI()
  : _loggerPtr( TechnicalServices::Logging::LoggerHandler::create() )
  {
    _logger << "Contracted UI being used and has been successfully initialized";
  }




  // Destructor
  SystemDriverUI::~SystemDriverUI() noexcept
  {
    _logger << "Contracted UI shutdown successfully";
  }




  // Operations
  void SystemDriverUI::launch()
  {
    {
      _logger << "Starting scenario 1: Allocate Project";

      auto allocateProjectSession  = Domain::Session::SessionHandler::createSession( {"Tom", "Tom@123321", {"Manager"}} );
      auto allocateProjectCommands               = allocateProjectSession->getCommands();
      auto allocateProjectResults                 = allocateProjectSession->executeCommand( "Allocate Project", { "Apple", "888194735", "Leader" } );
      //session->singOff();

      _logger << "Completed scenario 1";


      _logger << "Starting scenario 2: Pay Salary";

      auto paySalarySession  = Domain::Session::SessionHandler::createSession( { "Tom", "Tom@123321", { "Manager" } } );
      auto paySalaryCommands         = paySalarySession->getCommands();
      auto paySalaryResults  = paySalarySession->executeCommand( "Pay Salary", { "888194735", "8000", "2000" } );
      //session->singOff();

      _logger << "Completed scenario 2";


      _logger << "Starting scenario 3: Request Leave";

      auto requestLeaveSession  = Domain::Session::SessionHandler::createSession( { "Tommen", "Tommen@321123", { "Employee" } } );
      auto requestLeaveCommands = requestLeaveSession->getCommands();
      auto requestLeaveResults  = requestLeaveSession->executeCommand( "Request Leave", { "10/29/2020", "10/31/2020", "3", "Eye Operation", "Paid"} );
      //session->singOff();

      _logger << "Completed scenario 2";
    }
  }
}    // namespace UI
