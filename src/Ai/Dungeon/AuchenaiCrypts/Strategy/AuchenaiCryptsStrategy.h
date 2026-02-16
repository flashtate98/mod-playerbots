#ifndef _PLAYERBOT_TBCDUNGEONAUCHENAICRYPTSSTRATEGY_H
#define _PLAYERBOT_TBCDUNGEONAUCHENAICRYPTSSTRATEGY_H

#include "AiObjectContext.h"
#include "Strategy.h"

class TbcDungeonAuchenaiCryptsStrategy : public Strategy
{
public:
    TbcDungeonAuchenaiCryptsStrategy(PlayerbotAI* ai) : Strategy(ai) {}
    virtual std::string const getName() override { return "auchenai crypts"; }
    virtual void InitTriggers(std::vector<TriggerNode*> &triggers) override;
    virtual void InitMultipliers(std::vector<Multiplier*> &multipliers) override;
};

#endif