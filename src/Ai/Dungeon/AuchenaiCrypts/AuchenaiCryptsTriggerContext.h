#ifndef _PLAYERBOT_TBCDUNGEONAUCHENAICRYPTSTRIGGERCONTEXT_H
#define _PLAYERBOT_TBCDUNGEONAUCHENAICRYPTSTRIGGERCONTEXT_H

#include "TriggerContext.h"
#include "AuchenaiCryptsTriggers.h"

class TbcDungeonAuchenaiCryptsTriggerContext : NamedObjectContext<Trigger>
{
    public:
        TbcDungeonAuchenaiCryptsTriggerContext()
        {
            creators["flee focus fire"] = &TbcDungeonAuchenaiCryptsTriggerContext::flee_focus_fire;
        }
    private:
        static Trigger* flee_focus_fire(PlayerbotAI* botAI) { return new FleeFocusFireTrigger(botAI); }
};

#endif
