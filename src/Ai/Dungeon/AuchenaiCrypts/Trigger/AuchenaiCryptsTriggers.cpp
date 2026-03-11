#include "Playerbots.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Cell.h"
#include "CellImpl.h"
#include "AuchenaiCryptsTriggers.h"
#include "AiObject.h"
#include "AiObjectContext.h"

bool FleeFocusFireTrigger::IsActive()
{
    Unit* boss = AI_VALUE2(Unit*, "find target", "shirrak the dead watcher");
    if (!boss)
        return false;

   constexpr float searchRadius = 20.0f;
        std::list<Creature*> creatureList;
        bot->GetCreatureListWithEntryInGrid(creatureList, NPC_FOCUS_FIRE, 20.0f);

    for (Creature* flare : creatureList)
    {
        if (flare && flare->IsALive())
            return true;
    }
    return false;
}
