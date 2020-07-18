#pragma once

//#include <mln/core/image/ndimage.hpp>
//#include "include/pln/core/se.hpp"
#include <mln/core/se/rect2d.hpp>
#include <mln/core/se/disc.hpp>
#include <mln/core/se/periodic_line2d.hpp>
#include <mln/core/se/mask2d.hpp>
#include <mln/core/point.hpp>
#include <initializer_list>

#include "invalid_arg.hh"

enum SE_TYPE
{
  NONE=0,
  DISC,
  MASK,
  RECTANGLE,
  PERIODICLINE
};

enum approx
{
  EXACT = 0,
  PERIODIC_LINES_8=8
};

namespace pln
{
  class se_t
  {
  public:
    // Rectangle
    se_t()
    {
      se_type_ = RECTANGLE;
      struct_ = mln::se::rect2d();
    }// empty
    se_t(int width, int height)
    {
      se_type_ = RECTANGLE;
      struct_ = mln::se::rect2d(width, height);
    }

    // Disc
    se_t(float radius, approx approximation = PERIODIC_LINES_8)
    {
      se_type_ = DISC;
      struct_ = mln::se::disc(radius, approximation);
    }

    // periodic_line2d
    se_t(mln::point2d V, int k)
    {
      se_type_ = PERIODICLINE;
      struct_ = mln::se::periodic_line2d(V, k);
    }

    //mask
    se_t(std::initializer_list<std::initializer_list<int>> values)
    {
      se_type_ = MASK;
      struct_ = mln::se::mask2d(values);
    }

    //None
    se_t(...)
    {
      se_type_ = NONE;
    }

    ~se_t() = delete;

    void check_type();

    template<class S>
    S* get_struct() {
      return struct_;
    }

    enum SE_TYPE get_type() {
      return se_type_;
    }
  private:
    template<class S>
    S* struct_;
    enum SE_TYPE se_type_ = NONE;
  };
} // namespace pln
