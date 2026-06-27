/*
* This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
* information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
* or (at your option) any later version.
*/

#ifndef _PLAYERBOT_TBCDUNGEONHELLFIRERAMPARTSACTIONCONTEXT_H
#define _PLAYERBOT_TBCDUNGEONHELLFIRERAMPARTSACTIONCONTEXT_H

#include "AiObjectContext.h"
#include "Action.h"
#include "BFActions.h"

class TbcDungeonBloodFurnaceActionContext : public NamedObjectContext<Action>
{
public:
    TbcDungeonBloodFurnaceActionContext() : NamedObjectContext<Action>(false, true)
    {
        // Trash
        creators["shadowmoon technician avoid mines"] =
            &TbcDungeonBloodFurnaceActionContext::shadowmoon_technician_avoid_mines;

        // Keli'dan the Breaker
        creators["kelidan flee burning nova"] =
            &TbcDungeonBloodFurnaceActionContext::kelidan_flee_burning_nova;
    }
private:
    // Trash
    static Action* shadowmoon_technician_avoid_mines(
        PlayerbotAI* botAI) { return new ShadowmoonTechnicianAvoidMinesAction(botAI); }

    // Keli'dan the Breaker
    static Action* kelidan_flee_burning_nova(
        PlayerbotAI* botAI) { return new FleeBurningNovaAction(botAI); }

};

#endif
