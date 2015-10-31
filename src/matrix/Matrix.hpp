#ifndef			MATRIX
#define			MATRIX

#include			"iMatrix.hpp"

namespace			Algebra
{

  class				Matrix : public iMatrix
  {

  private:
    std::pair<uint, uint>		dimensions;
    int **	       			grid;
    
    bool				random;
    int					rand_min_val;
    int					rand_max_val;

  private:

    /*
     *  Life Time Object Control
     *
     */
  public:
    Matrix()=delete;
    Matrix(const uint nline, const uint ncol, bool random=false,
	   const int rand_min_val=-50, const int rand_max_val=50);
    ~Matrix();
    Matrix(const Matrix &);
    Matrix &				operator=(const Matrix &);

  private:
    void				__grid_generation();

  public:  
    bool				is_symmetric() const;
    bool				is_singular() const;
    bool				is_invertible() const;

  public:
    std::pair<uint, uint>		get_dimensions() const;
    uint			        get_nrow() const;
    uint				get_ncol() const;

  public:
    uint				determinant() const;

  public:
    const std::string	*		dump() const;

  private:
    friend std::ostream &		operator<<(std::ostream &os,
						   const Matrix &matrix);
  };
  
}


#endif // MATRIX
