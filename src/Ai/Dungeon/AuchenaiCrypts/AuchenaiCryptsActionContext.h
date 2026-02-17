#ifndef _PLAYERBOT_TBCDUNGEONAUCHENAICRYPTSACTIONSCONTEXT_H
#define _PLAYERBOT_TBCDUNGEONAUCHENAICRYPTSACTIONSCONTEXT_H

#include "Action.h"
#include "AuchenaiCryptsActions.h"

class TbcDungeonAuchenaiCryptsActionContext : public NamedObjectContext<Action>
{
    public:
        TbcDungeonAuchenaiCryptsActionContext() : NamedObjectContext<Action>(false, true)
        {
            creators["flee focus fire"] = &TbcDungeonAuchenaiCryptsActionContext::flee_focus_fire;
        }
    private:
        static Action* flee_focus_fire(PlayerbotAI* botAI) {return new ShirrakFocusFireAction(botAI); }
};

#endif
