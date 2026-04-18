#include "MagistersTerraceMultipliers.h"
#include "MagistersTerraceActions.h"
#include "MagistersTerraceTriggers.h"
#include "MovementActions.h"
#include "ReachTargetActions.h"
#include "FollowActions.h"
#include "AiObjectContext.h"
#include "Playerbots.h"

// Trash

class AvoidMagicDampeningFieldMultiplier::GetValue(Action* action)
{
    if (bot->HasAura((uint32)MagistersTerraceIDs::MAGIC_DAMPENING_FIELD) &&
        dynamic_cast<MovementAction*>(action) &&
        !dynamic_cast<AvoidMagicDampeningFieldAction*>(action))
        return 0.0f;

    return 1.0f;
}