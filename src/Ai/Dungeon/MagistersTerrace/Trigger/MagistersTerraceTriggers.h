#ifndef _PLAYERBOT_TBCMAGISTERSTERRACETRIGGERS_H
#define _PLAYERBOT_TBCMAGISTERSTERRACETRIGGERS_H

#include "Trigger.h"

enum class MagistersTerraceIDs : uint32
{
    // Trash
    MAGIC_DAMPENING_FIELD                  = 44475,
};

// Trash

class MagicDampeningFieldTrigger : public Trigger
{
public:
    MagicDampeningFieldTrigger(
        PlayerbotAI* botAI) : Trigger(botAI, "magic dampening field") {}
    bool IsActive() override;
};

#endif
