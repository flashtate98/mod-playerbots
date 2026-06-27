/*
* This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
* information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
* or (at your option) any later version.
*/

#include "Playerbots.h"
#include "BFTriggers.h"
#include "AiObject.h"
#include "AiObjectContext.h"
#include "RaidBossHelpers.h"

// Trash

bool ShadowmoonTechnicianMinesDetectedTrigger::IsActive()
{
    return bot->FindNearestGameObject(
        static_cast<uint32>(BloodFurnaceObjects::GO_PROXIMITY_BOMB), 5.0f, true);
}

// Keli'dan the Breaker

bool KelidanCastingBurningNovaTrigger::IsActive()
{
    Unit *kelidan = AI_VALUE2(Unit*, "find target", "keli'dan the breaker");
    return kelidan &&
           kelidan->HasAura(static_cast<uint32>(BloodFurnaceSpells::SPELL_BURNING_NOVA));
}
