#include "type.hh"

#include <iostream>

namespace pln
{
  void se_t::check_type(void)
  {
    try
    {
      if (se_type_ == DISC)
      {
        /* code */
      }
      else if (se_type_ == MASK)
      {
        /* code */
      }
      else if (se_type_ == RECTANGLE)
      {
        /* code */
      }
      else if (se_type_ == PERIODICLINE)
      {
        /* code */
      }
      else
        throw InvalidType("None");
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
  }
} // namespace pln