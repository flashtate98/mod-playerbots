#include "Playerbots.h"
#include "AuchenaiCryptsTriggers.h"
#include "AuchenaiCryptsActions.h"

// Move away from Shirrak's Focus Fire ability.

bool FleeFocusFireAction::Execute(Event /*event*/)
{
    constexpr float searchRadius = 20.0f;
        std::list<Creature*> creatureList;
        bot->GetCreatureListWithEntryInGrid(creatureList, NPC_FOCUS_FIRE, 20.0f);

    for (Creature* flare : creatureList)
    {
        if (flare && flare->IsAlive())
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
