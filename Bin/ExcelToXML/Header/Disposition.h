#pragma once

namespace ExcelData
{

class Disposition
{
public:
	Disposition()
	{
		memset(&m_TeamWork, 0, sizeof(m_TeamWork));

		memset(&m_Tactical, 0, sizeof(m_Tactical));

		memset(&m_Speed, 0, sizeof(m_Speed));

		memset(&m_Prediction, 0, sizeof(m_Prediction));

		memset(&m_Leadership, 0, sizeof(m_Leadership));

		memset(&m_Judgement, 0, sizeof(m_Judgement));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_DefenseTendency, 0, sizeof(m_DefenseTendency));

		memset(&m_Concentration, 0, sizeof(m_Concentration));

		memset(&m_Competitive, 0, sizeof(m_Competitive));

		memset(&m_Calm, 0, sizeof(m_Calm));

		memset(&m_Boldness, 0, sizeof(m_Boldness));

		memset(&m_AttackTendency, 0, sizeof(m_AttackTendency));

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

	int& SpeedReference()
	{
		return m_Speed;
	}

	int Speed() const
	{
		return m_Speed;
	}

	void Speed(const int& _Speed)
	{
		m_Speed = _Speed;
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

	std::wstring& IndexReference()
	{
		return m_Index;
	}

	std::wstring Index() const
	{
		return m_Index;
	}

	void Index(const std::wstring& _Index)
	{
		m_Index = _Index;
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
	int m_Speed;
	int m_Prediction;
	int m_Leadership;
	int m_Judgement;
	std::wstring m_Index;
	int m_DefenseTendency;
	int m_Concentration;
	int m_Competitive;
	int m_Calm;
	int m_Boldness;
	int m_AttackTendency;
	int m_ApDefense;
	int m_ApDamage;
	int m_Aggressive;
	int m_AdDefense;
	int m_AdDamage;
};

class DispositionData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		Disposition Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/Disposition.XML");
		if( false == parser.read_file(L"./XML/Disposition.XML"))
		{
			LOG_ERROR(_T("%s, Open() Failed. Path(./XML/Disposition.XML"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.execute(L"/DispositionList"))
		{
			LOG_ERROR(_T("%s, execute() Failed. /DispositionList"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(_T("%s, execute() Failed. Data"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"AdDamage", Instance.AdDamageReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.AdDamageReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"AdDefense", Instance.AdDefenseReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.AdDefenseReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Aggressive", Instance.AggressiveReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.AggressiveReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"ApDamage", Instance.ApDamageReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.ApDamageReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"ApDefense", Instance.ApDefenseReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.ApDefenseReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"AttackTendency", Instance.AttackTendencyReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.AttackTendencyReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Boldness", Instance.BoldnessReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.BoldnessReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Calm", Instance.CalmReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.CalmReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Competitive", Instance.CompetitiveReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.CompetitiveReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Concentration", Instance.ConcentrationReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.ConcentrationReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"DefenseTendency", Instance.DefenseTendencyReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.DefenseTendencyReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.IndexReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Judgement", Instance.JudgementReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.JudgementReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Leadership", Instance.LeadershipReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.LeadershipReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Prediction", Instance.PredictionReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.PredictionReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Speed", Instance.SpeedReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.SpeedReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Tactical", Instance.TacticalReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.TacticalReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"TeamWork", Instance.TeamWorkReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.TeamWorkReference()"), __FUNCTIONW__);
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<std::wstring, Disposition>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(std::wstring& key, Disposition& Instance)
	{
		std::map<std::wstring, Disposition>::iterator it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<std::wstring, Disposition>& Map()
	{
		return m_Map;
	}

private:
	std::map<std::wstring, Disposition> m_Map;
};

__declspec(selectany) DispositionData DispositionDataInstance;

} // ExcelData

