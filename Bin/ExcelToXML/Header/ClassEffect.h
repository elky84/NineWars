#pragma once

namespace ExcelData
{

class ClassEffect
{
public:
	ClassEffect()
	{
		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_Image, 0, sizeof(m_Image));

		memset(&m_Damage, 0, sizeof(m_Damage));

		memset(&m_Attack, 0, sizeof(m_Attack));

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

	std::wstring& DamageReference()
	{
		return m_Damage;
	}

	std::wstring Damage() const
	{
		return m_Damage;
	}

	void Damage(const std::wstring& _Damage)
	{
		m_Damage = _Damage;
	}

	std::wstring& AttackReference()
	{
		return m_Attack;
	}

	std::wstring Attack() const
	{
		return m_Attack;
	}

	void Attack(const std::wstring& _Attack)
	{
		m_Attack = _Attack;
	}

private:
	int m_Index;
	std::wstring m_Image;
	std::wstring m_Damage;
	std::wstring m_Attack;
};

class ClassEffectData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		ClassEffect Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/ClassEffect.XML");
		if( false == parser.read_file(L"./XML/ClassEffect.XML"))
		{
			LOG_ERROR(_T("%s, Open() Failed. Path(./XML/ClassEffect.XML"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.execute(L"/ClassEffectList"))
		{
			LOG_ERROR(_T("%s, execute() Failed. /ClassEffectList"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(_T("%s, execute() Failed. Data"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Attack", Instance.AttackReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.AttackReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Damage", Instance.DamageReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.DamageReference()"), __FUNCTIONW__);
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

		while (parser.next())
		{
			m_Map.insert(std::map<int, ClassEffect>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, ClassEffect& Instance)
	{
		std::map<int, ClassEffect>::iterator it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, ClassEffect>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, ClassEffect> m_Map;
};

__declspec(selectany) ClassEffectData ClassEffectDataInstance;

} // ExcelData

