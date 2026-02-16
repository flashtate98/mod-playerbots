#include "MovementActions.h"
#include "AiObject.h"
#include "AuchenaiCryptsMultipliers.h"
#include "AuchenaiCryptsActions.h"
#include "AuchenaiCryptsTriggers.h"
#include "Playerbots.h"

float ShirrakFocusFireMultiplier::GetValue(Action* action)
{
    Unit* boss = AI_VALUE2(Unit*, "find target", "shirrak the dead watcher");
    if (!boss)
        return 1.0f;

    Creature* flare = AI_VALUE2(Creature*, "nearest creature with entry", ENTRY_FOCUS_FIRE);
    if (!flare) { return 1.0f; }

    if (!flare->IsInWorld())
        return 1.0f;
    
    if (flare->IsAlive() && bot->GetExactDist2d(flare) <= 12.0f)
    {
        return 20.0f;
    }
    return 1.0f;
}
