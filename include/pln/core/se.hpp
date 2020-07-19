// Design pattern shown on https://www.youtube.com/watch?v=ZPk8HuyrKXU

#include <mln/core/se/rect2d.hpp>
#include <mln/core/se/disc.hpp>
#include <mln/core/se/periodic_line2d.hpp>
#include <mln/core/se/mask2d.hpp>
#include <mln/core/point.hpp>

namespace pln
{
    class se_t
    {
    public:
        se_t(mln::se::rect2d val)
        {
            rect = val ;
            value_type = RECT;
        }
        se_t(mln::se::disc val)
        {
            disc = val ;
            value_type = DISC;
        }
        se_t(mln::se::periodic_line2d val)
        {
            line = val ;
            value_type = LINE;
        }
        se_t(mln::se::mask2d val)
        {
            mask = val ;
            value_type = MASK;
        }

        mln::se::rect2d get_rect()
        {
            return rect.value();
        }

        mln::se::disc get_disc()
        {
            return disc.value();
        }

        mln::se::periodic_line2d get_line()
        {
            return line.value();
        }

        mln::se::mask2d get_mask()
        {
            return mask.value();
        }

        enum
        {
            RECT,
            DISC,
            LINE,
            MASK
        } value_type;

    private:
        std::optional<mln::se::rect2d> rect;
        std::optional<mln::se::disc> disc;
        std::optional<mln::se::periodic_line2d> line;
        std::optional<mln::se::mask2d> mask;
    };
}
