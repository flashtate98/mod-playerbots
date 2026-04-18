#ifndef _PLAYERBOT_TBCDUNGEONMAGISTERSTERRACEMULTIPLIERS_H
#define _PLAYERBOT_TBCDUNGEONMAGISTERSTERRACEMULTIPLIERS_H

#include "Multiplier.h"

class AvoidMagicDampeningFieldMultiplier : public Multiplier
{
public:
    AvoidMagicDampeningFieldMultiplier(PlayerbotAI* botAI) : Multiplier(botAI, "avoid magic dampening field") {}
    float GetValue(Action* action) override;
};

#endif