#pragma once
#include "Core/PowerPC/Gekko.h"
#include "Core/PowerPC/PowerPC.h"
#include "Core/PowerPC/MMU.h"
#include "Core/HW/Memmap.h"

#define PLAYER_STATUS_ADDR 0x803C4C08
#define PLAYER_INV_ADDR    0x803C4C44
#define PLAYER_AMMO_ADDR   0x803C4C65
#define PLAYER_BAGS_ADDR   0x803C4C7E
#define PLAYER_QUEST_ADDR  0x803C4CBC
#define PLAYER_CHARTS_ADDR 0x803C4CDC

namespace TWWTools
{

  typedef enum : u8
  {
    Sea = 0,
    SeaAlt = 1,
    FF = 2,
    DRC = 3,
    FW = 4,
    TotG = 5,
    Earth = 6,
    Wind = 7,
    Ganon = 8,
    Hyrule = 9,
    Ship = 10,
    Houses = 11,
    Caves = 12,
    CavesB = 13,
    ChuChu = 14,
    Test = 15
  } StageID;

  struct Bag
  {
    u8 contents[8];
  };

  struct Status
  {
  public:
    u16 maxHP;
    u16 currentHP;
    u16 currentRupees;
    u8 buttonItemX;
    u8 buttonItemY;
    u8 buttonItemZ;
  private:u16 ignore;
  public:
    u8 equippedSword;
    u8 equippedShield;
    u8 equippedBracelets;
    u8 wallet;
    u8 maxMagic;
    u8 currentMagic;
  };

  struct Inventory
  {
    u8 telescope;
    u8 sail;
    u8 windwaker;
    u8 grapplingHook;
    u8 spoilsBag;
    u8 boomerang;
    u8 dekuLeaf;
    u8 tingleTuner;
    u8 pictoBox;
    u8 ironBoots;
    u8 magicArmor;
    u8 baitBag;
    u8 bow;
    u8 bombs;
    u8 bottle1;
    u8 bottle2;
    u8 bottle3;
    u8 bottle4;
    u8 deliveryBag;
    u8 hookshot;
    u8 skullHammer;
  };

  // These track current ammo, capacity, and tell the game whether to drop ammo or not
  struct Ammo
  {
  public:
    u8 ownedBows;
    u8 ownedBombs;
  private: u32 ignore;
  public:
    u8 bowAmmo;
    u8 bombAmmo;
  private: u8 ignoreB;
  public:
    u8 bowCapacity;
    u8 bombCapacity;
  };

  struct BagSection
  {
    Bag spoilsBag;
    Bag baitBag;
    Bag deliveryBag;
  };

  struct QuestStatus
  {
    u8 swords; // checked by randomizer progressive sword code
    u8 shields;
    u8 bracelets;
    u8 piratesCharm;
    u8 herosCharm;
    u8 songs;
    u8 triforce;
    u8 pearls;
  };
  struct PlayerStatus
  {
    Status status;
    Inventory inventory;
    Ammo ammo;
    BagSection bags;
    QuestStatus questStatus;
    u64 charts;

    void ReadFromMemory();
  };

  StageID GetStageID();
}
