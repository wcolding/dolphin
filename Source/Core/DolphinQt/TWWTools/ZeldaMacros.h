#pragma once
#include "Core/HW/Memmap.h"

#define X_BUTTON_ITEM 0x803CA7DB
#define Y_BUTTON_ITEM 0x803CA7DC
#define Z_BUTTON_ITEM 0x803CA7DD

#define SET_PICTOBOX 1
#define SET_BOW      2
#define SET_SWORD    3
#define SET_SHIELD   4
#define SET_MAGIC    5
#define SET_WALLET   6
#define SET_BOW_CAPACITY 7
#define SET_BOMB_CAPACITY 8

namespace TWWTools
{

  void GiveTelescope();
  void GiveSail();
  void GiveWindWaker();
  void GiveGrapplingHook();
  void GiveSpoilsBag();
  void GiveBoomerang();
  void GiveDekuLeaf();

  void GiveTingleTuner();
  void SetPictoBox(int camLvl);
  void GiveIronBoots();
  void GiveMagicArmor();
  void GiveBaitBag();
  void SetBow(int bowLvl);
  void GiveBombBag();

  void SetBottleSlot(int slot, u8 contents);
  void GiveMailBag();
  void GiveHookshot();
  void GiveSkullHammer();

  void GiveBracelet();
  void GiveHurricaneSpin();
  void SetSword(int swordLvl);
  void SetShield(int shieldLvl);

  void UpdateEquipButtons(int itemCode);

  void UpgradeItem(int itemCode);
  void DowngradeItem(int itemCode);
  void RemoveItem(u8 item);

  void AddKeys(u16 keys);

  void AddSongs(u8 songs);
  void RemoveSongs(u8 songs);

  void GiveWindsRequiem();
  void GiveBalladofGales();
  void GiveCommandMelody();
  void GiveEarthGodsLyric();
  void GiveWindGodsAria();
  void GiveSongofPassing();

  void AddPearls(u8 pearls);
  void RemovePearls(u8 pearls);

  void GiveDinsPearl();
  void GiveFaroresPearl();
  void GiveNayrusPearl();

  void SetTriforce(u8 triforce);
  void SetStatues(u8 statues);

  bool HasFlag(u8 value, u8 flag);
}
