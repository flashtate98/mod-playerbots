#include "RaidMcActions.h"

#include "Playerbots.h"
#include "RaidMcTriggers.h"
#include "RaidMcHelpers.h"

static constexpr float LIVING_BOMB_DISTANCE = 20.0f;
static constexpr float INFERNO_DISTANCE = 20.0f;

// don't get hit by Arcane Explosion but still be in casting range
static constexpr float ARCANE_EXPLOSION_DISTANCE = 26.0f;

using namespace MoltenCoreHelpers;

bool McMoveFromGroupAction::Execute(Event event)
{
    return MoveFromGroup(LIVING_BOMB_DISTANCE);
}

bool McMoveFromBaronGeddonAction::Execute(Event event)
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "baron geddon"))
    {
        float distToTravel = INFERNO_DISTANCE - bot->GetDistance(boss);
        if (distToTravel > 0)
        {
            // Stop current spell first
            bot->AttackStop();
            bot->InterruptNonMeleeSpells(false);

            return MoveAway(boss, distToTravel);
        }
    }
    return false;
}

bool McShazzrahMoveAwayAction::Execute(Event event)
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "shazzrah"))
    {
        float distToTravel = ARCANE_EXPLOSION_DISTANCE - bot->GetDistance(boss);
        if (distToTravel > 0)
            return MoveAway(boss, distToTravel);
    }
    return false;
}
