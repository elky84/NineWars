#pragma once

namespace ExcelData
{

class Equip
{
public:
	Equip()
	{
		memset(&m_Shirts, 0, sizeof(m_Shirts));

		memset(&m_Robe, 0, sizeof(m_Robe));

		memset(&m_RightHand, 0, sizeof(m_RightHand));

		memset(&m_LeftHand, 0, sizeof(m_LeftHand));

		memset(&m_Helmet, 0, sizeof(m_Helmet));

		memset(&m_Glove, 0, sizeof(m_Glove));

		memset(&m_Class, 0, sizeof(m_Class));

		memset(&m_Boots, 0, sizeof(m_Boots));

		memset(&m_Armor, 0, sizeof(m_Armor));

	}

	int& ShirtsReference()
	{
		return m_Shirts;
	}

	int Shirts() const
	{
		return m_Shirts;
	}

	void Shirts(const int& _Shirts)
	{
		m_Shirts = _Shirts;
	}

	int& RobeReference()
	{
		return m_Robe;
	}

	int Robe() const
	{
		return m_Robe;
	}

	void Robe(const int& _Robe)
	{
		m_Robe = _Robe;
	}

	int& RightHandReference()
	{
		return m_RightHand;
	}

	int RightHand() const
	{
		return m_RightHand;
	}

	void RightHand(const int& _RightHand)
	{
		m_RightHand = _RightHand;
	}

	int& LeftHandReference()
	{
		return m_LeftHand;
	}

	int LeftHand() const
	{
		return m_LeftHand;
	}

	void LeftHand(const int& _LeftHand)
	{
		m_LeftHand = _LeftHand;
	}

	int& HelmetReference()
	{
		return m_Helmet;
	}

	int Helmet() const
	{
		return m_Helmet;
	}

	void Helmet(const int& _Helmet)
	{
		m_Helmet = _Helmet;
	}

	int& GloveReference()
	{
		return m_Glove;
	}

	int Glove() const
	{
		return m_Glove;
	}

	void Glove(const int& _Glove)
	{
		m_Glove = _Glove;
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

	int& BootsReference()
	{
		return m_Boots;
	}

	int Boots() const
	{
		return m_Boots;
	}

	void Boots(const int& _Boots)
	{
		m_Boots = _Boots;
	}

	int& ArmorReference()
	{
		return m_Armor;
	}

	int Armor() const
	{
		return m_Armor;
	}

	void Armor(const int& _Armor)
	{
		m_Armor = _Armor;
	}

private:
	int m_Shirts;
	int m_Robe;
	int m_RightHand;
	int m_LeftHand;
	int m_Helmet;
	int m_Glove;
	int m_Class;
	int m_Boots;
	int m_Armor;
};

class EquipData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		Equip Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/Equip.XML");
		if( false == parser.read_file(L"./XML/Equip.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/Equip.XML");
			return false;
		}

		if ( false == parser.execute(L"/EquipList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /EquipList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"Armor", Instance.ArmorReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ArmorReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Boots", Instance.BootsReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.BootsReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Class", Instance.ClassReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ClassReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Glove", Instance.GloveReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.GloveReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Helmet", Instance.HelmetReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.HelmetReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"LeftHand", Instance.LeftHandReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.LeftHandReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"RightHand", Instance.RightHandReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.RightHandReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Robe", Instance.RobeReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.RobeReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Shirts", Instance.ShirtsReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ShirtsReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, Equip>::value_type(Instance.Class(), Instance));
		}

		return true;
	}

	bool Get(int& key, Equip& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, Equip>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, Equip> m_Map;
};

__declspec(selectany) EquipData EquipDataInstance;

} // ExcelData

