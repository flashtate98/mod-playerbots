#include "RaidMcActions.h"

#include "Playerbots.h"
#include "RaidMcTriggers.h"
#include "RaidMcHelpers.h"

static constexpr float INFERNO_DISTANCE = 20.0f;

// don't get hit by Arcane Explosion but still be in casting range
static constexpr float ARCANE_EXPLOSION_DISTANCE = 26.0f;

using namespace MoltenCoreHelpers;

bool McCheckShouldMoveFromGroupAction::Execute(Event event)
{
    if (bot->HasAura(SPELL_LIVING_BOMB)) // baron geddon's living bomb
    {
        if (!botAI->HasStrategy("move from group", BOT_STATE_COMBAT))
        {
            // add/remove from both for now as it will make it more obvious to
            // player if this strat remains on after fight somehow
            botAI->ChangeStrategy("+move from group", BOT_STATE_NON_COMBAT);
            botAI->ChangeStrategy("+move from group", BOT_STATE_COMBAT);
            return true;
        }
    }
    else if (botAI->HasStrategy("move from group", BOT_STATE_COMBAT))
    {
        // add/remove from both for now as it will make it more obvious to
        // player if this strat remains on after fight somehow
        botAI->ChangeStrategy("-move from group", BOT_STATE_NON_COMBAT);
        botAI->ChangeStrategy("-move from group", BOT_STATE_COMBAT);
        return true;
    }
    return false;
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
