#include "stdafx.h"
#include "constants.h"
#include "blend_item.h"
#include "locale_service.h"

#include <fstream>

nlohmann::json json_blend;

bool Blend_Item_init()
{
	try
	{
		json_blend = nlohmann::json::parse(std::ifstream(LocaleService_GetBasePath() + "/blend.json"), nullptr, true, true);
		return true;
	}
	catch (const nlohmann::json::parse_error& message)
	{
		sys_err("%s", message.what());
		return false;
	}
}

bool Blend_Item_find(const uint32_t item)
{
	return json_blend.contains(std::to_string(item));
}

int32_t Blend_Item_verify(const nlohmann::json& item, const bool can_string)
{
	if (item.is_number())
		return item.get<int32_t>();

	return can_string ? FN_get_apply_type(item.get<std::string>().c_str()) : item.at(number(0, item.size() - 1)).get<int32_t>();
}

void Blend_Item_set_value(const LPITEM item)
{
	if (!item)
		return;

	try
	{
		const auto& find = json_blend.find(std::to_string(item->GetVnum())).value();
		item->SetSocket(0, Blend_Item_verify(find.at("type"), true));
		item->SetSocket(1, Blend_Item_verify(find.at("value"), false));
		item->SetSocket(2, Blend_Item_verify(find.at("duration"), false));
	}
	catch (const nlohmann::json::exception& message)
	{
		sys_err("%s", message.what());
	}
}
