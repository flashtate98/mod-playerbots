#include "Playerbots.h"
#include "AuchenaiCryptsTriggers.h"
#include "AiObject.h"
#include "AiObjectContext.h"

bool ShirrakFocusFireTrigger::IsActive()
{
    Unit* boss = AI_VALUE2(Unit*,"find target", "shirrak the dead watcher");
    if (!boss)
        return false;

    Creature* flare = AI_VALUE2(Creature*, "nearest creature with entry", ENTRY_FOCUS_FIRE);
    if (!flare || !flare->IsAlive())
        return false;
    
    if (bot->GetExactDist2d(flare) > 12.0f)
        return false;

    return true;
}