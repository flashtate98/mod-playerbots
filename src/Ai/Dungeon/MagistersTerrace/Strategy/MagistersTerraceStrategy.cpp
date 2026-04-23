#include "MagistersTerraceTriggers.h"
#include "MagistersTerraceStrategy.h"
#include "MagistersTerraceMultipliers.h"

void TbcDungeonMagistersTerraceStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    // Trash
    triggers.push_back(new TriggerNode("magic dampening field", {
        NextAction("avoid magic dampening field", ACTION_EMERGENCY + 10) }));
}

void TbcDungeonMagistersTerraceStrategy::InitMultipliers(std::vector<Multiplier*>& multipliers)
{
    multipliers.push_back(new AvoidMagicDampeningFieldMultiplier(botAI));
}
