#pragma once

#include <sstream>
#include <exception>

class InvalidType : public std::exception
{
public:

  InvalidType(const std::string& msg)
  : msg_(msg)
  {}
    
  const char* what() const noexcept
  {
    return msg_.c_str();
  }

private:
  std::string msg_;
};