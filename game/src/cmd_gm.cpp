// Add:
#include "blend_item.h"

// Find:
			case 'c':	// cube

				Cube_init ();
				break;

// Paste (under):
			case 'b':
				{
					if (Blend_Item_init())
						ch->ChatPacket(CHAT_TYPE_INFO, "Blend items reloaded.");
					else
						ch->ChatPacket(CHAT_TYPE_INFO, "Something went wrong while loading blend items, check syserr.txt!");
				}
				break;
