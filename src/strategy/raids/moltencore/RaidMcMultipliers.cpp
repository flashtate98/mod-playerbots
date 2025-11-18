#include "RaidMcMultipliers.h"

#include "Playerbots.h"
#include "ChooseTargetActions.h"
#include "GenericSpellActions.h"
#include "DruidActions.h"
#include "HunterActions.h"
#include "PaladinActions.h"
#include "ShamanActions.h"
#include "WarriorActions.h"
#include "DKActions.h"
#include "RaidMcActions.h"
#include "RaidMcHelpers.h"

using namespace MoltenCoreHelpers;

static bool IsDpsBotWithAoeAction(Player* bot, Action* action)
{
    if (PlayerbotAI::IsDps(bot))
    {
        if (dynamic_cast<DpsAoeAction*>(action) || dynamic_cast<CastConsecrationAction*>(action) ||
                    dynamic_cast<CastStarfallAction*>(action) || dynamic_cast<CastWhirlwindAction*>(action) ||
                    dynamic_cast<CastMagmaTotemAction*>(action) || dynamic_cast<CastExplosiveTrapAction*>(action) ||
                    dynamic_cast<CastDeathAndDecayAction*>(action))
            return true;

        if (auto castSpellAction = dynamic_cast<CastSpellAction*>(action))
            if (castSpellAction->getThreatType() == Action::ActionThreatType::Aoe)
                return true;
    }
    return false;
}

float GarrDisableDpsAoeMultiplier::GetValue(Action* action)
{
    if (AI_VALUE2(Unit*, "find target", "garr"))
    {
        if (IsDpsBotWithAoeAction(bot, action))
            return 0.0f;
    }
    return 1.0f;
}

float BaronGeddonInfernoMultiplier::GetValue(Action* action)
{
    Unit* boss = AI_VALUE2(Unit*, "find target", "baron geddon");
    if (boss && boss->HasAura(SPELL_INFERNO))
    {
        if (dynamic_cast<MovementAction*>(action) &&
            !dynamic_cast<McMoveFromGroupAction*>(action) &&
            !dynamic_cast<McMoveFromBaronGeddonAction*>(action))
            return 0.0f;

        if (dynamic_cast<CastReachTargetSpellAction*>(action))
            return 0.0f;
    }
    return 1.0f;
}

float GolemaggDisableDpsAoeMultiplier::GetValue(Action* action)
{
    if (AI_VALUE2(Unit*, "find target", "golemagg the incinerator"))
    {
        if (IsDpsBotWithAoeAction(bot, action))
            return 0.0f;
    }
    return 1.0f;
}
