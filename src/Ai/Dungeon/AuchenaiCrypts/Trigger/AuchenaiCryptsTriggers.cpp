#include "Playerbots.h"
#include "AuchenaiCryptsTriggers.h"
#include "AiObject.h"
#include "AiObjectContext.h"

bool ShirrakFocusFireTrigger::IsActive()
{
    if (AI_VALUE2(Unit*,"find target", "shirrak the dead watcher"));
        return false;

    Unit* flare = AI_VALUE2(Unit*, "nearest creature with entry", ENTRY_FOCUS_FIRE);
    if (!flare || !flare->IsAlive())
        return false;

    return true;
}
