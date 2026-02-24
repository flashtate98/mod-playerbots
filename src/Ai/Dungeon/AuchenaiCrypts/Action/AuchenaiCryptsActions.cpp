#include "Playerbots.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Cell.h"
#include "CellImpl.h"
#include "AuchenaiCryptsTriggers.h"
#include "AuchenaiCryptsActions.h"

// Move away from Shirrak's Focus Fire ability.

bool FleeFocusFireAction::Execute(Event /*event*/)
{
    std::list<Creature*> targets;
    Acore::AnyUnitInObjectRangeCheck u_check(bot, 20.0f);
    Acore::CreatureListSearcher<Acore::AnyUnitInObjectRangeCheck> searcher(bot, targets, u_check);
    Cell::VisitObjects(bot, searcher, 20.0f);

    for (Creature* flare : targets)
    {
        if (flare && flare->GetEntry() == NPC_FOCUS_FIRE)
        {
            float distance = bot->GetDistance2d(flare);
            const float safeDistance = 15.0f; 

            if (distance < safeDistance)
            {
                
                bot->AttackStop();
                bot->InterruptNonMeleeSpells(false);
                
                return FleePosition(flare->GetPosition(), 20.0f);
            }
        }
    }

    return false;
}
