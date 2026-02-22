#include "AuchenaiCryptsMultipliers.h"
#include "AuchenaiCryptsActions.h"
#include "AuchenaiCryptsTriggers.h"
#include "WipeAction.h"
#include "ReachTargetActions.h"
#include "AIObjectContext.h"
#include "Playerbots.h"


float FleeFocusFireMultiplier::GetValue(Action* action)
{

    Unit* boss = AI_VALUE2(Unit*, "find target", "shirrak");
    if (!boss)
    return 1.0f;

    if (dynamic_cast<WipeAction*>(action))
            return 1.0f;

    if (dynamic_cast<FleeFocusFireAction*>(action))
            return 1.0f;        

    if (dynamic_cast<ReachTargetAction*>(action) &&
            !dynamic_cast<MovementAction*>(action) &&
            !dynamic_cast<CastReachTargetSpellAction*>(action))
            return 0.0f;
    
    return 1.0f;
}

