#ifndef _PLAYERBOT_TBCDUNGEONAUCHENAICRYPTSACTIONS_H
#define _PLAYERBOT_TBCDUNGEONAUCHENAICRYPTSACTIONS_H

#include "Playerbots.h"
#include "Action.h"
#include "MovementActions.h"
#include "AuchenaiCryptsTriggers.h"

class FleeFocusFireAction : public MovementAction
{
public:
    FleeFocusFireAction(PlayerbotAI* botAI) : MovementAction(botAI, "flee focus fire") {}
    bool Execute(Event event) override;
};

#endif