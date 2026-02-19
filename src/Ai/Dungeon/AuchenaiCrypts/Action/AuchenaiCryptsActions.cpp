#include "Playerbots.h"
#include "AuchenaiCryptsTriggers.h"
#include "AuchenaiCryptsActions.h"

// Move away from Shirrak's Focus Fire ability.

bool ShirrakFocusFireAction::Execute(Event /*event*/)
{
    Unit* flare = AI_VALUE2(Unit*, "nearest creature with entry", ENTRY_FOCUS_FIRE);
    if (!flare || !flare->IsAlive())
        return false;

    constexpr float dangerRadius = 12.0f;
    constexpr float buffer = 3.0f;

    float dist = bot->GetDistance2d(flare);
    if (dist > dangerRadius)
        return false;

    float dx = bot->GetPositionX() - flare->GetPositionX();
    float dy = bot->GetPositionY() - flare->GetPositionY();

    float safeDist = dangerRadius + buffer;

    float moveX = flare->GetPositionX() + dx / dist * safeDist;
    float moveY = flare->GetPositionY() + dy / dist * safeDist;

    botAI->Reset();

    return MoveTo(bot->GetMapId(), moveX, moveY, bot->GetPositionZ(), false, false, 
            false, true, MovementPriority::MOVEMENT_FORCED, true, false);
}
