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

    std::list<Creature*> targets;
    Acore::AnyUnitInObjectRangeCheck u_check(bot, 20.0f);
    Acore::CreatureListSearcher<Acore::AnyUnitInObjectRangeCheck> searcher(bot, targets, u_check);
    Cell::VisitObjects(bot, searcher, 20.0f);

    for (Creature* creature : targets)
    {
        if (creature && creature->GetEntry() == NPC_FOCUS_FIRE) // Focus Fire NPC ID
            return true;
    
    }
    return false;
}
