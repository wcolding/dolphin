#pragma once
#include <string>
#include <Windows.h>

#define DOLPHIN_OUT_PIPE L"\\\\.\\pipe\\fromDolphin"
#define DOLPHIN_IN_PIPE  L"\\\\.\\pipe\\toDolphin"

#define PIPE_BUFFER_SIZE 256

#define SEND_PLAYERSTATUS 1

namespace TWWTools
{

  class ClientHandler
  {
  public:
    bool clientConnected = false;

    void SendClient(int msgType, char* buffer, size_t len);
    ClientHandler();

  private:
    HANDLE outPipe;
    HANDLE inPipe;
    LPDWORD bytesWritten = 0;
  };

}
