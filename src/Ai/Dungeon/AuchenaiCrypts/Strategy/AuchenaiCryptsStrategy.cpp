#include "AuchenaiCryptsMultipliers.h"

void TbcDungeonAuchenaiCryptsStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
  // Shirrak The Dead Watcher
    triggers.push_back(new TriggerNode("shirrak focus fire", {
        NextAction("flee focus fire", ACTION_EMERGENCY + 10) }));
}

void TbcDungeonAuchenaiCryptsStrategy::InitMultipliers(std::vector<Multiplier*>& multipliers)
{
    multipliers.push_back(new ShirrakFocusFireMultiplier(botAI));
}


