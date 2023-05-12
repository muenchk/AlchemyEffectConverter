
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>


typedef uint64_t AlchemyEffectBase;

/// <summary>
/// Supported AlchemyEffects
/// </summary>
enum class AlchemyEffect : AlchemyEffectBase
{
	kNone = 0,                                      // 0
	kHealth = 1 << 0,                               // 1
	kMagicka = 1 << 1,                              // 2
	kStamina = 1 << 2,                              // 4
	kOneHanded = 1 << 3,                            // 8
	kTwoHanded = 1 << 4,                            // 10
	kArchery = 1 << 5,                              // 20
	kBlock = 1 << 6,                                // 40
	kHeavyArmor = 1 << 7,                           // 80
	kLightArmor = 1 << 8,                           // 100
	kAlteration = 1 << 9,                           // 200
	kConjuration = 1 << 10,                         // 400
	kDestruction = 1 << 11,                         // 800
	kIllusion = 1 << 12,                            // 1000
	kRestoration = 1 << 13,                         // 2000
	kHealRate = 1 << 14,                            // 4000
	kMagickaRate = 1 << 15,                         // 8000
	kStaminaRate = 1 << 16,                         // 10000
	kSpeedMult = 1 << 17,                           // 20000
	kCriticalChance = 1 << 18,                      // 40000
	kMeleeDamage = 1 << 19,                         // 80000
	kUnarmedDamage = 1 << 20,                       // 100000
	kDamageResist = 1 << 21,                        // 200000
	kPoisonResist = 1 << 22,                        // 400000
	kResistFire = 1 << 23,                          // 800000
	kResistShock = 1 << 24,                         // 1000000
	kResistFrost = 1 << 25,                         // 2000000
	kResistMagic = 1 << 26,                         // 4000000
	kResistDisease = 1 << 27,                       // 8000000
	kParalysis = 1 << 28,                           // 10000000
	kInvisibility = 1 << 29,                        // 20000000
	kWeaponSpeedMult = 1 << 30,                     // 40000000
	kAttackDamageMult = (unsigned __int64)1 << 31,  // 80000000
	kHealRateMult = (unsigned __int64)1 << 32,      // 100000000
	kMagickaRateMult = (unsigned __int64)1 << 33,   // 200000000
	kStaminaRateMult = (unsigned __int64)1 << 34,   // 400000000
	kBlood = (unsigned __int64)1 << 35,             // 800000000
	kPickpocket = (unsigned __int64)1 << 36,        // 1000000000
	kLockpicking = (unsigned __int64)1 << 37,       // 2000000000
	kSneak = (unsigned __int64)1 << 38,             // 4000000000
	kFrenzy = (unsigned __int64)1 << 39,            // 8000000000
	kFear = (unsigned __int64)1 << 40,              // 10000000000
	kBowSpeed = (unsigned __int64)1 << 41,          // 20000000000
	kReflectDamage = (unsigned __int64)1 << 42,     // 40000000000
	kCureDisease = (unsigned __int64)1 << 43,       // 80000000000
	kCurePoison = (unsigned __int64)1 << 44,        // 100000000000
	kEnchanting = (unsigned __int64)1 << 45,        // 200000000000
	kWaterbreathing = (unsigned __int64)1 << 46,    // 400000000000
	kSmithing = (unsigned __int64)1 << 47,          // 800000000000
	kSpeech = (unsigned __int64)1 << 48,            // 1000000000000
	kCarryWeight = (unsigned __int64)1 << 49,       // 2000000000000
	kPersuasion = (unsigned __int64)1 << 50,        // 4000000000000
	kAlchemy = (unsigned __int64)1 << 51,           // 8000000000000
	kFortifyHealth = (unsigned __int64)1 << 52,     // 10000000000000
	kFortifyMagicka = (unsigned __int64)1 << 53,    // 20000000000000
	kFortifyStamina = (unsigned __int64)1 << 54,    // 40000000000000
	kUnused1 = (unsigned __int64)1 << 55,           // 80000000000000
	kUnused2 = (unsigned __int64)1 << 56,           // 100000000000000
	kUnused3 = (unsigned __int64)1 << 57,           // 200000000000000
	kUnused4 = (unsigned __int64)1 << 58,           // 300000000000000
	kUnused5 = (unsigned __int64)1 << 59,           // 400000000000000
	kUnused6 = (unsigned __int64)1 << 60,           // 800000000000000
	kUnused7 = (unsigned __int64)1 << 61,           // 1000000000000000
	kUnused8 = (unsigned __int64)1 << 62,           // 2000000000000000
	kCustom = (unsigned __int64)1 << 63,            // 4000000000000000

	// 2000007
	kAnyPotion = static_cast<uint64_t>(kHealth) |
	static_cast<uint64_t>(kMagicka) |
	static_cast<uint64_t>(kStamina) |
	static_cast<uint64_t>(kInvisibility),

	// 720387DFFBFFFF
	kAnyPoison = static_cast<uint64_t>(kHealth) |
	static_cast<uint64_t>(kMagicka) |
	static_cast<uint64_t>(kStamina) |
	static_cast<uint64_t>(kOneHanded) |
	static_cast<uint64_t>(kTwoHanded) |
	static_cast<uint64_t>(kArchery) |
	static_cast<uint64_t>(kBlock) |
	static_cast<uint64_t>(kHeavyArmor) |
	static_cast<uint64_t>(kLightArmor) |
	static_cast<uint64_t>(kAlteration) |
	static_cast<uint64_t>(kConjuration) |
	static_cast<uint64_t>(kDestruction) |
	static_cast<uint64_t>(kIllusion) |
	static_cast<uint64_t>(kRestoration) |
	static_cast<uint64_t>(kHealRate) |
	static_cast<uint64_t>(kMagickaRate) |
	static_cast<uint64_t>(kStaminaRate) |
	static_cast<uint64_t>(kSpeedMult) |
	static_cast<uint64_t>(kMeleeDamage) |
	static_cast<uint64_t>(kUnarmedDamage) |
	static_cast<uint64_t>(kDamageResist) |
	static_cast<uint64_t>(kPoisonResist) |
	static_cast<uint64_t>(kResistFire) |
	static_cast<uint64_t>(kResistShock) |
	static_cast<uint64_t>(kResistFrost) |
	static_cast<uint64_t>(kResistMagic) |
	static_cast<uint64_t>(kResistDisease) |
	static_cast<uint64_t>(kParalysis) |
	static_cast<uint64_t>(kWeaponSpeedMult) |
	static_cast<uint64_t>(kAttackDamageMult) |
	static_cast<uint64_t>(kHealRateMult) |
	static_cast<uint64_t>(kMagickaRateMult) |
	static_cast<uint64_t>(kStaminaRateMult) |
	static_cast<uint64_t>(kFrenzy) |
	static_cast<uint64_t>(kFear) |
	static_cast<uint64_t>(kBowSpeed) |
	static_cast<uint64_t>(kCarryWeight) |
	static_cast<uint64_t>(kFortifyHealth) |
	static_cast<uint64_t>(kFortifyMagicka) |
	static_cast<uint64_t>(kFortifyStamina),

	// 70001C000
	kAnyRegen = static_cast<uint64_t>(kHealRate) |
	static_cast<uint64_t>(kMagickaRate) |
	static_cast<uint64_t>(kStaminaRate) |
	static_cast<uint64_t>(kHealRateMult) |
	static_cast<uint64_t>(kMagickaRateMult) |
	static_cast<uint64_t>(kStaminaRateMult),

	// 7FE670CFFE3FF8
	kAnyFortify = static_cast<uint64_t>(kOneHanded) |
	static_cast<uint64_t>(kTwoHanded) |
	static_cast<uint64_t>(kArchery) |
	static_cast<uint64_t>(kBlock) |
	static_cast<uint64_t>(kHeavyArmor) |
	static_cast<uint64_t>(kLightArmor) |
	static_cast<uint64_t>(kAlteration) |
	static_cast<uint64_t>(kConjuration) |
	static_cast<uint64_t>(kDestruction) |
	static_cast<uint64_t>(kIllusion) |
	static_cast<uint64_t>(kRestoration) |
	static_cast<uint64_t>(kSpeedMult) |
	static_cast<uint64_t>(kCriticalChance) |
	static_cast<uint64_t>(kMeleeDamage) |
	static_cast<uint64_t>(kUnarmedDamage) |
	static_cast<uint64_t>(kDamageResist) |
	static_cast<uint64_t>(kPoisonResist) |
	static_cast<uint64_t>(kResistFire) |
	static_cast<uint64_t>(kResistShock) |
	static_cast<uint64_t>(kResistFrost) |
	static_cast<uint64_t>(kResistMagic) |
	static_cast<uint64_t>(kResistDisease) |
	static_cast<uint64_t>(kWeaponSpeedMult) |
	static_cast<uint64_t>(kAttackDamageMult) |
	static_cast<uint64_t>(kPickpocket) |
	static_cast<uint64_t>(kLockpicking) |
	static_cast<uint64_t>(kSneak) |
	static_cast<uint64_t>(kBowSpeed) |
	static_cast<uint64_t>(kReflectDamage) |
	static_cast<uint64_t>(kEnchanting) |
	static_cast<uint64_t>(kWaterbreathing) |
	static_cast<uint64_t>(kSmithing) |
	static_cast<uint64_t>(kSpeech) |
	static_cast<uint64_t>(kCarryWeight) |
	static_cast<uint64_t>(kPersuasion) |
	static_cast<uint64_t>(kAlchemy) |
	static_cast<uint64_t>(kFortifyHealth) |
	static_cast<uint64_t>(kFortifyMagicka) |
	static_cast<uint64_t>(kFortifyStamina),

	// 7FE677EFFFFFFF
	kAnyFood = static_cast<uint64_t>(kAnyPotion) |
	static_cast<uint64_t>(kAnyRegen) |
	static_cast<uint64_t>(kAnyFortify),

};


static std::string ToString(AlchemyEffect ae)
{
	switch (ae) {
	case AlchemyEffect::kAlteration:
		return "Alteration";
	case AlchemyEffect::kAnyFood:
		return "AnyFood";
	case AlchemyEffect::kAnyFortify:
		return "AnyFortify";
	case AlchemyEffect::kAnyPoison:
		return "AnyPoison";
	case AlchemyEffect::kAnyPotion:
		return "AnyPotion";
	case AlchemyEffect::kArchery:
		return "Archery";
	case AlchemyEffect::kAttackDamageMult:
		return "AttackDamageMult";
	case AlchemyEffect::kBlock:
		return "Block";
	case AlchemyEffect::kBlood:
		return "Blood";
	case AlchemyEffect::kBowSpeed:
		return "BowSpeed";
	case AlchemyEffect::kConjuration:
		return "Conjuration";
	case AlchemyEffect::kCriticalChance:
		return "CriticalChance";
	case AlchemyEffect::kDamageResist:
		return "DamageResist";
	case AlchemyEffect::kDestruction:
		return "Destruction";
	case AlchemyEffect::kFear:
		return "Fear";
	case AlchemyEffect::kFrenzy:
		return "Frenzy";
	case AlchemyEffect::kHealRate:
		return "HealRate";
	case AlchemyEffect::kHealRateMult:
		return "HealRateMult";
	case AlchemyEffect::kHealth:
		return "Health";
	case AlchemyEffect::kHeavyArmor:
		return "HeavyArmor";
	case AlchemyEffect::kIllusion:
		return "Illusion";
	case AlchemyEffect::kInvisibility:
		return "Invisibility";
	case AlchemyEffect::kLightArmor:
		return "LightArmor";
	case AlchemyEffect::kLockpicking:
		return "Lockpicking";
	case AlchemyEffect::kMagicka:
		return "Magicka";
	case AlchemyEffect::kMagickaRate:
		return "MagickaRate";
	case AlchemyEffect::kMagickaRateMult:
		return "MagickaRateMult";
	case AlchemyEffect::kMeleeDamage:
		return "MeleeDamage";
	case AlchemyEffect::kNone:
		return "None";
	case AlchemyEffect::kOneHanded:
		return "OneHanded";
	case AlchemyEffect::kParalysis:
		return "Paralysis";
	case AlchemyEffect::kPickpocket:
		return "Pickpocket";
	case AlchemyEffect::kPoisonResist:
		return "PoisonResist";
	case AlchemyEffect::kReflectDamage:
		return "ReflectDamage";
	case AlchemyEffect::kResistDisease:
		return "ResistDisease";
	case AlchemyEffect::kResistFire:
		return "ResistFire";
	case AlchemyEffect::kResistFrost:
		return "ResistFrost";
	case AlchemyEffect::kResistMagic:
		return "ResistMagic";
	case AlchemyEffect::kResistShock:
		return "ResistShock";
	case AlchemyEffect::kRestoration:
		return "Restoration";
	case AlchemyEffect::kSneak:
		return "Sneak";
	case AlchemyEffect::kSpeedMult:
		return "SpeedMult";
	case AlchemyEffect::kStamina:
		return "Stamina";
	case AlchemyEffect::kStaminaRate:
		return "StaminaRate";
	case AlchemyEffect::kStaminaRateMult:
		return "StaminaRateMult";
	case AlchemyEffect::kTwoHanded:
		return "TwoHanded";
	case AlchemyEffect::kUnarmedDamage:
		return "UnarmedDamage";
	case AlchemyEffect::kWeaponSpeedMult:
		return "WeapenSpeedMult";
	case AlchemyEffect::kCureDisease:
		return "CureDisease";
	case AlchemyEffect::kCurePoison:
		return "CurePoison";
	case AlchemyEffect::kEnchanting:
		return "Enchanting";
	case AlchemyEffect::kWaterbreathing:
		return "Waterbreathing";
	case AlchemyEffect::kSmithing:
		return "Smithing";
	case AlchemyEffect::kSpeech:
		return "Speech";
	case AlchemyEffect::kCarryWeight:
		return "CarryWeight";
	case AlchemyEffect::kAlchemy:
		return "Alchemy";
	case AlchemyEffect::kPersuasion:
		return "Persuasion";
	case AlchemyEffect::kFortifyHealth:
		return "FortifyHealth";
	case AlchemyEffect::kFortifyMagicka:
		return "FortifyMagicka";
	case AlchemyEffect::kFortifyStamina:
		return "FortifyStamina";
	case AlchemyEffect::kCustom:
		return "Custom";
	default:
		return "Unknown";
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

/// <summary>
/// Returns a string showing [val] as Hexadecimal number
/// </summary>
/// <param name="val"></param>
/// <returns></returns>
static std::string GetHex(uint64_t val)
{
	std::stringstream ss;
	ss << std::hex << val;
	return ss.str();
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

	AlchemyEffectBase effects = 0;

	for (int i = 0; i <= 63; i++)
	{
		for (int x = 0; x < splits.size(); x++)
		{
			if (splits[x] == ToLower(ToString(static_cast<AlchemyEffect>((AlchemyEffectBase)1 << i))))
			{
				// found effect, add to list
				effects |= (AlchemyEffectBase)1 << i;
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
					effects |= static_cast<AlchemyEffectBase>(AlchemyEffect::kAnyPotion);
				else if (i == 1)
					effects |= static_cast<AlchemyEffectBase>(AlchemyEffect::kAnyPoison);
				else if (i == 2)
					effects |= static_cast<AlchemyEffectBase>(AlchemyEffect::kAnyRegen);
				else if (i == 3)
					effects |= static_cast<AlchemyEffectBase>(AlchemyEffect::kAnyFortify);
				else if (i == 4)
					effects |= static_cast<AlchemyEffectBase>(AlchemyEffect::kAnyFood);
			}
		}
	}

	printf("%s\n", GetHex(effects).c_str());
}