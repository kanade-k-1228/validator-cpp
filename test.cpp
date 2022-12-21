#include "validator.hpp"
#include <iomanip>
#include <iostream>

int main(int argc, char* argv[]) {
  Valid::Condition cond(argv[1]);
  auto result = cond.match(argv[2]);

  std::cout
      << std::setw(5) << argv[2]
      << " > " << std::left << std::setw(8) << cond.print()
      << " > ";
  if(result)
    std::cout << result.value() << std::endl;
  else
    std::cout << "\033[31m!!!\033[0m" << std::endl;
}
