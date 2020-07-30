#pragma once

#define PLAYER_STATUS_ADDR 0x803C4C08
#define PLAYER_INV_ADDR    0x803C4C44
#define PLAYER_AMMO_ADDR   0x803C4C65
#define PLAYER_BAGS_ADDR   0x803C4C7E
#define PLAYER_QUEST_ADDR  0x803C4CBC
#define PLAYER_CHARTS_ADDR 0x803C4CDC

#define PLAYER_BOWS          0x803C4C65
#define PLAYER_BOMBS         0x803C4C66
#define PLAYER_BUTTONS       0x803CA7DB
#define PLAYER_SWORD_SPIN    0x803C5295
#define PLAYER_STATUES       0x803C5296

#define ADD_KEYS 0x803CA77C

#define STAGEINFO_SEA       0x803C4F88
#define STAGEINFO_SEA_ALT   0x803C4FAC
#define STAGEINFO_FF        0x803C4FD0
#define STAGEINFO_DRC       0x803C4FF4
#define STAGEINFO_FW        0x803C5018
#define STAGEINFO_TOTG      0x803C503C
#define STAGEINFO_EARTH     0x803C5060
#define STAGEINFO_WIND      0x803C5084
#define STAGEINFO_GANON     0x803C50A8
#define STAGEINFO_HYRULE    0x803C50CC
#define STAGEINFO_SHIPS     0x803C50F0
#define STAGEINFO_HOUSES    0x803C5114
#define STAGEINFO_CAVES     0x803C5138
#define STAGEINFO_CAVES_ALT 0x803C515C
#define STAGEINFO_CHUCHU    0x803C5180
#define STAGEINFO_LOCAL     0x803C5380

#define PLAYER_NAME  0x803C4D64
#define STAGE_ID     0x803C53A4
#define STAGE_NAME   0x803C9D3C
#define CURRENT_ZONE 0x803C4632    // not documented...uncharted waters so to speak

#define READ_BUFFER_SIZE 64
#define PLAYER_STATUS_SIZE 79
#define WORLD_STATE_SIZE 562

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
    Ships = 10,
    Houses = 11,
    Caves = 12,
    CavesAlt = 13,
    ChuChu = 14,
    Test = 15,
    Local = 0xFF
  } StageID;

  typedef enum : u8
  {
    Map = 0,
    Compass = 0x01,
    BigKey = 0x02,
    BossDead = 0x04,
    BossHC = 0x08,
    BossIntro = 0x10
  } DungeonFlags;

#pragma pack(push, 1)

  struct Bag
  {
    u8 contents[8];
  };

  struct Status // 9 bytes
  {
    u16 maxHP;
    u16 currentHP;
    u8 wallet;
    u16 currentRupees;
    u8 maxMagic;
    u8 currentMagic;
  };

  struct Inventory // 25 bytes
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
  };

  // These track current ammo, capacity, and tell the game whether to drop ammo or not
  struct Ammo // 4 bytes
  {
    u8 bowCapacity;
    u8 bowAmmo;
    u8 bombCapacity;
    u8 bombAmmo;
  };

  struct BagSection // 24 bytes
  {
    Bag spoilsBag;
    Bag baitBag;
    Bag deliveryBag;
  };

  struct QuestStatus // 17 bytes
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

  struct StageInfo
  {
    u8 chestFlags[4];
    u8 eventSwitches[16];
    u8 itemPickupFlags[4];
    u8 visitedRooms[8];
    u8 smallKeys;
    u8 dungeonFlags;
  };

  StageInfo GetStageInfo(u32 addr);

  struct WorldState
  {
    char playerName[8];
    u8 stageID;
    char stageName[8];
    u8 zone;
    StageInfo sea;
    StageInfo sea_alt;
    StageInfo ff;
    StageInfo drc;
    StageInfo fw;
    StageInfo totg;
    StageInfo earth;
    StageInfo wind;
    StageInfo ganon;
    StageInfo hyrule;
    StageInfo ships;
    StageInfo houses;
    StageInfo caves;
    StageInfo caves_alt;
    StageInfo chuchu;
    StageInfo local; // we don't need to track test stage flags

    void ReadFromMemory();
  };

#pragma pack(pop)
  u8 GetStageID();

  void WindWakerTrainerFrame();
}
