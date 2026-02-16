#ifndef _PLAYERBOT_TBCDUNGEONAUCHENAICRYPTSACTIONS_H
#define _PLAYERBOT_TBCDUNGEONAUCHENAICRYPTSACTIONS_H

#include "MovementActions.h"

class ShirrakFocusFireAction : public MovementAction
{
public:
    ShirrakFocusFireAction(PlayerbotAI* botAI, std::string const name = "flee focus fire") 
        : MovementAction(botAI, name) {}
    bool Execute(Event /*event*/) override;
};

#endif