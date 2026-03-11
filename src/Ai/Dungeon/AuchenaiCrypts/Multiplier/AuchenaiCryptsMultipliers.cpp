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
   constexpr float searchRadius = 20.0f;
        std::list<Creature*> creatureList;
        bot->GetCreatureListWithEntryInGrid(creatureList, NPC_FOCUS_FIRE, 20.0f);

    for (Creature* flare : creatureList)
    {
        if (flare && flare->IsALive())
            return 1.0f;
    }
    
    if (dynamic_cast<CastReachTargetSpellAction*>(action) ||
        dynamic_cast<CastKillingSpreeAction*>(action) ||
        dynamic_cast<ReachTargetAction*>(action) ||
        dynamic_cast<AttackAction*>(action))
        return 0.0f;

    return 1.0f;
}
