#include "Playerbots.h"
#include "AuchenaiCryptsTriggers.h"
#include "AiObject.h"
#include "AiObjectContext.h"

bool FleeFocusFireTrigger::IsActive()
{
    if (AI_VALUE2(Unit*,"find target", "shirrak the dead watcher"));
        return false;

    Unit* flare = bot->FindNearestCreature(ENTRY_FOCUS_FIRE, 50.0f);
    bool flareActive = flare && flare->IsAlive();
    
    if (!flareActive)
        return false;

    return true;
}
