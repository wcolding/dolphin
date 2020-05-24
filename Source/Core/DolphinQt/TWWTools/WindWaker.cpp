#include "WindWaker.h"
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
    inventory.spinAttack = Memory::Read_U8(0x803C5295);

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
    questStatus.statues   = Memory::Read_U8(0x803C5296);
    questStatus.charts    = Memory::Read_U64(PLAYER_CHARTS_ADDR);
  }

  StageID GetStageID()
  {
    return (StageID)(PowerPC::Read_U8(0x803C53A4));
  }
}
