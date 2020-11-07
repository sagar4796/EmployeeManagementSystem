/* 
 CPSC 462 
 Project : Employee Management System
 Group : Graduate Group 3
 Team Members : Sagar Ramani, Nirav Patil, Adit Gandhi, Abhiranjan Singh

*/

#pragma once

#include <memory>       
#include <stdexcept>  




namespace UI
{
  
  class UserInterfaceHandler
  {
    public:
      
      struct UIException    : std::runtime_error {using runtime_error::runtime_error;};
      struct   BadUIRequest : UIException        {using UIException  ::UIException;  };


      static std::unique_ptr<UserInterfaceHandler> createUI();                                 // must be static


      virtual void launch() = 0;                                                               // must be virtual and pure


      virtual ~UserInterfaceHandler() noexcept = 0;                                            // must be virtual, best practice to be pure

    protected:
      UserInterfaceHandler & operator=( const UserInterfaceHandler  & ) = default;             // copy assignment
      UserInterfaceHandler & operator=(       UserInterfaceHandler && ) = default;             // move assignment
  };
} 
