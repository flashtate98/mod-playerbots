/*
* This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
* information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
* or (at your option) any later version.
*/

#include "BFTriggers.h"
#include "BFStrategy.h"

void TbcDungeonBloodFurnaceStrategy::InitTriggers(std::vector<TriggerNode*> &triggers)
{
    // Trash
    triggers.push_back(new TriggerNode("shadowmoon technician mines detected", {
        NextAction("shadowmoon technician avoid mines", ACTION_RAID + 1)}));

    // Keli'dan the Breaker
    triggers.push_back(new TriggerNode("kelidan casting burning nova", {
        NextAction("kelidan flee burning nova", ACTION_EMERGENCY + 1)}));
}
