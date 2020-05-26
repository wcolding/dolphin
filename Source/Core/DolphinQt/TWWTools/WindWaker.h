#pragma once

#define PLAYER_STATUS_ADDR 0x803C4C08
#define PLAYER_INV_ADDR    0x803C4C44
#define PLAYER_AMMO_ADDR   0x803C4C65
#define PLAYER_BAGS_ADDR   0x803C4C7E
#define PLAYER_QUEST_ADDR  0x803C4CBC
#define PLAYER_CHARTS_ADDR 0x803C4CDC

#define PLAYER_BOWS  0x803C4C65
#define PLAYER_BOMBS 0x803C4C66
#define PLAYER_BUTTONS 0x803CA7DB

#define ADD_KEYS 0x803CA77C

#define READ_BUFFER_SIZE 64
#define PLAYER_STATUS_SIZE 104

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
    u16 maxHP;
    u16 currentHP;
    u8 wallet;
    u16 currentRupees;
    u8 maxMagic;
    u8 currentMagic;
  private:
    u8 padding[3];
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
    u8 sword;
    u8 shield;
    u8 bracelets;
    u8 spinAttack;
  private:
    u8 padding[3];
  };

  // These track current ammo, capacity, and tell the game whether to drop ammo or not
  struct Ammo
  {
    u8 bowCapacity;
    u8 bowAmmo;
    u8 bombCapacity;
    u8 bombAmmo;
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
    u8 bows;
    u8 bombs;
    u8 bracelets;
    u8 songs;
    u8 triforce;
    u8 pearls;
    u8 statues;
    u64 charts;
  private:
    u8 padding[3];
  };

  struct PlayerStatus
  {
    Status status;
    Inventory inventory;
    Ammo ammo;
    BagSection bags;
    QuestStatus questStatus;

    void ReadFromMemory();
  };

  u8 GetStageID();

  void WindWakerTrainerFrame();
}
