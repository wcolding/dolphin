#pragma once
#include <string>
#include <Windows.h>

#define DOLPHIN_OUT_PIPE L"\\\\.\\pipe\\fromDolphin"
#define DOLPHIN_IN_PIPE  L"\\\\.\\pipe\\toDolphin"

#define PIPE_BUFFER_SIZE 1024

#define SEND_PLAYERSTATUS 1
#define SEND_WORLDSTATE 2
#define GIVE_ITEM 3
#define GIVE_KEYS 4
#define UPGRADE_ITEM 5
#define DOWNGRADE_ITEM 6
#define REVOKE_ITEM 7
#define GIVE_SONG 8
#define REMOVE_SONG 9
#define GIVE_PEARL 10
#define REMOVE_PEARL 11

namespace TWWTools
{

  class ClientHandler
  {
  public:
    bool clientConnected = false;

    void SendClient(int msgType, char* buffer, size_t len);
    void ReceiveClient();
    ClientHandler();

  private:
    HANDLE outPipe;
    HANDLE inPipe;
    LPDWORD bytesIO = 0;

    static DWORD WINAPI ClientReadThread(LPVOID lpParam);
  };

}
