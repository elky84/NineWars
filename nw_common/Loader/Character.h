#pragma once

namespace ExcelData
{

class Character
{
public:
	Character()
	{
		m_Skill.resize(3);

		memset(&m_Wis, 0, sizeof(m_Wis));

		memset(&m_TeamWork, 0, sizeof(m_TeamWork));

		memset(&m_Tactical, 0, sizeof(m_Tactical));

		memset(&m_Str, 0, sizeof(m_Str));

		memset(&m_Speed, 0, sizeof(m_Speed));

		memset(&m_Range, 0, sizeof(m_Range));

		memset(&m_Prediction, 0, sizeof(m_Prediction));

		memset(&m_PreDelay, 0, sizeof(m_PreDelay));

		memset(&m_PostDelay, 0, sizeof(m_PostDelay));

		memset(&m_Position, 0, sizeof(m_Position));

		memset(&m_Name, 0, sizeof(m_Name));

		memset(&m_MovingTime, 0, sizeof(m_MovingTime));

		memset(&m_Leadership, 0, sizeof(m_Leadership));

		memset(&m_Judgement, 0, sizeof(m_Judgement));

		memset(&m_Job, 0, sizeof(m_Job));

		memset(&m_Int, 0, sizeof(m_Int));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_Image, 0, sizeof(m_Image));

		memset(&m_Dex, 0, sizeof(m_Dex));

		memset(&m_DefenseTendency, 0, sizeof(m_DefenseTendency));

		memset(&m_Cost, 0, sizeof(m_Cost));

		memset(&m_Concentration, 0, sizeof(m_Concentration));

		memset(&m_Con, 0, sizeof(m_Con));

		memset(&m_Competitive, 0, sizeof(m_Competitive));

		memset(&m_Class, 0, sizeof(m_Class));

		memset(&m_Calm, 0, sizeof(m_Calm));

		memset(&m_Boldness, 0, sizeof(m_Boldness));

		memset(&m_AttackTendency, 0, sizeof(m_AttackTendency));

		memset(&m_Aggressive, 0, sizeof(m_Aggressive));

	}

	int& WisReference()
	{
		return m_Wis;
	}

	int Wis() const
	{
		return m_Wis;
	}

	void Wis(const int& _Wis)
	{
		m_Wis = _Wis;
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

	int& StrReference()
	{
		return m_Str;
	}

	int Str() const
	{
		return m_Str;
	}

	void Str(const int& _Str)
	{
		m_Str = _Str;
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

	int& Skill2Reference()
	{
		return m_Skill[2];
	}

	std::vector<int>& VectorSkill()
	{
		return m_Skill;
	}

	int& Skill1Reference()
	{
		return m_Skill[1];
	}

	int& Skill0Reference()
	{
		return m_Skill[0];
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

	int& PreDelayReference()
	{
		return m_PreDelay;
	}

	int PreDelay() const
	{
		return m_PreDelay;
	}

	void PreDelay(const int& _PreDelay)
	{
		m_PreDelay = _PreDelay;
	}

	int& PostDelayReference()
	{
		return m_PostDelay;
	}

	int PostDelay() const
	{
		return m_PostDelay;
	}

	void PostDelay(const int& _PostDelay)
	{
		m_PostDelay = _PostDelay;
	}

	int& PositionReference()
	{
		return m_Position;
	}

	int Position() const
	{
		return m_Position;
	}

	void Position(const int& _Position)
	{
		m_Position = _Position;
	}

	std::wstring& NameReference()
	{
		return m_Name;
	}

	std::wstring Name() const
	{
		return m_Name;
	}

	void Name(const std::wstring& _Name)
	{
		m_Name = _Name;
	}

	int& MovingTimeReference()
	{
		return m_MovingTime;
	}

	int MovingTime() const
	{
		return m_MovingTime;
	}

	void MovingTime(const int& _MovingTime)
	{
		m_MovingTime = _MovingTime;
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

	std::wstring& JobReference()
	{
		return m_Job;
	}

	std::wstring Job() const
	{
		return m_Job;
	}

	void Job(const std::wstring& _Job)
	{
		m_Job = _Job;
	}

	int& IntReference()
	{
		return m_Int;
	}

	int Int() const
	{
		return m_Int;
	}

	void Int(const int& _Int)
	{
		m_Int = _Int;
	}

	int& IndexReference()
	{
		return m_Index;
	}

	int Index() const
	{
		return m_Index;
	}

	void Index(const int& _Index)
	{
		m_Index = _Index;
	}

	std::wstring& ImageReference()
	{
		return m_Image;
	}

	std::wstring Image() const
	{
		return m_Image;
	}

	void Image(const std::wstring& _Image)
	{
		m_Image = _Image;
	}

	int& DexReference()
	{
		return m_Dex;
	}

	int Dex() const
	{
		return m_Dex;
	}

	void Dex(const int& _Dex)
	{
		m_Dex = _Dex;
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

	int& CostReference()
	{
		return m_Cost;
	}

	int Cost() const
	{
		return m_Cost;
	}

	void Cost(const int& _Cost)
	{
		m_Cost = _Cost;
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

	int& ConReference()
	{
		return m_Con;
	}

	int Con() const
	{
		return m_Con;
	}

	void Con(const int& _Con)
	{
		m_Con = _Con;
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

	int& ClassReference()
	{
		return m_Class;
	}

	int Class() const
	{
		return m_Class;
	}

	void Class(const int& _Class)
	{
		m_Class = _Class;
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

private:
	int m_Wis;
	int m_TeamWork;
	int m_Tactical;
	int m_Str;
	float m_Speed;
	std::vector<int> m_Skill;
	float m_Range;
	int m_Prediction;
	int m_PreDelay;
	int m_PostDelay;
	int m_Position;
	std::wstring m_Name;
	int m_MovingTime;
	int m_Leadership;
	int m_Judgement;
	std::wstring m_Job;
	int m_Int;
	int m_Index;
	std::wstring m_Image;
	int m_Dex;
	int m_DefenseTendency;
	int m_Cost;
	int m_Concentration;
	int m_Con;
	int m_Competitive;
	int m_Class;
	int m_Calm;
	int m_Boldness;
	int m_AttackTendency;
	int m_Aggressive;
};

class CharacterData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		Character Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/Character.XML");
		if( false == parser.read_file(L"./XML/Character.XML"))
		{
			LOG_ERROR(_T("%s, Open() Failed. Path(./XML/Character.XML"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.execute(L"/CharacterList"))
		{
			LOG_ERROR(_T("%s, execute() Failed. /CharacterList"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(_T("%s, execute() Failed. Data"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Aggressive", Instance.AggressiveReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.AggressiveReference()"), __FUNCTIONW__);
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

		if ( false == parser.bind_attrib(L"Class", Instance.ClassReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.ClassReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Competitive", Instance.CompetitiveReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.CompetitiveReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Con", Instance.ConReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.ConReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Concentration", Instance.ConcentrationReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.ConcentrationReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Cost", Instance.CostReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.CostReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"DefenseTendency", Instance.DefenseTendencyReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.DefenseTendencyReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Dex", Instance.DexReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.DexReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Image", Instance.ImageReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.ImageReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.IndexReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Int", Instance.IntReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.IntReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Job", Instance.JobReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.JobReference()"), __FUNCTIONW__);
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

		if ( false == parser.bind_attrib(L"MovingTime", Instance.MovingTimeReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.MovingTimeReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Name", Instance.NameReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.NameReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Position", Instance.PositionReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.PositionReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"PostDelay", Instance.PostDelayReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.PostDelayReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"PreDelay", Instance.PreDelayReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.PreDelayReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Prediction", Instance.PredictionReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.PredictionReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Range", Instance.RangeReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.RangeReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Skill0", Instance.Skill0Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.Skill0Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Skill1", Instance.Skill1Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.Skill1Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Skill2", Instance.Skill2Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.Skill2Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Speed", Instance.SpeedReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.SpeedReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Str", Instance.StrReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.StrReference()"), __FUNCTIONW__);
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

		if ( false == parser.bind_attrib(L"Wis", Instance.WisReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.WisReference()"), __FUNCTIONW__);
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, Character>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, Character& Instance)
	{
		std::map<int, Character>::iterator it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, Character>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, Character> m_Map;
};

__declspec(selectany) CharacterData CharacterDataInstance;

} // ExcelData

