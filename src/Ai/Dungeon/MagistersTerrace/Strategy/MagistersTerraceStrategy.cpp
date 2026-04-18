#include "MagistersTerraceTriggers.h"
#include "MagistersTerraceStrategy.h"
#include "MagistersTerraceMultipliers.h"

void TbcDungeonMagistersTerraceStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    // Trash
    triggers.push_back(new TriggerNode("magic dampening field", {
        NextAction("avoid magic dampening field", ACTION_EMERGENCY + 10) }));
}
