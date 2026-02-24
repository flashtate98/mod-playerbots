#include "AuchenaiCryptsMultipliers.h"
#include "AuchenaiCryptsActions.h"
#include "AuchenaiCryptsTriggers.h"
#include "WipeAction.h"
#include "MovementActions.h"
#include "AttackAction.h"
#include "ReachTargetActions.h"
#include "AIObjectContext.h"
#include "Playerbots.h"


float FleeFocusFireMultiplier::GetValue(Action* action)
{
   Unit* boss = AI_VALUE2(Unit*, "find target", "shirrak the dead watcher");
    if (!boss)
        return 1.0f;

    // gotta figure out how to do this mutiplier without constantly doing creature searches in every function, if even possible.
}
