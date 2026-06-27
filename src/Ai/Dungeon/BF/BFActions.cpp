/*
* This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
* information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
* or (at your option) any later version.
*/
#include "Playerbots.h"
#include "PlayerbotAI.h"
#include "AiFactory.h"
#include "BFTriggers.h"
#include "BFActions.h"
#include "MovementActions.h"
#include "RaidBossHelpers.h"

constexpr uint32 BF_MAP_ID = 542;

// Trash

// Bots will avoid walking over mines when they are detected
bool ShadowmoonTechnicianAvoidMinesAction::Execute(Event /*event*/)
{
    GameObject* mine = bot->FindNearestGameObject(
        static_cast<uint32>(BloodFurnaceObjects::GO_PROXIMITY_BOMB), 5.0f, true);

    if (!mine)
        return false;

    float currentDistance = bot->GetDistance2d(mine);
    constexpr float safeDistance = 5.0f;
    constexpr uint32 minInterval = 0;
    if (currentDistance < safeDistance)
        return FleePosition(mine->GetPosition(), safeDistance, minInterval);

    return false;
}

// Keli'dan the Breaker

// Bots will flee from Keli'dan's Burning Nova ability
bool FleeBurningNovaAction::Execute(Event /*event*/)
{
    Unit *kelidan = AI_VALUE2(Unit*, "find target", "keli'dan the breaker");
    if (!kelidan)
        return false;

    float currentDistance = bot->GetDistance2d(kelidan);
    constexpr float safeDistance = 20.0f;
    constexpr uint32 minInterval = 0;
    if (currentDistance < safeDistance)
        return FleePosition(kelidan->GetPosition(), safeDistance, minInterval);

    return false;
}
