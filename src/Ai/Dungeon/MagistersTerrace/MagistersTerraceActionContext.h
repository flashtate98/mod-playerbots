#ifndef _PLAYERBOT_TBCDUNGEONMAGISTERSTERRACEACTIONCONTEXT_H
#define _PLAYERBOT_TBCDUNGEONMAGISTERSTERRACEACTIONCONTEXT_H

#include "AiObjectContext.h"
#include "Action.h"
#include "MagistersTerraceActions.h"

class TbcDungeonMagistersTerraceActionContext : public NamedObjectContext<Action>
{
public:
    TbcDungeonMagistersTerraceActionContext() : NamedObjectContext<Action>(false, true)
    {
        // Trash
        creators["avoid magic dampening field"] =
            &TbcDungeonMagistersTerraceContext::avoid_magic_dampening_field;
    }
private:
    // Trash
    static Action* avoid_magic_dampening_field(
        PlayerbotAI* botAI) { return new AvoidMagicDampeningFieldAction(botAI); }
};

#endif
