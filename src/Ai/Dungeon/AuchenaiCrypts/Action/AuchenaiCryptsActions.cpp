#include "Playerbots.h"
#include "AuchenaiCryptsTriggers.h"
#include "AuchenaiCryptsActions.h"
#include "AuchenaiCryptsStrategy.h"

// Move away from Shirrak's Focus Fire ability.

bool ShirrakFocusFireAction::Execute(Event /*event*/)
{
    Creature* flare = AI_VALUE2(Creature*, "nearest creature with entry", ENTRY_FOCUS_FIRE);
    if (!flare || !flare->IsAlive())
        return false;

    float dangerRadius = 12.0f;
    float buffer = 3.0f;

    float dist = bot->GetExactDist2d(flare);
    if (dist > dangerRadius)
        return false;

    float dx = bot->GetPositionX() - flare->GetPositionX();
    float dy = bot->GetPositionY() - flare->GetPositionY();

    if (dist <= 0.001f)
        return false;

    float safeDist = dangerRadius + buffer;
    float invDist = 1.0f / dist;

    float moveX = flare->GetPositionX() + (dx * invDist) * safeDist;
    float moveY = flare->GetPositionY() + (dy * invDist) * safeDist;

    botAI->Reset();

    return MoveTo(static_cast<uint32>(flare->GetMapId()), moveX, moveY, bot->GetPositionZ(),
              false, false, false, true,
              MovementPriority::MOVEMENT_FORCED);
}
