#ifndef _PLAYERBOT_TBCDUNGEONMAGISTERSTERRACECONTEXT_H
#define _PLAYERBOT_TBCDUNGEONMAGISTERSTERRACETRIGGERCONTEXT_H

#include "AiObjectContext.h"
#include "TriggerContext.h"
#include "MagistersTerraceTriggers.h"

class TbcDungeonMagistersTerraceTriggerContext : public NamedObjectContext<Trigger>
{
public:
    TbcDungeonMagistersTerraceTriggerContext()
    {
        //Trash
        creators["magic dampening field"] =
            &TbcDungeonMagistersTerraceTriggerContext::magic_dampening_field;
    }
private:
    // Trash
    static Trigger* magic_dampening_field(
        PlayerbotAI* botAI) { return new MagicDampeningFieldTrigger(botAI); }
};

#endif
