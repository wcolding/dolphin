#include "ClientIO.h"

namespace TWWTools
{
  void SendClient(std::string msg)
  {
    std::cout << msg << std::endl;
  }

  std::string ReadClient()
  {
    std::string msg = "";
    std::getline(std::cin, msg);
    return msg;
  }
}
