#include "Playerbots.h"
#include "DynamicObject.h"
#include "AuchenaiCryptsTriggers.h"
#include "AuchenaiCryptsActions.h"

// Move away from Shirrak's Focus Fire ability.

bool FleeFocusFireAction::Execute(Event /*event*/)
{
    Unit* boss = AI_VALUE2(Unit*, "find target", "shirrak");
    if (!boss)
        return false;

    std::list<ObjectGuid> objects = AI_VALUE(std::list<ObjectGuid>, "nearest dynamic objects");
    for (auto const& guid : objects)
    {
        DynamicObject* obj = bot->GetMap()->GetDynamicObject(guid);
        if (obj && obj->GetSpellId() == 32286) // SPELL_FOCUS_FIRE_VISUAL
        {
            float radius = obj->GetRadius();
            if (bot->GetDistance2d(obj) <= (radius + 2.0f))
            {
            bot->InterruptNonMeleeSpells(false);
            return FleePosition(obj->GetPosition(), 20.0f, 3000U);
            }
        }
    }
    return false;
}
