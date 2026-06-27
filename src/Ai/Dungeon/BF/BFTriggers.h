/*
* This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
* information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
* or (at your option) any later version.
*/

#ifndef _PLAYERBOT_TBCDUNGEONBLOODFURNACETRIGGERS_H
#define _PLAYERBOT_TBCDUNGEONBLOODFURNACETRIGGERS_H

#include "Trigger.h"
#include "GenericTriggers.h"
#include "DungeonStrategyUtils.h"

enum class BloodFurnaceSpells : uint32
{
    SPELL_BURNING_NOVA = 30940,
};

enum class BloodFurnaceObjects : uint32
{
    GO_PROXIMITY_BOMB = 181877,
};

// Trash

class ShadowmoonTechnicianMinesDetectedTrigger : public Trigger
{
public:
    ShadowmoonTechnicianMinesDetectedTrigger(PlayerbotAI* botAI) : Trigger(botAI, "shadowmoon technician mines detected") {}

    bool IsActive() override;
};

// Keli'dan the Breaker

class KelidanCastingBurningNovaTrigger : public Trigger
{
public:
    KelidanCastingBurningNovaTrigger(PlayerbotAI* botAI) : Trigger(botAI, "kelidan casting burning nova") {}

    bool IsActive() override;
};
#endif
