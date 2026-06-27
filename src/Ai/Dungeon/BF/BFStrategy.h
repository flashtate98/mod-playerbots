/*
* This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
* information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
* or (at your option) any later version.
*/

#ifndef _PLAYERBOT_TBCDUNGEONBLOODFURNACESTRATEGY_H
#define _PLAYERBOT_TBCDUNGEONBLOODFURNACESTRATEGY_H

#include "AiObjectContext.h"
#include "Strategy.h"
#include "Multiplier.h"

class TbcDungeonBloodFurnaceStrategy : public Strategy
{
public:
    TbcDungeonBloodFurnaceStrategy(PlayerbotAI* botAI) : Strategy(botAI) {}

    virtual std::string const getName() override { return "tbc-bf"; }

    virtual void InitTriggers(std::vector<TriggerNode*> &triggers) override;
    virtual void InitMultipliers(std::vector<Multiplier*> &multipliers) override;
};

#endif
