#ifndef _PLAYERBOT_RAIDMCMULTIPLIERS_H
#define _PLAYERBOT_RAIDMCMULTIPLIERS_H

#include "Multiplier.h"

class GarrDisableDpsAoeMultiplier : public Multiplier
{
public:
    GarrDisableDpsAoeMultiplier(PlayerbotAI* botAI) : Multiplier(botAI, "garr disable dps aoe multiplier") {}
    float GetValue(Action* action) override;
};

class BaronGeddonInfernoMultiplier : public Multiplier
{
public:
    BaronGeddonInfernoMultiplier(PlayerbotAI* botAI) : Multiplier(botAI, "baron geddon inferno multiplier") {}
    float GetValue(Action* action) override;
};

class GolemaggDisableDpsAoeMultiplier : public Multiplier
{
public:
    GolemaggDisableDpsAoeMultiplier(PlayerbotAI* botAI) : Multiplier(botAI, "golemagg disable dps aoe multiplier") {}
    float GetValue(Action* action) override;
};

#endif
