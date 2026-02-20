#ifndef _PLAYERBOT_TBCDUNGEONAUCHENAICRYPTSTRIGGERS_H
#define _PLAYERBOT_TBCDUNGEONAUCHENAICRYPTSTRIGGERS_H

#include "Trigger.h"
#include "PlayerbotAIConfig.h"
#include "GenericTriggers.h"
#include "DungeonStrategyUtils.h"

enum AuchenaiCryptsIDs
{
    // Shirrak The Dead Watcher
    ENTRY_FOCUS_FIRE                  = 18374,
};

class FleeFocusFireTrigger : public Trigger
{
public:
    FleeFocusFireTrigger(PlayerbotAI* botAI) : Trigger(botAI, "flee focus fire") {}

    bool IsActive() override;
};

#endif
