#include "WindWaker.h"

namespace TWWTools
{
  void PlayerStatus::ReadFromMemory()
  {
    u8 *currentSection = Memory::GetPointer(PLAYER_STATUS_ADDR);
    u8 buffer[64];
    memset(&buffer, 0, 64);

    memcpy(&buffer, currentSection, 64);
    status.maxHP = Memory::Read_U16(PLAYER_STATUS_ADDR); //Common::swap16(buffer[0]); 
    status.currentHP = Memory::Read_U16(PLAYER_STATUS_ADDR + 2); // Common::swap16(buffer[2]);
    status.currentRupees = Memory::Read_U16(PLAYER_STATUS_ADDR + 4); // Common::swap16(buffer[4]);
    status.buttonItemX = buffer[9];
    status.buttonItemY = buffer[10];
    status.buttonItemZ = buffer[11];
    status.equippedSword = buffer[14];
    status.equippedShield = buffer[15];
    status.equippedBracelets = buffer[16];
    status.wallet = buffer[18];
    status.maxMagic = buffer[19];
    status.currentMagic = buffer[20];
    memset(&buffer, 0, sizeof(status));

    currentSection = Memory::GetPointer(PLAYER_INV_ADDR);
    memcpy(&inventory, currentSection, sizeof(inventory));

    currentSection = Memory::GetPointer(PLAYER_AMMO_ADDR);
    memcpy(&ammo, currentSection, sizeof(ammo));

    currentSection = Memory::GetPointer(PLAYER_BAGS_ADDR);
    memcpy(&bags, currentSection, sizeof(bags));

    currentSection = Memory::GetPointer(PLAYER_QUEST_ADDR);
    memcpy(&questStatus, currentSection, sizeof(questStatus));

  }

  StageID GetStageID()
  {
    return (StageID)(PowerPC::Read_U8(0x803C53A4));
  }
}
