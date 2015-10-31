#include		<iostream>
#include		"Matrix.hpp"

int			main(int argc, char *argv[])
{
  Algebra::Matrix	matrix(3, 4);

  std::cout << "[" << argv[0] << "]"
	    << " Test functionalities"<< std::endl;

  return 0;
}
