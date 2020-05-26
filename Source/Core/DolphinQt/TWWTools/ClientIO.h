#pragma once
#include <string>

#define SEND_PLAYERSTATUS 1

namespace TWWTools
{
  void SendClient(int msgType, char* buffer, size_t len);

  //char* ReadClient();

  void SendRawAndEcho(std::string msg);


}
