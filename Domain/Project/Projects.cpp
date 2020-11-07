#pragma once
#include <array>
#include <iostream>
#include <string>

#include "ProjectHandler.hpp";

namespace Domain::Project
{
  ProjectHandler::ProjectHandler()
  {
     AvailableProjects = { "Apple",
                 "Google",
                 "Amazon",
                 "Facebook" };

     employees = { "Tommen",
                 "sam",
                 "julie",
                 "david" };

     projectRoles = { "Leader",
                     "Developer",
                     "Test",
                     "Support" };

  }

  ProjectHandler::~ProjectHandler() noexcept {}
    

  std::array<std::string, 4> ProjectHandler::get_projects()
  {
    return AvailableProjects;
  }

  std::array<std::string, 4> ProjectHandler::get_employee()
  {
    return employees;
  }

  std::array<std::string, 4> ProjectHandler::get_project_role()
  {
    return projectRoles;
  }


}    // namespace Domain::Project
