#ifndef _PLAYERBOT_RAIDMCTRIGGERCONTEXT_H
#define _PLAYERBOT_RAIDMCTRIGGERCONTEXT_H

#include "AiObjectContext.h"
#include "NamedObjectContext.h"
#include "RaidMcTriggers.h"

class RaidMcTriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidMcTriggerContext()
    {
        creators["mc lucifron shadow resistance trigger"] = &RaidMcTriggerContext::lucifron_shadow_resistance_trigger;
        creators["mc magmadar fire resistance trigger"] = &RaidMcTriggerContext::magmadar_fire_resistance_trigger;
        creators["mc gehennas shadow resistance trigger"] = &RaidMcTriggerContext::gehennas_shadow_resistance_trigger;
        creators["mc garr fire resistance trigger"] = &RaidMcTriggerContext::garr_fire_resistance_trigger;
        creators["mc baron geddon fire resistance trigger"] = &RaidMcTriggerContext::baron_geddon_fire_resistance_trigger;
        creators["mc living bomb debuff"] = &RaidMcTriggerContext::living_bomb_debuff;
        creators["mc baron geddon inferno"] = &RaidMcTriggerContext::baron_geddon_inferno;
        creators["mc shazzrah ranged"] = &RaidMcTriggerContext::shazzrah_ranged;
        creators["mc sulfuron harbinger fire resistance trigger"] = &RaidMcTriggerContext::sulfuron_harbinger_fire_resistance_trigger;
        creators["mc golemagg fire resistance trigger"] = &RaidMcTriggerContext::golemagg_fire_resistance_trigger;
        creators["mc majordomo shadow resistance trigger"] = &RaidMcTriggerContext::majordomo_shadow_resistance_trigger;
        creators["mc ragnaros fire resistance trigger"] = &RaidMcTriggerContext::ragnaros_fire_resistance_trigger;
    }

private:
    static Trigger* lucifron_shadow_resistance_trigger(PlayerbotAI* ai) { return new BossShadowResistanceTrigger(ai, "lucifron"); }
    static Trigger* magmadar_fire_resistance_trigger(PlayerbotAI* ai) { return new BossFireResistanceTrigger(ai, "magmadar"); }
    static Trigger* gehennas_shadow_resistance_trigger(PlayerbotAI* ai) { return new BossShadowResistanceTrigger(ai, "gehennas"); }
    static Trigger* garr_fire_resistance_trigger(PlayerbotAI* ai) { return new BossFireResistanceTrigger(ai, "garr"); }
    static Trigger* baron_geddon_fire_resistance_trigger(PlayerbotAI* ai) { return new BossFireResistanceTrigger(ai, "baron geddon"); }
    static Trigger* living_bomb_debuff(PlayerbotAI* ai) { return new McLivingBombDebuffTrigger(ai); }
    static Trigger* baron_geddon_inferno(PlayerbotAI* ai) { return new McBaronGeddonInfernoTrigger(ai); }
    static Trigger* shazzrah_ranged(PlayerbotAI* ai) { return new McShazzrahRangedTrigger(ai); }
    static Trigger* sulfuron_harbinger_fire_resistance_trigger(PlayerbotAI* ai) { return new BossFireResistanceTrigger(ai, "sulfuron harbinger"); }
    static Trigger* golemagg_fire_resistance_trigger(PlayerbotAI* ai) { return new BossFireResistanceTrigger(ai, "golemagg the incinerator"); }
    static Trigger* majordomo_shadow_resistance_trigger(PlayerbotAI* ai) { return new BossShadowResistanceTrigger(ai, "majordomo executus"); }
    static Trigger* ragnaros_fire_resistance_trigger(PlayerbotAI* ai) { return new BossFireResistanceTrigger(ai, "ragnaros"); }
};

#endif
