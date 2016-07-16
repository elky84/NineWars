#pragma once

namespace Instance
{

class CharacterStat
{
public:
	CharacterStat()
	{
		memset(&m_TeamWork, 0, sizeof(m_TeamWork));

		memset(&m_Tactical, 0, sizeof(m_Tactical));

		memset(&m_Speed, 0, sizeof(m_Speed));

		memset(&m_Range, 0, sizeof(m_Range));

		memset(&m_Prediction, 0, sizeof(m_Prediction));

		memset(&m_Leadership, 0, sizeof(m_Leadership));

		memset(&m_Judgement, 0, sizeof(m_Judgement));

		memset(&m_DefenseTendency, 0, sizeof(m_DefenseTendency));

		memset(&m_Concentration, 0, sizeof(m_Concentration));

		memset(&m_Competitive, 0, sizeof(m_Competitive));

		memset(&m_Calm, 0, sizeof(m_Calm));

		memset(&m_Boldness, 0, sizeof(m_Boldness));

		memset(&m_AttackTendency, 0, sizeof(m_AttackTendency));

		memset(&m_AttackSpeed, 0, sizeof(m_AttackSpeed));

		memset(&m_AttackRate, 0, sizeof(m_AttackRate));

		memset(&m_ApDefense, 0, sizeof(m_ApDefense));

		memset(&m_ApDamage, 0, sizeof(m_ApDamage));

		memset(&m_Aggressive, 0, sizeof(m_Aggressive));

		memset(&m_AdDefense, 0, sizeof(m_AdDefense));

		memset(&m_AdDamage, 0, sizeof(m_AdDamage));

	}

	int& TeamWorkReference()
	{
		return m_TeamWork;
	}

	int TeamWork() const
	{
		return m_TeamWork;
	}

	void TeamWork(const int& _TeamWork)
	{
		m_TeamWork = _TeamWork;
	}

	int& TacticalReference()
	{
		return m_Tactical;
	}

	int Tactical() const
	{
		return m_Tactical;
	}

	void Tactical(const int& _Tactical)
	{
		m_Tactical = _Tactical;
	}

	float& SpeedReference()
	{
		return m_Speed;
	}

	float Speed() const
	{
		return m_Speed;
	}

	void Speed(const float& _Speed)
	{
		m_Speed = _Speed;
	}

	float& RangeReference()
	{
		return m_Range;
	}

	float Range() const
	{
		return m_Range;
	}

	void Range(const float& _Range)
	{
		m_Range = _Range;
	}

	int& PredictionReference()
	{
		return m_Prediction;
	}

	int Prediction() const
	{
		return m_Prediction;
	}

	void Prediction(const int& _Prediction)
	{
		m_Prediction = _Prediction;
	}

	int& LeadershipReference()
	{
		return m_Leadership;
	}

	int Leadership() const
	{
		return m_Leadership;
	}

	void Leadership(const int& _Leadership)
	{
		m_Leadership = _Leadership;
	}

	int& JudgementReference()
	{
		return m_Judgement;
	}

	int Judgement() const
	{
		return m_Judgement;
	}

	void Judgement(const int& _Judgement)
	{
		m_Judgement = _Judgement;
	}

	int& DefenseTendencyReference()
	{
		return m_DefenseTendency;
	}

	int DefenseTendency() const
	{
		return m_DefenseTendency;
	}

	void DefenseTendency(const int& _DefenseTendency)
	{
		m_DefenseTendency = _DefenseTendency;
	}

	int& ConcentrationReference()
	{
		return m_Concentration;
	}

	int Concentration() const
	{
		return m_Concentration;
	}

	void Concentration(const int& _Concentration)
	{
		m_Concentration = _Concentration;
	}

	int& CompetitiveReference()
	{
		return m_Competitive;
	}

	int Competitive() const
	{
		return m_Competitive;
	}

	void Competitive(const int& _Competitive)
	{
		m_Competitive = _Competitive;
	}

	int& CalmReference()
	{
		return m_Calm;
	}

	int Calm() const
	{
		return m_Calm;
	}

	void Calm(const int& _Calm)
	{
		m_Calm = _Calm;
	}

	int& BoldnessReference()
	{
		return m_Boldness;
	}

	int Boldness() const
	{
		return m_Boldness;
	}

	void Boldness(const int& _Boldness)
	{
		m_Boldness = _Boldness;
	}

	int& AttackTendencyReference()
	{
		return m_AttackTendency;
	}

	int AttackTendency() const
	{
		return m_AttackTendency;
	}

	void AttackTendency(const int& _AttackTendency)
	{
		m_AttackTendency = _AttackTendency;
	}

	float& AttackSpeedReference()
	{
		return m_AttackSpeed;
	}

	float AttackSpeed() const
	{
		return m_AttackSpeed;
	}

	void AttackSpeed(const float& _AttackSpeed)
	{
		m_AttackSpeed = _AttackSpeed;
	}

	float& AttackRateReference()
	{
		return m_AttackRate;
	}

	float AttackRate() const
	{
		return m_AttackRate;
	}

	void AttackRate(const float& _AttackRate)
	{
		m_AttackRate = _AttackRate;
	}

	int& ApDefenseReference()
	{
		return m_ApDefense;
	}

	int ApDefense() const
	{
		return m_ApDefense;
	}

	void ApDefense(const int& _ApDefense)
	{
		m_ApDefense = _ApDefense;
	}

	int& ApDamageReference()
	{
		return m_ApDamage;
	}

	int ApDamage() const
	{
		return m_ApDamage;
	}

	void ApDamage(const int& _ApDamage)
	{
		m_ApDamage = _ApDamage;
	}

	int& AggressiveReference()
	{
		return m_Aggressive;
	}

	int Aggressive() const
	{
		return m_Aggressive;
	}

	void Aggressive(const int& _Aggressive)
	{
		m_Aggressive = _Aggressive;
	}

	int& AdDefenseReference()
	{
		return m_AdDefense;
	}

	int AdDefense() const
	{
		return m_AdDefense;
	}

	void AdDefense(const int& _AdDefense)
	{
		m_AdDefense = _AdDefense;
	}

	int& AdDamageReference()
	{
		return m_AdDamage;
	}

	int AdDamage() const
	{
		return m_AdDamage;
	}

	void AdDamage(const int& _AdDamage)
	{
		m_AdDamage = _AdDamage;
	}

private:
	int m_TeamWork;
	int m_Tactical;
	float m_Speed;
	float m_Range;
	int m_Prediction;
	int m_Leadership;
	int m_Judgement;
	int m_DefenseTendency;
	int m_Concentration;
	int m_Competitive;
	int m_Calm;
	int m_Boldness;
	int m_AttackTendency;
	float m_AttackSpeed;
	float m_AttackRate;
	int m_ApDefense;
	int m_ApDamage;
	int m_Aggressive;
	int m_AdDefense;
	int m_AdDamage;
};


} // Instance

