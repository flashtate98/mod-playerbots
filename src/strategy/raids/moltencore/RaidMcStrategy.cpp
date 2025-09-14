#include "RaidMcStrategy.h"

#include "RaidMcMultipliers.h"
#include "Strategy.h"

void RaidMcStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    // Lucifron
    triggers.push_back(
        new TriggerNode("mc lucifron shadow resistance trigger",
                        NextAction::array(0, new NextAction("mc lucifron shadow resistance action", ACTION_RAID), nullptr)));

    // Magmadar
    // TODO: Fear ward / tremor totem, or general anti-fear strat development. Same as King Dred (Drak'Tharon) and faction commander (Nexus).
    triggers.push_back(
        new TriggerNode("mc magmadar fire resistance trigger",
                        NextAction::array(0, new NextAction("mc magmadar fire resistance action", ACTION_RAID), nullptr)));

    // Gehennas
    triggers.push_back(
        new TriggerNode("mc gehennas shadow resistance trigger",
                        NextAction::array(0, new NextAction("mc gehennas shadow resistance action", ACTION_RAID), nullptr)));

    // Garr
    triggers.push_back(
        new TriggerNode("mc garr fire resistance trigger",
                        NextAction::array(0, new NextAction("mc garr fire resistance action", ACTION_RAID), nullptr)));

    // Baron Geddon
    triggers.push_back(
        new TriggerNode("mc baron geddon fire resistance trigger",
                        NextAction::array(0, new NextAction("mc baron geddon fire resistance action", ACTION_RAID), nullptr)));
    triggers.push_back(
        new TriggerNode("mc living bomb debuff",
                        NextAction::array(0, new NextAction("mc check should move from group", ACTION_RAID), nullptr)));
    triggers.push_back(
        new TriggerNode("mc baron geddon inferno",
                        NextAction::array(0, new NextAction("mc move from baron geddon", ACTION_RAID), nullptr)));

    // Shazzrah
    triggers.push_back(
        new TriggerNode("mc shazzrah ranged",
                        NextAction::array(0, new NextAction("mc shazzrah move away", ACTION_RAID), nullptr)));

    // Sulfuron Harbinger
    // Alternatively, shadow resistance is also possible.
    triggers.push_back(
        new TriggerNode("mc sulfuron harbinger fire resistance trigger",
                        NextAction::array(0, new NextAction("mc sulfuron harbinger fire resistance action", ACTION_RAID), nullptr)));

    // Golemagg the Incinerator
    triggers.push_back(
        new TriggerNode("mc golemagg fire resistance trigger",
                        NextAction::array(0, new NextAction("mc golemagg fire resistance action", ACTION_RAID), nullptr)));

    // Majordomo Executus
    triggers.push_back(
        new TriggerNode("mc majordomo shadow resistance trigger",
                        NextAction::array(0, new NextAction("mc majordomo shadow resistance action", ACTION_RAID), nullptr)));

    // Ragnaros
    triggers.push_back(
        new TriggerNode("mc ragnaros fire resistance trigger",
                        NextAction::array(0, new NextAction("mc ragnaros fire resistance action", ACTION_RAID), nullptr)));
}

void RaidMcStrategy::InitMultipliers(std::vector<Multiplier*>& multipliers)
{
    multipliers.push_back(new GarrDisableDpsAoeMultiplier(botAI));
    multipliers.push_back(new BaronGeddonInfernoMultiplier(botAI));
    multipliers.push_back(new GolemaggDisableDpsAoeMultiplier(botAI));
}
