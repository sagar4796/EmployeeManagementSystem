#pragma once

namespace Domain::Project
{
  // Library Package within the Domain Layer Abstract class
  class AllocateProjectHandler
  {
    public:
      // Operations
      //   Work in progress ...


      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
      virtual ~AllocateProjectHandler() noexcept = 0;

    protected:
      // Copy assignment operators, protected to prevent mix derived-type assignments
      AllocateProjectHandler & operator=( const AllocateProjectHandler &  rhs ) = default;  // copy assignment
      AllocateProjectHandler & operator=(       AllocateProjectHandler && rhs ) = default;  // move assignment

  };    // class MaintainBooksHandler





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline AllocateProjectHandler::~AllocateProjectHandler() noexcept = default;


} // namespace Domain::Library
