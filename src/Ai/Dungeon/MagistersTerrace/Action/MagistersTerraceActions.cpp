#include "Playerbots.h"
#include "AiFactory.h"
#include "MagistersTerraceTriggers.h"
#include "MagistersTerraceActions.h"

// Trash

// Bots will avoid Magic Dampening Fields
bool AvoidMagicDampeningFieldAction::Execute(Event /*event*/)
{
    Aura* aura = bot->GetAura((uint32)MagistersTerraceIDs::MAGIC_DAMPENING_FIELD);
    if (!aura)
        return false;

    DynamicObject* bubble = aura->GetDynobjOwner();
    if (!bubble)
        return false;

    constexpr float safeDistFromBubble = 7.0f;

    if (bot->GetExactDist2d(bubble) < safeDistFromBubble)
    {
        botAI->Reset();
        return FleePosition (bubble->GetPosition(), safeDistFromBubble);
    }

    return false;
}
