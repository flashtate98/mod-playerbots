/*
* This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
* information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
* or (at your option) any later version.
*/

#ifndef _PLAYERBOT_TBCDUNGEONBLOODFURNACEACTIONS_H
#define _PLAYERBOT_TBCDUNGEONBLOODFURNACEACTIONS_H

#include "AttackAction.h"
#include "MovementActions.h"
#include "Action.h"
#include "BFTriggers.h"

// Trash

class ShadowmoonTechnicianAvoidMinesAction : public MovementAction
{
public:
    ShadowmoonTechnicianAvoidMinesAction(
        PlayerbotAI* botAI, std::string const name = "shadowmoon technician avoid mines") : MovementAction(botAI, name) {}
    bool Execute(Event event) override;
};

// Keli'dan the Breaker

class FleeBurningNovaAction : public MovementAction
{
public:
    FleeBurningNovaAction(
        PlayerbotAI* botAI, std::string const name = "kelidan flee burning nova") : MovementAction(botAI, name) {}
    bool Execute(Event event) override;
};

#endif
