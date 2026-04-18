#ifndef _PLAYERBOT_TBCMAGISTERSTERRACEACTIONS_H
#define _PLAYERBOT_TBCMAGISTERSTERRACEACTIONS_H

#include "AttackAction.h"
#include "MovementActions.h"
#include "MagistersTerraceTriggers.h"

class AvoidMagicDampeningFieldAction : public MovementAction
{
public:
    AvoidMagicDampeningFieldAction(PlayerbotAI* botAI) : MovementAction(botAI, "avoid magic dampening field") {}
    bool Execute(Event event) override;
};

#endif
