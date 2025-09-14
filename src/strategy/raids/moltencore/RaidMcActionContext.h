#ifndef _PLAYERBOT_RAIDMCACTIONCONTEXT_H
#define _PLAYERBOT_RAIDMCACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "RaidMcActions.h"

class RaidMcActionContext : public NamedObjectContext<Action>
{
public:
    RaidMcActionContext()
    {
        creators["mc lucifron shadow resistance action"] = &RaidMcActionContext::lucifron_shadow_resistance_action;
        creators["mc magmadar fire resistance action"] = &RaidMcActionContext::magmadar_fire_resistance_action;
        creators["mc gehennas shadow resistance action"] = &RaidMcActionContext::gehennas_shadow_resistance_action;
        creators["mc garr fire resistance action"] = &RaidMcActionContext::garr_fire_resistance_action;
        creators["mc baron geddon fire resistance action"] = &RaidMcActionContext::baron_geddon_fire_resistance_action;
        creators["mc check should move from group"] = &RaidMcActionContext::check_should_move_from_group;
        creators["mc move from baron geddon"] = &RaidMcActionContext::move_from_baron_geddon;
        creators["mc shazzrah move away"] = &RaidMcActionContext::shazzrah_move_away;
        creators["mc sulfuron harbinger fire resistance action"] = &RaidMcActionContext::sulfuron_harbinger_fire_resistance_action;
        creators["mc golemagg fire resistance action"] = &RaidMcActionContext::golemagg_fire_resistance_action;
        creators["mc majordomo shadow resistance action"] = &RaidMcActionContext::majordomo_shadow_resistance_action;
        creators["mc ragnaros fire resistance action"] = &RaidMcActionContext::ragnaros_fire_resistance_action;
    }

private:
    static Action* lucifron_shadow_resistance_action(PlayerbotAI* ai) { return new BossShadowResistanceAction(ai, "lucifron"); }
    static Action* magmadar_fire_resistance_action(PlayerbotAI* ai) { return new BossFireResistanceAction(ai, "magmadar"); }
    static Action* gehennas_shadow_resistance_action(PlayerbotAI* ai) { return new BossShadowResistanceAction(ai, "gehennas"); }
    static Action* garr_fire_resistance_action(PlayerbotAI* ai) { return new BossFireResistanceAction(ai, "garr"); }
    static Action* baron_geddon_fire_resistance_action(PlayerbotAI* ai) { return new BossFireResistanceAction(ai, "baron geddon"); }
    static Action* check_should_move_from_group(PlayerbotAI* ai) { return new McCheckShouldMoveFromGroupAction(ai); }
    static Action* move_from_baron_geddon(PlayerbotAI* ai) { return new McMoveFromBaronGeddonAction(ai); }
    static Action* shazzrah_move_away(PlayerbotAI* ai) { return new McShazzrahMoveAwayAction(ai); }
    static Action* sulfuron_harbinger_fire_resistance_action(PlayerbotAI* ai) { return new BossFireResistanceAction(ai, "sulfuron harbinger"); }
    static Action* golemagg_fire_resistance_action(PlayerbotAI* ai) { return new BossFireResistanceAction(ai, "golemagg the incinerator"); }
    static Action* majordomo_shadow_resistance_action(PlayerbotAI* ai) { return new BossShadowResistanceAction(ai, "majordomo executus"); }
    static Action* ragnaros_fire_resistance_action(PlayerbotAI* ai) { return new BossFireResistanceAction(ai, "ragnaros"); }
};

#endif
