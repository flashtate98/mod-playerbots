#include "Playerbots.h"
#include "AuchenaiCryptsTriggers.h"
#include "AiObject.h"
#include "AiObjectContext.h"

bool FleeFocusFireTrigger::IsActive()
{
    Unit* boss = AI_VALUE2(Unit*, "find target", "shirrak");
    if (!boss) 
        return false;

    if (boss->FindCurrentSpellBySpellId(SPELL_FOCUS_CAST))
        return true;

    return false;

}
