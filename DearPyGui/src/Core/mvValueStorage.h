#pragma once

//-----------------------------------------------------------------------------
// mvDataStorage
//
//     - This class acts as a manager for data storage by the users. The 
//       data storage system serves 3 purposes:
//
//         * Allows some widgets to share the same underlying data.
//         * Allows some widgets secondary data be modified (i.e. listbox list items)
//         * Allows the user to store data for any other purpose where
//           the data can be retrieved at a later time.
//
//     - AddData is also used to update existing data. We probably need to add
//       an UpdataData method to make this explicit and come up with another
//       name for the current UpdateData method. The current UpdateData just
//       updates all items in mvApp (which should not be this class's
//       responsibility).
//     
//-----------------------------------------------------------------------------

#include <string>
#include <map>
#include <set>
#include <array>

namespace Marvel {

	//-----------------------------------------------------------------------------
	// mvValueStorage
	//-----------------------------------------------------------------------------
	class mvValueStorage
	{

		enum class ValueTypes 
		{
			None = 0,
			Int,
			Int2,
			Int3,
			Int4,
			Float,
			Float2,
			Float3,
			Float4,
			Bool,
			String
		};

	public:

		// adders
		static int*         AddIntValue    (const std::string& name, int value);
		static int*         AddInt2Value   (const std::string& name, const std::array<int, 2>& value);
		static int*         AddInt3Value   (const std::string& name, const std::array<int, 3>& value);
		static int*         AddInt4Value   (const std::string& name, const std::array<int, 4>& value);
		static float*       AddFloatValue  (const std::string& name, float value);
		static float*       AddFloat2Value (const std::string& name, const std::array<float, 2>& value);
		static float*       AddFloat3Value (const std::string& name, const std::array<float, 3>& value);
		static float*       AddFloat4Value (const std::string& name, const std::array<float, 4>& value);
		static bool*        AddBoolValue   (const std::string& name, bool value);
		static std::string* AddStringValue (const std::string& name, const std::string& value);

		// getters
		static int*         GetIntValue    (const std::string& name);
		static int*         GetInt2Value   (const std::string& name);
		static int*         GetInt3Value   (const std::string& name);
		static int*         GetInt4Value   (const std::string& name);
		static float*       GetFloatValue  (const std::string& name);
		static float*       GetFloat2Value (const std::string& name);
		static float*       GetFloat3Value (const std::string& name);
		static float*       GetFloat4Value (const std::string& name);
		static bool*        GetBoolValue   (const std::string& name);
		static std::string* GetStringValue (const std::string& name);

		static bool HasValue(const std::string& name);

		static ValueTypes GetType(const std::string& name);

		static void IncrementRef(const std::string& name);
		static void DecrementRef(const std::string& name);
		static void DeleteValue(const std::string& name);

		//static void      DeleteData   (const std::string& name);
		//static PyObject* GetData      (const std::string& name); // does not add to ref count
		//static PyObject* GetDataIncRef(const std::string& name); // adds to ref count
		//static unsigned  GetDataCount ();
		//static void      DeleteAllData();

	private:

		mvValueStorage() = default;

		static std::map<std::string, ValueTypes>  s_typeStorage;  // keeps track of reference count
		static std::map<std::string, int>         s_refStorage;  // keeps track of reference count
		static std::set<std::string>              s_itemStorage; // keeps track of registered items

		static std::map<std::string, int>         s_ints;        // int items
		static std::map<std::string, std::array<int, 2>>         s_int2s;        // int items
		static std::map<std::string, std::array<int, 3>>         s_int3s;        // int items
		static std::map<std::string, std::array<int, 4>>         s_int4s;        // int items

		static std::map<std::string, float>       s_floats;      // int items
		static std::map<std::string, std::array<float, 2>>         s_float2s;        // int items
		static std::map<std::string, std::array<float, 3>>         s_float3s;        // int items
		static std::map<std::string, std::array<float, 4>>         s_float4s;        // int items

		static std::map<std::string, bool>        s_bools;      // int items
		static std::map<std::string, std::string> s_strings;      // int items

	};

}