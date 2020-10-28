#pragma once

#include "Domain/Project/AllocateProjectHandler.hpp"

namespace Domain::Project
{
  class Projects : public Domain::Project::AllocateProjectHandler
  {
    public:
      // Constructors
      using AllocateProjectHandler::AllocateProjectHandler;  // inherit constructors

      // Operations

     ~Projects() noexcept override;
  }; // class Books


  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline Projects::~Projects() noexcept
  {}


}  // namespace Domain::Library
