# BlendItemRenewal
Completely new and fresh approach to load blend items using [JSON](https://www.json.org/json-en.html).

# Better than previous versions?
I suppose so. The source file for this version has only about 50 lines so it is very slim.

I have decided to adhere to the YMIR coding style, so there are no classes or structures.

# So - how to install this „system”?
* Make sure the compiler you are using supports (at least) C++11.
  * Install [JSON](https://github.com/nlohmann/json) parser.
    * Replace `blend_item.h` and `blend_item.cpp` with the old ones, and that is it.
      * If you want hot-reloading the JSON file, you can add the `cmd_gm.cpp` part (recommended).

# Example `blend.json` file content below.
```
{
	"50821": {
		"type": "CRITICAL_PCT",
		"value": [ 8, 10, 12, 15, 20 ],
		"duration": [ 60, 120, 180, 300, 600 ]
	},

	"50822": {
		"type": "PENETRATE_PCT",
		"value": [ 8, 10, 12, 15, 20 ],
		"duration": [ 60, 120, 180, 300, 600 ]
	},

	"50823": {
		"type": "ATTACK_SPEED",
		"value": [ 2, 3, 4, 5, 8 ],
		"duration": [ 60, 120, 180, 300, 600 ]
	},

	"50824": {
		"type": "RESIST_MAGIC",
		"value": [ 8, 10, 12, 15, 20 ],
		"duration": [ 60, 120, 180, 300, 600 ]
	},

	"50825": {
		"type": "ATT_BONUS",
		"value": [ 30, 50, 70, 90, 120 ],
		"duration": [ 60, 120, 180, 300, 600 ]
	},

	"50826": {
		"type": "DEF_BONUS",
		"value": [ 40, 70, 100, 150, 200 ],
		"duration": [ 60, 120, 180, 300, 600 ]
	},

	"51002": {
		"type": "ENERGY",
		"value": [ 1, 3, 5, 7, 10 ],
		"duration": 1800 // It is possible to use only one duration (and value).
	}
}
```
