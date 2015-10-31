#include		<string>
#include		<chrono>

namespace		Faculta
{

  class					Chronos
  {
    const std::string 			name_test;
    std::chrono::time_point<std::chrono::high_resolution_clock>		start_time;

    public:
    Chronos(std::string const name_test=std::string("test"));
    ~Chronos();
    Chronos(Chronos const &)=delete;
    Chronos &				operator=(Chronos const & chronos)=delete;
  
  };

}
