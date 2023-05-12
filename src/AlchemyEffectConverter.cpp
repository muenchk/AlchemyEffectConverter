
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>

#include "AlchemyEffect.h"

static std::string ToString(AlchemicEffect ae)
{
	if (ae.IsEffect()) {
		switch (ae.AlchemyBaseEffectSecond()) {
		case AlchemyBaseEffectSecond::kAlteration:
			return "Alteration";
		case AlchemyBaseEffectSecond::kAnyFood:
			return "AnyFood";
		case AlchemyBaseEffectSecond::kAnyFortify:
			return "AnyFortify";
		case AlchemyBaseEffectSecond::kAnyPoison:
			return "AnyPoison";
		case AlchemyBaseEffectSecond::kAnyPotion:
			return "AnyPotion";
		case AlchemyBaseEffectSecond::kArchery:
			return "Archery";
		case AlchemyBaseEffectSecond::kAttackDamageMult:
			return "AttackDamageMult";
		case AlchemyBaseEffectSecond::kBlock:
			return "Block";
		case AlchemyBaseEffectSecond::kBlood:
			return "Blood";
		case AlchemyBaseEffectSecond::kBowSpeed:
			return "BowSpeed";
		case AlchemyBaseEffectSecond::kConjuration:
			return "Conjuration";
		case AlchemyBaseEffectSecond::kCriticalChance:
			return "CriticalChance";
		case AlchemyBaseEffectSecond::kDamageResist:
			return "DamageResist";
		case AlchemyBaseEffectSecond::kDestruction:
			return "Destruction";
		case AlchemyBaseEffectSecond::kFear:
			return "Fear";
		case AlchemyBaseEffectSecond::kFrenzy:
			return "Frenzy";
		case AlchemyBaseEffectSecond::kHealRate:
			return "HealRate";
		case AlchemyBaseEffectSecond::kHealRateMult:
			return "HealRateMult";
		case AlchemyBaseEffectSecond::kHealth:
			return "Health";
		case AlchemyBaseEffectSecond::kHeavyArmor:
			return "HeavyArmor";
		case AlchemyBaseEffectSecond::kIllusion:
			return "Illusion";
		case AlchemyBaseEffectSecond::kInvisibility:
			return "Invisibility";
		case AlchemyBaseEffectSecond::kLightArmor:
			return "LightArmor";
		case AlchemyBaseEffectSecond::kLockpicking:
			return "Lockpicking";
		case AlchemyBaseEffectSecond::kMagicka:
			return "Magicka";
		case AlchemyBaseEffectSecond::kMagickaRate:
			return "MagickaRate";
		case AlchemyBaseEffectSecond::kMagickaRateMult:
			return "MagickaRateMult";
		case AlchemyBaseEffectSecond::kMeleeDamage:
			return "MeleeDamage";
		case AlchemyBaseEffectSecond::kNone:
			return "None";
		case AlchemyBaseEffectSecond::kOneHanded:
			return "OneHanded";
		case AlchemyBaseEffectSecond::kParalysis:
			return "Paralysis";
		case AlchemyBaseEffectSecond::kPickpocket:
			return "Pickpocket";
		case AlchemyBaseEffectSecond::kPoisonResist:
			return "PoisonResist";
		case AlchemyBaseEffectSecond::kReflectDamage:
			return "ReflectDamage";
		case AlchemyBaseEffectSecond::kResistDisease:
			return "ResistDisease";
		case AlchemyBaseEffectSecond::kResistFire:
			return "ResistFire";
		case AlchemyBaseEffectSecond::kResistFrost:
			return "ResistFrost";
		case AlchemyBaseEffectSecond::kResistMagic:
			return "ResistMagic";
		case AlchemyBaseEffectSecond::kResistShock:
			return "ResistShock";
		case AlchemyBaseEffectSecond::kRestoration:
			return "Restoration";
		case AlchemyBaseEffectSecond::kSneak:
			return "Sneak";
		case AlchemyBaseEffectSecond::kSpeedMult:
			return "SpeedMult";
		case AlchemyBaseEffectSecond::kStamina:
			return "Stamina";
		case AlchemyBaseEffectSecond::kStaminaRate:
			return "StaminaRate";
		case AlchemyBaseEffectSecond::kStaminaRateMult:
			return "StaminaRateMult";
		case AlchemyBaseEffectSecond::kTwoHanded:
			return "TwoHanded";
		case AlchemyBaseEffectSecond::kUnarmedDamage:
			return "UnarmedDamage";
		case AlchemyBaseEffectSecond::kWeaponSpeedMult:
			return "WeapenSpeedMult";
		case AlchemyBaseEffectSecond::kCureDisease:
			return "CureDisease";
		case AlchemyBaseEffectSecond::kCurePoison:
			return "CurePoison";
		case AlchemyBaseEffectSecond::kEnchanting:
			return "Enchanting";
		case AlchemyBaseEffectSecond::kWaterbreathing:
			return "Waterbreathing";
		case AlchemyBaseEffectSecond::kSmithing:
			return "Smithing";
		case AlchemyBaseEffectSecond::kSpeech:
			return "Speech";
		case AlchemyBaseEffectSecond::kCarryWeight:
			return "CarryWeight";
		case AlchemyBaseEffectSecond::kAlchemy:
			return "Alchemy";
		case AlchemyBaseEffectSecond::kPersuasion:
			return "Persuasion";
		case AlchemyBaseEffectSecond::kFortifyHealth:
			return "FortifyHealth";
		case AlchemyBaseEffectSecond::kFortifyMagicka:
			return "FortifyMagicka";
		case AlchemyBaseEffectSecond::kFortifyStamina:
			return "FortifyStamina";
		case AlchemyBaseEffectSecond::kCustom:
			return "Custom";
		case AlchemyBaseEffectSecond::kShield:
			return "Shield";
		default:
			return "Unknown";
		}
	} else {
		std::string ret = "|";
		if ((ae & AlchemicEffect::kAlteration).IsValid())
			ret += "Alteration|";
		if ((ae & AlchemicEffect::kArchery).IsValid())
			ret += "Archery|";
		if ((ae & AlchemicEffect::kAttackDamageMult).IsValid())
			ret += "AttackDamageMult|";
		if ((ae & AlchemicEffect::kBlock).IsValid())
			ret += "Block|";
		if ((ae & AlchemicEffect::kBlood).IsValid())
			ret += "Blood|";
		if ((ae & AlchemicEffect::kBowSpeed).IsValid())
			ret += "BowSpeed|";
		if ((ae & AlchemicEffect::kConjuration).IsValid())
			ret += "Conjuration|";
		if ((ae & AlchemicEffect::kCriticalChance).IsValid())
			ret += "CriticalChance|";
		if ((ae & AlchemicEffect::kDamageResist).IsValid())
			ret += "DamageResist|";
		if ((ae & AlchemicEffect::kDestruction).IsValid())
			ret += "Destruction|";
		if ((ae & AlchemicEffect::kFear).IsValid())
			ret += "Fear|";
		if ((ae & AlchemicEffect::kFrenzy).IsValid())
			ret += "Frenzy|";
		if ((ae & AlchemicEffect::kHealRate).IsValid())
			ret += "HealRate|";
		if ((ae & AlchemicEffect::kHealRateMult).IsValid())
			ret += "HealRateMult|";
		if ((ae & AlchemicEffect::kHealth).IsValid())
			ret += "Health|";
		if ((ae & AlchemicEffect::kHeavyArmor).IsValid())
			ret += "HeavyArmor|";
		if ((ae & AlchemicEffect::kIllusion).IsValid())
			ret += "Illusion|";
		if ((ae & AlchemicEffect::kInvisibility).IsValid())
			ret += "Invisibility|";
		if ((ae & AlchemicEffect::kLightArmor).IsValid())
			ret += "LightArmor|";
		if ((ae & AlchemicEffect::kLockpicking).IsValid())
			ret += "Lockpicking|";
		if ((ae & AlchemicEffect::kMagicka).IsValid())
			ret += "Magicka|";
		if ((ae & AlchemicEffect::kMagickaRate).IsValid())
			ret += "MagickaRate|";
		if ((ae & AlchemicEffect::kMagickaRateMult).IsValid())
			ret += "MagickaRateMult|";
		if ((ae & AlchemicEffect::kMeleeDamage).IsValid())
			ret += "MeleeDamage|";
		if ((ae & AlchemicEffect::kNone).IsValid())
			ret += "None|";
		if ((ae & AlchemicEffect::kOneHanded).IsValid())
			ret += "OneHanded|";
		if ((ae & AlchemicEffect::kParalysis).IsValid())
			ret += "Paralysis|";
		if ((ae & AlchemicEffect::kPickpocket).IsValid())
			ret += "Pickpocket|";
		if ((ae & AlchemicEffect::kPoisonResist).IsValid())
			ret += "PoisonResist|";
		if ((ae & AlchemicEffect::kReflectDamage).IsValid())
			ret += "ReflectDamage|";
		if ((ae & AlchemicEffect::kResistDisease).IsValid())
			ret += "ResistDisease|";
		if ((ae & AlchemicEffect::kResistFire).IsValid())
			ret += "ResistFire|";
		if ((ae & AlchemicEffect::kResistFrost).IsValid())
			ret += "ResistFrost|";
		if ((ae & AlchemicEffect::kResistMagic).IsValid())
			ret += "ResistMagic|";
		if ((ae & AlchemicEffect::kResistShock).IsValid())
			ret += "ResistShock|";
		if ((ae & AlchemicEffect::kRestoration).IsValid())
			ret += "Restoration|";
		if ((ae & AlchemicEffect::kSneak).IsValid())
			ret += "Sneak|";
		if ((ae & AlchemicEffect::kSpeedMult).IsValid())
			ret += "SpeedMult|";
		if ((ae & AlchemicEffect::kStamina).IsValid())
			ret += "Stamina|";
		if ((ae & AlchemicEffect::kStaminaRate).IsValid())
			ret += "StaminaRate|";
		if ((ae & AlchemicEffect::kStaminaRateMult).IsValid())
			ret += "StaminaRateMult|";
		if ((ae & AlchemicEffect::kTwoHanded).IsValid())
			ret += "TwoHanded|";
		if ((ae & AlchemicEffect::kUnarmedDamage).IsValid())
			ret += "UnarmedDamage|";
		if ((ae & AlchemicEffect::kWeaponSpeedMult).IsValid())
			ret += "WeapenSpeedMult|";
		if ((ae & AlchemicEffect::kCureDisease).IsValid())
			ret += "CureDisease|";
		if ((ae & AlchemicEffect::kCurePoison).IsValid())
			ret += "CurePoison|";
		if ((ae & AlchemicEffect::kEnchanting).IsValid())
			ret += "Enchanting|";
		if ((ae & AlchemicEffect::kWaterbreathing).IsValid())
			ret += "Waterbreathing|";
		if ((ae & AlchemicEffect::kSmithing).IsValid())
			ret += "Smithing|";
		if ((ae & AlchemicEffect::kSpeech).IsValid())
			ret += "Speech|";
		if ((ae & AlchemicEffect::kCarryWeight).IsValid())
			ret += "CarryWeight|";
		if ((ae & AlchemicEffect::kAlchemy).IsValid())
			ret += "Alchemy|";
		if ((ae & AlchemicEffect::kPersuasion).IsValid())
			ret += "Persuasion|";
		if ((ae & AlchemicEffect::kFortifyHealth).IsValid())
			ret += "FortifyHealth|";
		if ((ae & AlchemicEffect::kFortifyMagicka).IsValid())
			ret += "FortifyMagicka|";
		if ((ae & AlchemicEffect::kFortifyStamina).IsValid())
			ret += "FortifyStamina|";
		if ((ae & AlchemicEffect::kCustom).IsValid())
			ret += "Custom|";
		if ((ae & AlchemicEffect::kShield).IsValid())
			ret += "Shield|";

		if (ret == "|")
			return "|Unknown|";
		return ret;
	}
}

/// <summary>
/// Converts all symbols in a string into lower case.
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
static std::string ToLower(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) { return (unsigned char)std::tolower(c); }  // correct
	);
	return s;
}

int main(int argc, char** argv)
{
	std::vector<std::string> splits;
	

	for (int i = 0; i < argc; i++)
	{
		char buf[50];
		strncpy_s(buf, argv[i], strlen(argv[i]));
		splits.push_back(ToLower(std::string(buf)));
	}


	// found something
	// check for all alchemyeffects whether they are present

	// remove all chars except 0x61-0x7A
	for (int i = 0; i < splits.size(); i++)
	{
		for (int x = 0; x < splits[i].size(); x++)
		{
			if (splits[i][x] < 0x61 || splits[i][x] > 0x7A)
			{
				// remove from string
				splits[i] = splits[i].substr(0, x) + splits[i].substr(x + 1, splits[i].size() - (x + 1));
			}
		}
		if (splits[i].size() > 0 && splits[i][0] == 'k')
			splits[i] = splits[i].substr(1, splits[i].size() - 1);
	}

	AlchemicEffect effects = 0;

	for (int i = 0; i <= 127; i++)
	{
		for (int x = 0; x < splits.size(); x++)
		{
			if (splits[x] == ToLower(ToString(AlchemicEffect(0, 1) << i)))
			{
				// found effect, add to list
				effects |= AlchemicEffect(0, 1) << i;
			}
		}
	}

	std::vector<std::string> special = { "AnyPotion", "AnyPoison", "AnyRegen","AnyFortify", "AnyFood" };
	for (int i = 0; i < special.size(); i++)
	{
		for (int x = 0; x < splits.size(); x++)
		{
			if (splits[x] == ToLower(special[i]))
			{
				// found effect, add to list
				if (i == 0)
					effects |= AlchemicEffect::kAnyPotion;
				else if (i == 1)
					effects |= AlchemicEffect::kAnyPoison;
				else if (i == 2)
					effects |= AlchemicEffect::kAnyRegen;
				else if (i == 3)
					effects |= AlchemicEffect::kAnyFortify;
				else if (i == 4)
					effects |= AlchemicEffect::kAnyFood;
			}
		}
	}

	printf("%s\n", effects.string().c_str());
}