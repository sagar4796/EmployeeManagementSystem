#include "UI/SimpleUI.hpp"

#include <any>         // any_cast()
#include <iomanip>     // setw()
#include <iostream>    // streamsize
#include <limits>      // numeric_limits
#include <memory>      // unique_ptr, make_unique<>()
#include <string>      // string, getline()
#include <vector>

#include "Domain/Project/ProjectHandler.hpp"    // Include for now - will replace next increment
#include "Domain/Session/SessionHandler.hpp"
#include "Domain/Salary/SalaryHandler.hpp"

#include "TechnicalServices/Logging/LoggerHandler.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"




namespace UI
{
  // Default constructor
  SimpleUI::SimpleUI()
    : _allocateProject( std::make_unique<Domain::Project::ProjectHandler>() ),    // will replace these with factory calls in the next increment
      _paySalary( std::make_unique<Domain::Salary::SalaryHandler>() ),
      _loggerPtr     ( TechnicalServices::Logging::LoggerHandler::create()            ),
    _persistentData( TechnicalServices::Persistence::PersistenceHandler::instance() )
  {
    _logger << "Simple UI being used and has been successfully initialized";
  }




  // Destructor
  SimpleUI::~SimpleUI() noexcept
  {
    _logger << "Simple UI shutdown successfully";
  }




  // Operations
  void SimpleUI::launch()
  {
    // 1) Fetch Role legal value list
    std::vector<std::string> roleLegalValues = _persistentData.findRoles();


    // 2) Present login screen to user and get username, password, and valid role
    Domain::Session::UserCredentials credentials  = {"", "", {""}};           // ensures roles[0] exists
    auto &                           selectedRole = credentials.roles[0];     // convenience alias

    std::unique_ptr<Domain::Session::SessionHandler> sessionControl;

    do
    {
      std::cin.ignore(  std::numeric_limits<std::streamsize>::max(), '\n' );

      std::cout << "  Username: ";
      std::getline( std::cin, credentials.userName );

      std::cout << "  Password: ";
      std::getline( std::cin, credentials.password );

      unsigned menuSelection;
      do
      {
        for( unsigned i = 0; i != roleLegalValues.size(); ++i )   std::cout << std::setw( 2 ) << i << " - " << roleLegalValues[i] << '\n';
        std::cout << "  Select Role: ";
        std::cin  >> menuSelection;
      } while( menuSelection >= roleLegalValues.size() );

      selectedRole = roleLegalValues[menuSelection];


      // 3) Validate user is authorized for this role, and if so create session
      sessionControl = Domain::Session::SessionHandler::createSession( credentials );
      if( sessionControl != nullptr )
      {
        _logger << "Login Successful for \"" + credentials.userName + "\" as role \"" + selectedRole + "\"";
        break;
      }

      std::cout << "** Login failed\n";
      _logger << "Login failure for \"" + credentials.userName + "\" as role \"" + selectedRole + "\"";

    } while( true );


    // 4) Fetch functionality options for this role
    do
    {
      auto        commands = sessionControl->getCommands();
      std::string selectedCommand;
      unsigned    menuSelection;

      do
      {
        for( unsigned i = 0; i != commands.size(); ++i ) std::cout << std::setw( 2 ) << i << " - " << commands[i] << '\n';
        std::cout << std::setw( 2 ) << commands.size() << " - " << "Quit\n";

        std::cout << " Select Action you want to perform: ";
        std::cin >> menuSelection;
      } while( menuSelection > commands.size() );

      if( menuSelection == commands.size() ) break;

      selectedCommand = commands[menuSelection];
      _logger << "Command selected \"" + selectedCommand + '"';


      /******************************************************************************************************************************
      **  5) The user interface will collect relevant information to execute the chosen command.  This section requires the UI to
      **     know what information to collect, and hence what the available commands are.  Our goal is loose (minimal) coupling, not
      **     no coupling. This can be achieved in a variety of ways, but one common way is to pass strings instead of strong typed
      **     parameters.
      ******************************************************************************************************************************/
      if( selectedCommand == "Allocate Project" )
      {
        std::array<std::string, 4> projects = _allocateProject->get_projects();
        unsigned                   projectSelection;
        do
        {
          for( unsigned i = 0; i != projects.size(); ++i ) std::cout << std::setw( 2 ) << i << " - " << projects[i] << '\n';
          std::cout << "Select Project: ";
          std::cin >> projectSelection;

        } while( projectSelection > projects.size() );
            std::string selectedProject = projects[projectSelection];
        _logger << "Selected Project \"" + selectedProject + '"';



        std::array<std::string, 4> employees = _allocateProject->get_employee();
        unsigned                   employeeSelection;
        do
        {
          for( unsigned i = 0; i != employees.size(); ++i ) std::cout << std::setw( 2 ) << i << " - " << employees[i] << '\n';
          std::cout << "Select Employee: ";
          std::cin >> employeeSelection;

        } while( employeeSelection > employees.size() );
         std::string selectedEmployee = employees[employeeSelection];
        _logger << "Selected Employee \"" + selectedEmployee + '"';



        std::array<std::string, 4> projectRoles = _allocateProject->get_project_role();
        unsigned                   projectRoleSelection;
        do
        {
          for( unsigned i = 0; i != projectRoles.size(); ++i ) std::cout << std::setw( 2 ) << i << " - " << projectRoles[i] << '\n';
          std::cout << "Select Project Role: ";
          std::cin >> projectRoleSelection;

        } while( employeeSelection > projectRoles.size() );
          std::string selectedProjectRole = projectRoles[projectRoleSelection];
        _logger << "Selected Project Role: " + selectedProjectRole + '"';


        std::vector<std::string> parameters( 3 );
        parameters[0] = selectedProject;
        parameters[1] = selectedEmployee;
        parameters[2] = selectedProjectRole;

        auto results = sessionControl->executeCommand( selectedCommand, parameters );
        if( results.has_value() ) _logger << "Received reply: " + std::any_cast<const std::string &>( results );
      }

      else if (selectedCommand == "Pay Salary")
      {


        std::array<std::string, 2> salaryOptions = _paySalary->get_salary_options();
        unsigned                   salaryOptionSelection;
        do
        {
          for( unsigned i = 0; i != salaryOptions.size(); ++i ) std::cout << std::setw( 2 ) << i << " - " << salaryOptions[i] << '\n';
          std::cout << "Select Pay Salary Option: ";
          std::cin >> salaryOptionSelection;
        } while( salaryOptionSelection > salaryOptions.size() );
        std::string selectedSalaryOption = salaryOptions[salaryOptionSelection];
        _logger << "Selected Option  \"" + selectedSalaryOption + '"'; 


        std::array<std::string, 4> employees = _allocateProject->get_employee();
        unsigned                   employeeSelection;
        do
        {
          for( unsigned i = 0; i != employees.size(); ++i ) std::cout << std::setw( 2 ) << i << " - " << employees[i] << '\n';
          std::cout << "Select Employee: ";
          std::cin >> employeeSelection;

        } while( employeeSelection > employees.size() );
            std::string selectedEmployee = employees[employeeSelection];
        _logger << "Selected Employee \"" + selectedEmployee + '"'; 


        std::vector<std::string> parameters( 3 );
        parameters[0] = selectedEmployee;

        std::cout << " Enter Salary: ";
        std::cin >> std::ws;
        std::getline( std::cin, parameters[1] );
        std::cout << " Enter Bonus Salary:   ";
        std::cin >> std::ws;
        std::getline( std::cin, parameters[2] );

        auto results = sessionControl->executeCommand( selectedCommand, parameters );
        if( results.has_value() ) _logger << "Received reply: " + std::any_cast<const std::string &>( results );

      }


      else if( selectedCommand == "Request Leave" )
      {
        std::vector<std::string> parameters( 5 );

        std::cout << " Enter Start Date (MM/DD/YYYY) :  ";
        std::cin >> std::ws;
        std::getline( std::cin, parameters[0] );
        std::cout << " Enter Last Date (MM/DD/YYYY) : ";
        std::cin >> std::ws;
        std::getline( std::cin, parameters[1] );
        std::cout << " Enter Total Days:   ";
        std::cin >> std::ws;
        std::getline( std::cin, parameters[2] );
        std::cout << " Enter Reason for Leave:   ";
        std::cin >> std::ws;
        std::getline( std::cin, parameters[3] );
        std::cout << " Enter Leave Type (Paid or Unpaid):   ";
        std::cin >> std::ws;
        std::getline( std::cin, parameters[4] );



        auto results = sessionControl->executeCommand( selectedCommand, parameters );
        if( results.has_value() ) _logger << "Received reply: " + std::any_cast<const std::string &>( results );
      }

      else if( selectedCommand == "Another command" ) /* ... */ {}

      else sessionControl->executeCommand( selectedCommand, {} );
    } while( true );

    _logger << "Ending session and terminating";
  }
}
