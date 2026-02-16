#ifndef _PLAYERBOT_TBCDUNGEONAUCHENAICRYPTSMULTIPLIERS_H
#define _PLAYERBOT_TBCDUNGEONAUCHENAICRYPTSMULTIPLIERS_H

#include "Multiplier.h"

class ShirrakFocusFireMultiplier : public Multiplier
{
public:
    ShirrakFocusFireMultiplier(PlayerbotAI* ai) : Multiplier(ai, "flee focus fire") {}
    float GetValue(Action* action) override;
};

#endif