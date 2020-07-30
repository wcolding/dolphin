#include "WindWaker.h"
#include "ClientIO.h"
#include <iostream>
#include "Core/PowerPC/Gekko.h"
#include "Core/PowerPC/PowerPC.h"
#include "Core/PowerPC/MMU.h"
#include "Core/HW/Memmap.h"

namespace TWWTools
{
  void PlayerStatus::ReadFromMemory()
  {
    u8* currentSection;

    status.maxHP         = Memory::Read_U16(PLAYER_STATUS_ADDR);
    status.currentHP     = Memory::Read_U16(PLAYER_STATUS_ADDR + 2);
    status.wallet        = Memory::Read_U8(PLAYER_STATUS_ADDR + 18);
    status.currentRupees = Memory::Read_U16(PLAYER_STATUS_ADDR + 4);
    status.maxMagic      = Memory::Read_U8(PLAYER_STATUS_ADDR + 19);
    status.currentMagic  = Memory::Read_U8(PLAYER_STATUS_ADDR + 20);

    currentSection = Memory::GetPointer(PLAYER_INV_ADDR);
    memcpy(&inventory, currentSection, sizeof(inventory) - 4);
    inventory.sword      = Memory::Read_U8(PLAYER_STATUS_ADDR + 14);
    inventory.shield     = Memory::Read_U8(PLAYER_STATUS_ADDR + 15);
    inventory.bracelets  = Memory::Read_U8(PLAYER_STATUS_ADDR + 16);
    inventory.spinAttack = Memory::Read_U8(PLAYER_SWORD_SPIN);

    ammo.bowCapacity     = Memory::Read_U8(0x803C4C77);
    ammo.bowAmmo         = Memory::Read_U8(0x803C4C71);
    ammo.bombCapacity    = Memory::Read_U8(0x803C4C78);
    ammo.bombAmmo        = Memory::Read_U8(0x803C4C72);

    currentSection = Memory::GetPointer(PLAYER_BAGS_ADDR);
    memcpy(&bags, currentSection, sizeof(bags));

    questStatus.swords    = Memory::Read_U8(PLAYER_QUEST_ADDR);
    questStatus.shields   = Memory::Read_U8(PLAYER_QUEST_ADDR + 1);
    questStatus.bows      = Memory::Read_U8(PLAYER_BOWS);
    questStatus.bombs     = Memory::Read_U8(PLAYER_BOMBS);
    questStatus.bracelets = Memory::Read_U8(PLAYER_QUEST_ADDR + 2);
    questStatus.songs     = Memory::Read_U8(PLAYER_QUEST_ADDR + 9);
    questStatus.triforce  = Memory::Read_U8(PLAYER_QUEST_ADDR + 10);
    questStatus.pearls    = Memory::Read_U8(PLAYER_QUEST_ADDR + 11);
    questStatus.statues   = Memory::Read_U8(PLAYER_STATUES);
    questStatus.charts    = Memory::Read_U64(PLAYER_CHARTS_ADDR);
  }

  StageInfo GetStageInfo(u32 addr)
  {
    StageInfo temp;
    memset(&temp, 0, sizeof(StageInfo));

    u8* infoPtr = Memory::GetPointer(addr);
    if (infoPtr == nullptr)
      return temp;

    memcpy(&temp, infoPtr, sizeof(StageInfo));
    return temp;
  }

  u8 GetStageID()
  {
    return Memory::Read_U8(STAGE_ID);
  }

  void WorldState::ReadFromMemory()
  {
    u8* currentSection = Memory::GetPointer(PLAYER_NAME);
    memcpy(&playerName, currentSection, 8);

    stageID = GetStageID();

    currentSection = Memory::GetPointer(STAGE_NAME);
    memcpy(&stageName, currentSection, 8);

    zone = Memory::Read_U8(CURRENT_ZONE);

    sea       = GetStageInfo(STAGEINFO_SEA);
    sea_alt   = GetStageInfo(STAGEINFO_SEA_ALT);
    ff        = GetStageInfo(STAGEINFO_FF);
    drc       = GetStageInfo(STAGEINFO_DRC);

    fw        = GetStageInfo(STAGEINFO_FW);
    totg      = GetStageInfo(STAGEINFO_TOTG);
    earth     = GetStageInfo(STAGEINFO_EARTH);
    wind      = GetStageInfo(STAGEINFO_WIND);

    ganon     = GetStageInfo(STAGEINFO_GANON);
    hyrule    = GetStageInfo(STAGEINFO_HYRULE);
    ships     = GetStageInfo(STAGEINFO_SHIPS);
    houses    = GetStageInfo(STAGEINFO_HOUSES);

    caves     = GetStageInfo(STAGEINFO_CAVES);
    caves_alt = GetStageInfo(STAGEINFO_CAVES_ALT);
    chuchu    = GetStageInfo(STAGEINFO_CHUCHU);

    local     = GetStageInfo(STAGEINFO_LOCAL);
  }

  void WindWakerTrainerFrame()
  {
    PlayerStatus playerStatus;
    char statusBuffer[PLAYER_STATUS_SIZE];
    memset(&statusBuffer, 0, PLAYER_STATUS_SIZE);
    playerStatus.ReadFromMemory();
    memcpy(&statusBuffer, &playerStatus, PLAYER_STATUS_SIZE);
    //SendClient(SEND_PLAYERSTATUS, statusBuffer, PLAYER_STATUS_SIZE);
  }
}
