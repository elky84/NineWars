#pragma once

namespace ExcelData
{

class ItemInfo
{
public:
	ItemInfo()
	{
		memset(&m_SafeEnchant, 0, sizeof(m_SafeEnchant));

		memset(&m_Range, 0, sizeof(m_Range));

		memset(&m_Option, 0, sizeof(m_Option));

		memset(&m_Name, 0, sizeof(m_Name));

		memset(&m_MR, 0, sizeof(m_MR));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_Icon, 0, sizeof(m_Icon));

		memset(&m_Damage, 0, sizeof(m_Damage));

		memset(&m_CategoryNumber, 0, sizeof(m_CategoryNumber));

		memset(&m_Category, 0, sizeof(m_Category));

		memset(&m_AttackSpeed, 0, sizeof(m_AttackSpeed));

		memset(&m_AttackRate, 0, sizeof(m_AttackRate));

		memset(&m_AC, 0, sizeof(m_AC));

	}

	int& SafeEnchantReference()
	{
		return m_SafeEnchant;
	}

	int SafeEnchant() const
	{
		return m_SafeEnchant;
	}

	void SafeEnchant(const int& _SafeEnchant)
	{
		m_SafeEnchant = _SafeEnchant;
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

	std::wstring& OptionReference()
	{
		return m_Option;
	}

	std::wstring Option() const
	{
		return m_Option;
	}

	void Option(const std::wstring& _Option)
	{
		m_Option = _Option;
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

	int& MRReference()
	{
		return m_MR;
	}

	int MR() const
	{
		return m_MR;
	}

	void MR(const int& _MR)
	{
		m_MR = _MR;
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

	std::wstring& IconReference()
	{
		return m_Icon;
	}

	std::wstring Icon() const
	{
		return m_Icon;
	}

	void Icon(const std::wstring& _Icon)
	{
		m_Icon = _Icon;
	}

	int& DamageReference()
	{
		return m_Damage;
	}

	int Damage() const
	{
		return m_Damage;
	}

	void Damage(const int& _Damage)
	{
		m_Damage = _Damage;
	}

	int& CategoryNumberReference()
	{
		return m_CategoryNumber;
	}

	int CategoryNumber() const
	{
		return m_CategoryNumber;
	}

	void CategoryNumber(const int& _CategoryNumber)
	{
		m_CategoryNumber = _CategoryNumber;
	}

	std::wstring& CategoryReference()
	{
		return m_Category;
	}

	std::wstring Category() const
	{
		return m_Category;
	}

	void Category(const std::wstring& _Category)
	{
		m_Category = _Category;
	}

	int& AttackSpeedReference()
	{
		return m_AttackSpeed;
	}

	int AttackSpeed() const
	{
		return m_AttackSpeed;
	}

	void AttackSpeed(const int& _AttackSpeed)
	{
		m_AttackSpeed = _AttackSpeed;
	}

	int& AttackRateReference()
	{
		return m_AttackRate;
	}

	int AttackRate() const
	{
		return m_AttackRate;
	}

	void AttackRate(const int& _AttackRate)
	{
		m_AttackRate = _AttackRate;
	}

	int& ACReference()
	{
		return m_AC;
	}

	int AC() const
	{
		return m_AC;
	}

	void AC(const int& _AC)
	{
		m_AC = _AC;
	}

private:
	int m_SafeEnchant;
	float m_Range;
	std::wstring m_Option;
	std::wstring m_Name;
	int m_MR;
	int m_Index;
	std::wstring m_Icon;
	int m_Damage;
	int m_CategoryNumber;
	std::wstring m_Category;
	int m_AttackSpeed;
	int m_AttackRate;
	int m_AC;
};

class ItemInfoData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		ItemInfo Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/ItemInfo.XML");
		if( false == parser.read_file(L"./XML/ItemInfo.XML"))
		{
			LOG_ERROR(_T("%s, Open() Failed. Path(./XML/ItemInfo.XML"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.execute(L"/ItemInfoList"))
		{
			LOG_ERROR(_T("%s, execute() Failed. /ItemInfoList"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(_T("%s, execute() Failed. Data"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"AC", Instance.ACReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.ACReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"AttackRate", Instance.AttackRateReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.AttackRateReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"AttackSpeed", Instance.AttackSpeedReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.AttackSpeedReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Category", Instance.CategoryReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.CategoryReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"CategoryNumber", Instance.CategoryNumberReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.CategoryNumberReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Damage", Instance.DamageReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.DamageReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Icon", Instance.IconReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.IconReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.IndexReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"MR", Instance.MRReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.MRReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Name", Instance.NameReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.NameReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Option", Instance.OptionReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.OptionReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Range", Instance.RangeReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.RangeReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"SafeEnchant", Instance.SafeEnchantReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.SafeEnchantReference()"), __FUNCTIONW__);
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, ItemInfo>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, ItemInfo& Instance)
	{
		std::map<int, ItemInfo>::iterator it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, ItemInfo>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, ItemInfo> m_Map;
};

__declspec(selectany) ItemInfoData ItemInfoDataInstance;

} // ExcelData

