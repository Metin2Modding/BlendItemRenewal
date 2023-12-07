#include "stdafx.h"
#include "constants.h"
#include "blend_item.h"
#include "locale_service.h"

#include <fstream>
#include <nlohmann/json.hpp>

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
	return json_blend.find(std::to_string(item)) != json_blend.end();
}

void Blend_Item_set_value(const LPITEM item)
{
	if (!item)
		return;

	try
	{
		const auto& find = json_blend.find(std::to_string(item->GetVnum())).value();
		const auto& type = find.at("type");
		const auto& value = find.at("value");
		const auto& duration = find.at("duration");

		item->SetSocket(0, type.is_number() ? type.get<int32_t>() : FN_get_apply_type(type.get<std::string>().c_str()));
		item->SetSocket(1, value.is_number() ? value.get<int32_t>() : value.at(number(0, value.size() - 1)));
		item->SetSocket(2, duration.is_number() ? duration.get<int32_t>() : duration.at(number(0, duration.size() - 1)));
	}
	catch (const nlohmann::json::exception& message)
	{
		sys_err("%s", message.what());
	}
}
