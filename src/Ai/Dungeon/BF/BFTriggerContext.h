/*
* This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
* information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
* or (at your option) any later version.
*/

#ifndef _PLAYERBOT_TBCDUNGEONBLOODFURNACETRIGGERCONTEXT_H
#define _PLAYERBOT_TBCDUNGEONBLOODFURNACETRIGGERCONTEXT_H

#include "AiObjectContext.h"
#include "TriggerContext.h"
#include "BFTriggers.h"

class TbcDungeonBloodFurnaceTriggerContext : public NamedObjectContext<Trigger>
{
public:
    TbcDungeonBloodFurnaceTriggerContext()
    {
        // Trash
        creators["shadowmoon technician mines detected"] =
            &TbcDungeonBloodFurnaceTriggerContext::shadowmoon_technician_mines_detected;

        // Keli'dan the Breaker
        creators["kelidan casting burning nova"] =
            &TbcDungeonBloodFurnaceTriggerContext::kelidan_casting_burning_nova;
    }
private:
    // Trash
    static Trigger* shadowmoon_technician_mines_detected(
        PlayerbotAI* botAI) { return new ShadowmoonTechnicianMinesDetectedTrigger(botAI); }

    // Keli'dan the Breaker
    static Trigger* kelidan_casting_burning_nova(
        PlayerbotAI* botAI) { return new KelidanCastingBurningNovaTrigger(botAI); }
};

#endif
