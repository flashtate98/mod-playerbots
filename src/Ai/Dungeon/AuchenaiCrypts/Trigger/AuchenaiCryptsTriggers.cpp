#include "Playerbots.h"
#include "Trigger.h"
#include "AuchenaiCryptsTriggers.h"
#include "AiObject.h"
#include "AiObjectContext.h"

bool FleeFocusFireTrigger::IsActive()
{
    Unit* flare = AI_VALUE2(Unit*, "find target", "focus fire");
    bool flareActive = flare && flare->IsAlive();
    
    if (!flareActive)
        return false;

    return true;
}
