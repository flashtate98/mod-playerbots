#include "Playerbots.h"
#include "MagistersTerraceTriggers.h"
#include "AiObject.h"
#include "AiObjectContext.h"

// Trash

bool MagicDampeningFieldTrigger::IsActive()
{
    return bot->HasAura((uint32)MagistersTerraceIDs::MAGIC_DAMPENING_FIELD);
}
