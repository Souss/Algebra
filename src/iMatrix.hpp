#ifndef			IMATRIX
#define			IMATRIX

#include		<utility>

namespace		Algebra
{
  typedef unsigned int uint;

  class			iMatrix
  {

    /*
     * Properties
     */
  public:

    virtual bool				is_symmetric() const = 0;
    virtual bool				is_singular() const = 0;
    virtual bool				is_invertible() const = 0;

    virtual std::pair<uint, uint>		get_dimensions() const = 0;
    virtual uint				get_nrow() const = 0;
    virtual uint				get_ncol() const = 0;

    virtual uint				determinant() const = 0;

  };
}

#endif // IMATRIX
