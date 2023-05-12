#include "AlchemyEffect.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>
#include <utility>
#include <iomanip>

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
/// <summary>
/// Returns a string showing [val] as Hexadecimal number with padding
/// </summary>
/// <param name="val"></param>
/// <returns></returns>
static std::string GetHexFill(uint64_t val)
{
	std::stringstream ss;
	ss << std::setw(16) << std::hex << std::setfill('0') << val;
	return ss.str();
}

bool AlchemicEffect::operator==(const AlchemicEffect& rhs) const
{
	// return true if all values are equal
	return first == rhs.first && second == rhs.second;
}

bool AlchemicEffect::operator==(const int& rhs) const
{
	
	return first == 0 && second == rhs;
}

bool AlchemicEffect::operator<(const AlchemicEffect& rhs) const
{
	return first ? (first < rhs.first) : (rhs.first > 0 ? true : second < rhs.second);
}

bool AlchemicEffect::operator>(const int& rhs) const
{
	return first ? true : (second > rhs);
}


bool AlchemicEffect::operator!() const
{
	// return true if both value are zero
	return first == 0 && second == 0;
}

bool AlchemicEffect::operator&&(const AlchemicEffect& rhs) const
{
	// return true if both objects have a value != 0
	return (first != 0 || second != 0) && (rhs.first != 0 || rhs.second != 0);
}

bool AlchemicEffect::operator&&(const bool& rhs) const
{
	// return true if both objects have a value != 0
	return (first != 0 || second != 0) && rhs;
}

bool AlchemicEffect::operator||(const AlchemicEffect& rhs) const
{
	// return true one of the objects has a value != 0
	return (first != 0 || second != 0) || (rhs.first != 0 || rhs.second != 0);
}

AlchemicEffect AlchemicEffect::operator~() const
{
	return AlchemicEffect(~first, ~second);
}

AlchemicEffect AlchemicEffect::operator&(const AlchemicEffect& rhs) const
{
	return AlchemicEffect(first & rhs.first, second & rhs.second);
}

/* AlchemicEffect operator&(const AlchemicEffect& lhs, const AlchemicEffect& rhs)
{
	return AlchemicEffect(lhs.first & rhs.first, lhs.second & rhs.second);
}*/

AlchemicEffect AlchemicEffect::operator|(const AlchemicEffect& rhs) const
{
	return AlchemicEffect(first | rhs.first, second | rhs.second);
}

/* AlchemicEffect operator|(const AlchemicEffect& lhs, const AlchemicEffect& rhs)
{
	return AlchemicEffect(lhs.first | rhs.first, lhs.second | rhs.second);
}*/

AlchemicEffect AlchemicEffect::operator^(const AlchemicEffect& rhs) const
{
	return AlchemicEffect(first ^ rhs.first, second ^ rhs.second);
}

/* AlchemicEffect operator^(const AlchemicEffect& lhs, const AlchemicEffect& rhs)
{
	return AlchemicEffect(lhs.first ^ rhs.first, lhs.second ^ rhs.second);
}*/

AlchemicEffect AlchemicEffect::ShiftLeft(const uint64_t& shift) const
{
	AlchemicEffect alc;
	if (shift > 64) {
		// we are shifting second into first completely and more
		// just replace first by second and shift less
		alc.first = second << (shift - 64);
		alc.second = 0;
	} else if (shift == 64) {
		// we are shifting second into first
		alc.first = second;
		alc.second = 0;
	} else if (shift == 0) {
		alc.first = first;
		alc.second = second;
	} else {
		// we shift less than 64 bytes, thus we need an intermediary
		// save bytes shifted out
		uint64_t tmp = second >> (64 - shift);
		// shift second
		alc.second = second << (shift);
		// shift first
		alc.first = first << shift;
		// merge tmp into first
		alc.first |= tmp;
	}
	return alc;
}

AlchemicEffect AlchemicEffect::operator<<(const uint64_t& shift) const
{
	return ShiftLeft(shift);
}

AlchemicEffect AlchemicEffect::operator<<(const int& shift) const
{
	return ShiftLeft(shift);
}

AlchemicEffect& AlchemicEffect::operator=(const AlchemicEffect& rhs)
{
	first = rhs.first;
	second = rhs.second;
	return *this;
}

AlchemicEffect::AlchemicEffect(const std::string& rhs)
{
	if (rhs.size() > 16) {
		int length = (int)rhs.size() - 16;
		try {
			first = std::stoull(rhs.substr(0, length), nullptr, 16);
			second = std::stoull(rhs.substr(length, 16), nullptr, 16);
		} catch (std::exception& e) {
			throw(InitializationError("Cannot convert string to AlchemicEffect", e.what()));
		}
	} else {
		first = 0;
		try {
			second = std::stoull(rhs, nullptr, 16);
		} catch (std::exception& e) {
			throw(InitializationError("Cannot convert string to AlchemicEffect", e.what()));
		}
	}
}

AlchemicEffect::AlchemicEffect(const uint64_t& rhs)
{
	first = 0;
	second = rhs;
}

AlchemicEffect::AlchemicEffect(const int& rhs)
{
	first = 0;
	second = rhs;
}

AlchemicEffect::AlchemicEffect(const ::AlchemyBaseEffectSecond& rhs)
{
	first = 0;
	second = static_cast<::AlchemyBaseEffect>(rhs);
}

AlchemicEffect& AlchemicEffect::operator&=(const AlchemicEffect& rhs)
{
	first &= rhs.first;
	second &= rhs.second;
	return *this;
}

AlchemicEffect& AlchemicEffect::operator|=(const AlchemicEffect& rhs)
{
	first |= rhs.first;
	second |= rhs.second;
	return *this;
}

AlchemicEffect& AlchemicEffect::operator^=(const AlchemicEffect& rhs)
{
	first ^= rhs.first;
	second ^= rhs.second;
	return *this;
}

AlchemicEffect::operator std::string()
{
	return first ? GetHex(first) + GetHexFill(second) : GetHex(second);
}

std::string AlchemicEffect::string()
{
	return first ? GetHex(first) + GetHexFill(second) : GetHex(second);
}

bool AlchemicEffect::IsValid()
{
	return first != 0 || second != 0;
}

AlchemyBaseEffectSecond AlchemicEffect::AlchemyBaseEffectSecond()
{
	if (first > 0)
		return ::AlchemyBaseEffectSecond::kNone;
	else
		return static_cast<::AlchemyBaseEffectSecond>(second);
}

AlchemyBaseEffectFirst AlchemicEffect::AlchemyBaseEffectFirst()
{
	if (first > 0)
		return ::AlchemyBaseEffectFirst::kNone;
	else
		return static_cast<::AlchemyBaseEffectFirst>(second);
}

bool AlchemicEffect::IsEffect()
{
	// we only need to check one of the values. 
	// If first has a value, second cannot have one, so just check this
	if (first)
	{
		if (second)
			return false;
		return (first & (first - 1)) == 0;
	} else {
		// only have second to check
		return (second & (second - 1)) == 0;
	}
}

bool AlchemicEffect::IsEffectMap()
{
	return !IsEffect();
}


// definition of constants

const AlchemicEffect AlchemicEffect::kNone = AlchemyBaseEffectSecond::kNone;
const AlchemicEffect AlchemicEffect::kHealth = AlchemyBaseEffectSecond::kHealth;
const AlchemicEffect AlchemicEffect::kMagicka = AlchemyBaseEffectSecond::kMagicka;
const AlchemicEffect AlchemicEffect::kStamina = AlchemyBaseEffectSecond::kStamina;
const AlchemicEffect AlchemicEffect::kOneHanded = AlchemyBaseEffectSecond::kOneHanded;
const AlchemicEffect AlchemicEffect::kTwoHanded = AlchemyBaseEffectSecond::kTwoHanded;
const AlchemicEffect AlchemicEffect::kArchery = AlchemyBaseEffectSecond::kArchery;
const AlchemicEffect AlchemicEffect::kBlock = AlchemyBaseEffectSecond::kBlock;
const AlchemicEffect AlchemicEffect::kHeavyArmor = AlchemyBaseEffectSecond::kHeavyArmor;
const AlchemicEffect AlchemicEffect::kLightArmor = AlchemyBaseEffectSecond::kLightArmor;
const AlchemicEffect AlchemicEffect::kAlteration = AlchemyBaseEffectSecond::kAlteration;
const AlchemicEffect AlchemicEffect::kConjuration = AlchemyBaseEffectSecond::kConjuration;
const AlchemicEffect AlchemicEffect::kDestruction = AlchemyBaseEffectSecond::kDestruction;
const AlchemicEffect AlchemicEffect::kIllusion = AlchemyBaseEffectSecond::kIllusion;
const AlchemicEffect AlchemicEffect::kRestoration = AlchemyBaseEffectSecond::kRestoration;
const AlchemicEffect AlchemicEffect::kHealRate = AlchemyBaseEffectSecond::kHealRate;
const AlchemicEffect AlchemicEffect::kMagickaRate = AlchemyBaseEffectSecond::kMagickaRate;
const AlchemicEffect AlchemicEffect::kStaminaRate = AlchemyBaseEffectSecond::kStaminaRate;
const AlchemicEffect AlchemicEffect::kSpeedMult = AlchemyBaseEffectSecond::kSpeedMult;
const AlchemicEffect AlchemicEffect::kCriticalChance = AlchemyBaseEffectSecond::kCriticalChance;
const AlchemicEffect AlchemicEffect::kMeleeDamage = AlchemyBaseEffectSecond::kMeleeDamage;
const AlchemicEffect AlchemicEffect::kUnarmedDamage = AlchemyBaseEffectSecond::kUnarmedDamage;
const AlchemicEffect AlchemicEffect::kDamageResist = AlchemyBaseEffectSecond::kDamageResist;
const AlchemicEffect AlchemicEffect::kPoisonResist = AlchemyBaseEffectSecond::kPoisonResist;
const AlchemicEffect AlchemicEffect::kResistFire = AlchemyBaseEffectSecond::kResistFire;
const AlchemicEffect AlchemicEffect::kResistShock = AlchemyBaseEffectSecond::kResistShock;
const AlchemicEffect AlchemicEffect::kResistFrost = AlchemyBaseEffectSecond::kResistFrost;
const AlchemicEffect AlchemicEffect::kResistMagic = AlchemyBaseEffectSecond::kResistMagic;
const AlchemicEffect AlchemicEffect::kResistDisease = AlchemyBaseEffectSecond::kResistDisease;
const AlchemicEffect AlchemicEffect::kParalysis = AlchemyBaseEffectSecond::kParalysis;
const AlchemicEffect AlchemicEffect::kInvisibility = AlchemyBaseEffectSecond::kInvisibility;
const AlchemicEffect AlchemicEffect::kWeaponSpeedMult = AlchemyBaseEffectSecond::kWeaponSpeedMult;
const AlchemicEffect AlchemicEffect::kAttackDamageMult = AlchemyBaseEffectSecond::kAttackDamageMult;
const AlchemicEffect AlchemicEffect::kHealRateMult = AlchemyBaseEffectSecond::kHealRateMult;
const AlchemicEffect AlchemicEffect::kMagickaRateMult = AlchemyBaseEffectSecond::kMagickaRateMult;
const AlchemicEffect AlchemicEffect::kStaminaRateMult = AlchemyBaseEffectSecond::kStaminaRateMult;
const AlchemicEffect AlchemicEffect::kBlood = AlchemyBaseEffectSecond::kBlood;
const AlchemicEffect AlchemicEffect::kPickpocket = AlchemyBaseEffectSecond::kPickpocket;
const AlchemicEffect AlchemicEffect::kLockpicking = AlchemyBaseEffectSecond::kLockpicking;
const AlchemicEffect AlchemicEffect::kSneak = AlchemyBaseEffectSecond::kSneak;
const AlchemicEffect AlchemicEffect::kFrenzy = AlchemyBaseEffectSecond::kFrenzy;
const AlchemicEffect AlchemicEffect::kFear = AlchemyBaseEffectSecond::kFear;
const AlchemicEffect AlchemicEffect::kBowSpeed = AlchemyBaseEffectSecond::kBowSpeed;
const AlchemicEffect AlchemicEffect::kReflectDamage = AlchemyBaseEffectSecond::kReflectDamage;
const AlchemicEffect AlchemicEffect::kCureDisease = AlchemyBaseEffectSecond::kCureDisease;
const AlchemicEffect AlchemicEffect::kCurePoison = AlchemyBaseEffectSecond::kCurePoison;
const AlchemicEffect AlchemicEffect::kEnchanting = AlchemyBaseEffectSecond::kEnchanting;
const AlchemicEffect AlchemicEffect::kWaterbreathing = AlchemyBaseEffectSecond::kWaterbreathing;
const AlchemicEffect AlchemicEffect::kSmithing = AlchemyBaseEffectSecond::kSmithing;
const AlchemicEffect AlchemicEffect::kSpeech = AlchemyBaseEffectSecond::kSpeech;
const AlchemicEffect AlchemicEffect::kCarryWeight = AlchemyBaseEffectSecond::kCarryWeight;
const AlchemicEffect AlchemicEffect::kPersuasion = AlchemyBaseEffectSecond::kPersuasion;
const AlchemicEffect AlchemicEffect::kAlchemy = AlchemyBaseEffectSecond::kAlchemy;
const AlchemicEffect AlchemicEffect::kFortifyHealth = AlchemyBaseEffectSecond::kFortifyHealth;
const AlchemicEffect AlchemicEffect::kFortifyMagicka = AlchemyBaseEffectSecond::kFortifyMagicka;
const AlchemicEffect AlchemicEffect::kFortifyStamina = AlchemyBaseEffectSecond::kFortifyStamina;
const AlchemicEffect AlchemicEffect::kShield = AlchemyBaseEffectSecond::kShield;
const AlchemicEffect AlchemicEffect::kUnused2 = AlchemyBaseEffectSecond::kUnused2;
const AlchemicEffect AlchemicEffect::kUnused3 = AlchemyBaseEffectSecond::kUnused3;
const AlchemicEffect AlchemicEffect::kUnused4 = AlchemyBaseEffectSecond::kUnused4;
const AlchemicEffect AlchemicEffect::kUnused5 = AlchemyBaseEffectSecond::kUnused5;
const AlchemicEffect AlchemicEffect::kUnused6 = AlchemyBaseEffectSecond::kUnused6;
const AlchemicEffect AlchemicEffect::kUnused7 = AlchemyBaseEffectSecond::kUnused7;
const AlchemicEffect AlchemicEffect::kUnused8 = AlchemyBaseEffectSecond::kUnused8;
const AlchemicEffect AlchemicEffect::kCustom = AlchemyBaseEffectSecond::kCustom;

const AlchemicEffect AlchemicEffect::kAnyPotion = AlchemicEffect(0, static_cast<uint64_t>(AlchemyBaseEffectSecond::kAnyPotion));
const AlchemicEffect AlchemicEffect::kAnyPoison = AlchemicEffect(0, static_cast<uint64_t>(AlchemyBaseEffectSecond::kAnyPoison));
const AlchemicEffect AlchemicEffect::kAnyRegen = AlchemicEffect(0, static_cast<uint64_t>(AlchemyBaseEffectSecond::kAnyRegen));
const AlchemicEffect AlchemicEffect::kAnyFortify = AlchemicEffect(0, static_cast<uint64_t>(AlchemyBaseEffectSecond::kAnyFortify));
const AlchemicEffect AlchemicEffect::kAnyFood = AlchemicEffect(0, static_cast<uint64_t>(AlchemyBaseEffectSecond::kAnyFood));
