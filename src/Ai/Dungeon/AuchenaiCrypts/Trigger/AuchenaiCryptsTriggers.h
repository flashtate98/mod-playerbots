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

class ShirrakFocusFireTrigger : public Trigger
{
public:
    ShirrakFocusFireTrigger(PlayerbotAI* ai) : Trigger(ai, "shirrak focus fire") {}

    bool IsActive() override;
};

#endif