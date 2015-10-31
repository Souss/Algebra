#include		<string>
#include		<sstream>
#include		<stdexcept>
#include		<random>
#include		<algorithm>

#include		<iostream>

#include		"Matrix.hpp"

namespace		Algebra
{

  /*
   *   Lifetime Object Control
   *
   *   Implementation
   */
  Matrix::Matrix(const uint nline, const uint ncol, bool random,
		 const int rand_min_val, const int rand_max_val):
    dimensions(nline, ncol), random(random), grid(nullptr),
    rand_min_val(rand_min_val), rand_max_val(rand_max_val)
  {
    if (rand_min_val > rand_max_val)
      throw std::range_error((std::string("rand_min_val should be inferior to rand_max_val (")
			      + std::to_string(rand_min_val) + " > "
			      + std::to_string(rand_max_val) + ")")
			     );
			
    this->__grid_generation();
  }

  Matrix::~Matrix()
  {
    for (uint iline = 0; iline < this->dimensions.first; ++iline)
      delete[] this->grid[iline];
    delete[] this->grid;
  }

  Matrix::Matrix(const Matrix &other)
  {
    if (this != &other)
      {
	this->dimensions = std::make_pair(other.dimensions.first,
					  other.dimensions.second);
        this->random = other.random;
	this->rand_min_val = other.rand_min_val;
	this->rand_max_val = other.rand_max_val;
	this->grid = new int*[this->dimensions.first];
	for (uint iline = 0; iline < this->dimensions.first; ++iline)
	  {
	    this->grid[iline] = new int[this->dimensions.second];
	    std::copy_n(this->grid[iline], this->dimensions.second,
			other.grid[iline]);
	  }
      }
  }


  /*
   * Grid random generation
   *
   */
  void						Matrix::__grid_generation()
  {
    std::random_device				rd;
    std::mt19937				gen(rd());
    std::uniform_int_distribution<>		distrib(this->rand_min_val,
							this->rand_max_val);

    this->grid = new int*[this->dimensions.first];
    for (uint iline = 0; iline < this->dimensions.first; ++iline)
      {
	this->grid[iline] = new int[this->dimensions.second];
	for (uint icol = 0; icol < this->dimensions.second; ++icol)
	  this->grid[iline][icol] = distrib(gen);
      }
  }

  /*
   * Accessors
  int *						Matrix::operator[](uint index)
  {
    if (this->dimensions.first >= index)
      throw std::out_of_range("Line index out of matrix range");
    return this->grid[index]
  }
   */

  /*
   *  States
   *
   */
  bool		       				Matrix::is_symmetric() const
  {
    return false;
  }

  bool						Matrix::is_singular() const
  {
    return false;
  }

  bool						Matrix::is_invertible() const
  {
    return false;
  }

  /*
   *  Properties access
   *
   */
  std::pair<uint, uint>				Matrix::get_dimensions() const
  {
    return this->dimensions;
  }

  uint			        		Matrix::get_nrow() const
  {
    return this->dimensions.first;
  }

  uint						Matrix::get_ncol() const
  {
    return this->dimensions.second;
  }

  /*
   *  Caracteristics
   *
   */

  uint						Matrix::determinant() const
  {
    return 0;
  }

  /*
   * Display matrix content
   *
   */

  const std::string *				Matrix::dump() const
  {
    std::string *				repr = new std::string();

    for (uint iline = 0; iline < this->dimensions.first; ++iline)
      {
	std::ostringstream			line;

	line << "[";
	for (uint icol = 0; icol < this->dimensions.second; ++icol)
	  {
	    line << this->grid[iline][icol];
	    if (icol + 1 < this->dimensions.second)
	      line << ", ";
	  }
	line << "]";
	*repr += line.str();
	if (iline + 1 < this->dimensions.first)
	  *repr += "\n";
      }

    return repr;
  }

  std::ostream &			        operator<<(std::ostream &os,
							   const Matrix &matrix)
  {
    const std::string *				dump = matrix.dump();

    os << *dump;
    delete dump;
    return os;
  }

}
