/* 
 CPSC 462 
 Project : Employee Management System
 Group : Graduate Group 3
 Team Members : Sagar Ramani, Nirav Patil, Adit Gandhi, Abhiranjan Singh

*/


#pragma once

#include <map>
#include <stdexcept>   
#include <string>
#include <vector>




namespace TechnicalServices::Persistence
{
  struct UserCredentials
  {
    std::string               userName;
    std::string               password;
    std::vector<std::string>  roles;
  };




  class PersistenceHandler
  {
    public:
      struct PersistenceException : std::runtime_error   {using runtime_error       ::runtime_error;};
      struct   NoSuchUser         : PersistenceException {using PersistenceException::PersistenceException;};
      struct   NoSuchProperty     : PersistenceException {using PersistenceException::PersistenceException;};

      PersistenceHandler            (                            ) = default;
      PersistenceHandler            ( const PersistenceHandler & ) = delete;
      PersistenceHandler & operator=( const PersistenceHandler & ) = delete;
      static  PersistenceHandler & instance();


      virtual std::vector<std::string> findRoles()                                       = 0;   // Returns list of all legal roles
      virtual UserCredentials          findCredentialsByName( const std::string & name ) = 0;   // Returns credentials for specified user, throws NoSuchUser if user not found


      virtual const std::string & operator[]( const std::string & key ) const = 0;


      virtual ~PersistenceHandler() noexcept = 0;
  };
} 
