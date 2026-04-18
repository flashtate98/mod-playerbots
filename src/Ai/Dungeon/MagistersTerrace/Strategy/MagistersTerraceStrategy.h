#ifndef _PLAYERBOT_TBCDUNGEONMAGISTERSTERRACESTRATEGY_H
#define _PLAYERBOT_TBCDUNGEONMAGISTERSTERRACESTRATEGY_H

#include "AiObjectContext.h"
#include "Strategy.h"
#include "Multiplier.h"

class TbcDungeonMagistersTerraceStrategy : public Strategy
{
public:
    TbcDungeonMagistersTerraceStrategy(PlayerbotAI* botAI) : Strategy(botAI) {}

    virtual std::string const getName() override { return "tbc-mgt"; }

    virtual void InitTriggers(std::vector<TriggerNode*> &triggers) override;
    virtual void InitMultipliers(std::vector<Multiplier*> &multipliers) override;
};

#endif
