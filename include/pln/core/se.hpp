// Design pattern shown on https://www.youtube.com/watch?v=ZPk8HuyrKXU

namespace pln
{
    class se_t
    {
    public:
        template <typename T>
        se_t(T&& value)
        {
            *this = value ; // calls overloaded = operator
        }

	template<typename T>
        se_t& operator=(T&& value)
        {
            m_value.reset(new Model<T>(value));
	    return *this;
        }
    private:
        struct Concept // Our interface
        {
            virtual ~Concept() {}
            virtual int radial_extent() const = 0; // mask2d
            //virtual void .... () (const) = 0;
        };

        template <typename T>
        struct Model : Concept // To proceed virtual dispatch
        {
            Model(T const& value) // T const& same as const T&
                : m_val(value)
            {}
            
            int radial_extent() const override
            {
                return m_val.radial_extent();
            }

	    /*void ... () (const) override
            {
                m_val....();
            }*/

	    T m_val;
	};
        std::unique_ptr<Concept> m_value;
    };
}
