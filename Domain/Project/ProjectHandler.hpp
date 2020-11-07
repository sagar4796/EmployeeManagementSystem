/* 
 CPSC 462 
 Project : Employee Management System
 Group : Graduate Group 3
 Team Members : Sagar Ramani, Nirav Patil, Adit Gandhi, Abhiranjan Singh

*/


#pragma once
#include <array>
#include <iostream>
#include <string>

namespace Domain::Project
{
  class ProjectHandler
  {
  protected:
    std::array<std::string, 4> AvailableProjects;
    std::array<std::string, 4> employees;
    std::array<std::string, 4> projectRoles;


  public:

    ProjectHandler();
    ProjectHandler( const ProjectHandler & original ) = default;    //Copy const
    ProjectHandler( ProjectHandler && original )      = default;    //Move Constructor can be removed later
    ~ProjectHandler() noexcept;




    std::array<std::string, 4> get_projects();

    std::array<std::string, 4> get_employee();

    std::array<std::string, 4> get_project_role();
  };
}
