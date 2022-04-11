#include "fraction.h"

std::map <std::string, Fraction> Fraction::fractions;

Fraction::Fraction()
{
    this->name = "None";
    this->heroReputation = 0;
    this->attitude = neutral;
}

Fraction::Fraction(std::string name, int heroReputation, int attitude)
{
    this->name = name;
    this->heroReputation = heroReputation;
    this->attitude = attitude;
}

Fraction::~Fraction()
{
}

std::string Fraction::printAttitude()
{
    std::string attitude;

    if (this->attitude == angry) attitude = "angry";
    else if (this->attitude == hostile) attitude = "hostile";
    else if (this->attitude == friendly) attitude = "friendly";
    else attitude = "neutral";

    return attitude;
}

void Fraction::initFractions_EN()
{
    Logger::out("Function starts", "Fraction::initFractions_EN");

    Fraction None("None", 0, neutral);
    Fraction Beggars("Beggars", 0, neutral);
    Fraction Police("Police", 0, neutral);
    Fraction Hammers("Hammers", 0, neutral);
    Fraction Sleepers("Sleepers", 0, neutral);

    fractions["None"] = None;
    fractions["Beggars"] = Beggars;
    fractions["Police"] = Police;
    fractions["Hammers"] = Hammers;
    fractions["Sleepers"] = Sleepers;
}

void Fraction::initFractions_PL()
{
    Logger::out("Function starts", "Fraction::initFractions_PL");

    Fraction None("Brak", 0, neutral);
    Fraction Beggars("�ebracy", 0, neutral);
    Fraction Police("Policja", 0, neutral);
    Fraction Hammers("M�oty", 0, neutral);
    Fraction Sleepers("�ni�cy", 0, neutral);

    fractions["None"] = None;
    fractions["Beggars"] = Beggars;
    fractions["Police"] = Police;
    fractions["Hammers"] = Hammers;
    fractions["Sleepers"] = Sleepers;
}