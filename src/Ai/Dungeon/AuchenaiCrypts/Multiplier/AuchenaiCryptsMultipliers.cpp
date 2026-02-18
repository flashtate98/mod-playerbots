#include "AuchenaiCryptsMultipliers.h"
#include "WipeAction.h"
#include "ReachTargetActions.h"


float ShirrakFocusFireMultiplier::GetValue(Action* action)
{
    Creature* flare = AI_VALUE2(Creature*, "nearest creature with entry", ENTRY_FOCUS_FIRE);
    if (!flare || !flare->IsAlive())
        return 1.0f;
    
    float dist = bot->GetDistance2d(flare);

    constexpr float dangerRadius = 12.0f;

    if (dist >= dangerRadius)
    {
         if (dynamic_cast<WipeAction*>(action))
                return 1.0f;
        
        if action->GetName() == "flee focus fire")
                return 1.0f;

         if (dynamic_cast<ReachTargetAction*>(action)&&
            dynamic_cast<MovementAction*>(action) &&
            dynamic_cast<AttackAction*>(action) &&
            dynamic_cast<ReachTargetSpellAction*>(action))
            return 0.0f;
    }
    
    return 1.0f;
}

