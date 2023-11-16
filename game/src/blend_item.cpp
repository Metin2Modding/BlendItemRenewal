#include "stdafx.h"
#include "constants.h"
#include "blend_item.h"
#include "locale_service.h"

#include <fstream>
#include <nlohmann/json.hpp>

nlohmann::json container;

bool Blend_Item_init()
{
	try
	{
		container = nlohmann::json::parse(std::ifstream(LocaleService_GetBasePath() + "/blend.json"), nullptr, true, true);
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
#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 202004L) || __cplusplus >= 202004L)
	return container.contains(std::to_string(item));
#else
	return container.find(std::to_string(item)) != container.end();
#endif
}

void Blend_Item_set_value(const LPITEM item)
{
	if (!item)
		return;

	const auto& result = container.find(std::to_string(item->GetVnum())).value();

	const auto& type = result.at("type");
	item->SetSocket(0, type.is_number() ? type.get<int32_t>() : FN_get_apply_type(type.get<std::string>().c_str()));

	const auto& value = result.at("value");
	item->SetSocket(1, !value.is_array() ? value.at(0) : value.at(number(0, value.size() - 1)));

	const auto& duration = result.at("duration");
	item->SetSocket(2, !duration.is_array() ? duration.at(0) : duration.at(number(0, duration.size() - 1)));
}
