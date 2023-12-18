#pragma once

#include "item.h"

#include <cstdint>
#include <nlohmann/json.hpp>

bool Blend_Item_init();
bool Blend_Item_find(uint32_t item);
int32_t Blend_Item_verify(const nlohmann::json& item, bool can_string);
void Blend_Item_set_value(LPITEM item);
