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

    DynamicObject* dynObj = aura->GetDynobjOwner();
    if (!dynObj)
        return false;

    float radius = dynObj->GetRadius();
    const SpellInfo* sInfo = sSpellMgr->GetSpellInfo(dynObj->GetSpellId());
    if (radius <= 0.0f && sInfo)
    {
        for (int e = 0; e < MAX_SPELL_EFFECTS; ++e)
        {
            auto const& eff = sInfo->Effects[e];
            if (eff.Effect == SPELL_EFFECT_SCHOOL_DAMAGE ||
                eff.Effect == SPELL_EFFECT_APPLY_AURA)
            {
                radius = eff.CalcRadius();
                break;
            }
        }
    }

    if (radius <= 0.0f)
        return false;

    constexpr float bufferDist = 2.0f;
    float distToObj = bot->GetExactDist2d(dynObj->GetPositionX(), dynObj->GetPositionY());

    float dx = bot->GetPositionX() - dynObj->GetPositionX();
    float dy = bot->GetPositionY() - dynObj->GetPositionY();
    float safeDist = radius + bufferDist;

    float invDist = 1.0f / distToObj;
    float moveX = dynObj->GetPositionX() + (dx * invDist) * safeDist;
    float moveY = dynObj->GetPositionY() + (dy * invDist) * safeDist;

    botAI->Reset();
    return MoveTo(bot->GetMapId(), moveX, moveY, bot->GetPositionZ(), false, false, false,
                  true, MovementPriority::MOVEMENT_FORCED, true, false);
}
