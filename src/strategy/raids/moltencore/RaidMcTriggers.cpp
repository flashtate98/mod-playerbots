#include "RaidMcTriggers.h"

#include "SharedDefines.h"
#include "RaidMcHelpers.h"

using namespace MoltenCoreHelpers;

bool McLivingBombDebuffTrigger::IsActive()
{
    // TODO Remove boss check?
    if (AI_VALUE2(Unit*, "find target", "baron geddon"))
        return bot->HasAura(SPELL_LIVING_BOMB);
    return false;
}

bool McBaronGeddonInfernoTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "baron geddon"))
        return boss->HasAura(SPELL_INFERNO);
    return false;
}

bool McShazzrahRangedTrigger::IsActive()
{
    return AI_VALUE2(Unit*, "find target", "shazzrah") && PlayerbotAI::IsRanged(bot);
}
