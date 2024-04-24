class ExtraLogsDatabaseCallback: RestCallback
{
	private Class m_cbClass;
	private string m_cbFnc;
	private ref Param m_cbArgs;

	void ExtraLogsDatabaseCallback(Class callbackClass, string callbackFnc, ref Param args = null)
	{
		m_cbClass = callbackClass;
		m_cbFnc = callbackFnc;
		m_cbArgs = args;
	}

	override void OnSuccess(string data, int dataSize)
	{
		#ifdef DZSM_DEBUG
		Print("DZSM ExtraLogs ~ OnSuccess: " + data);
		#endif

		if (data.Length() > 0 && data.Get(0) == "[")
		{
			ref DatabaseResponse dbResponse = new DatabaseResponse(data);
			GetGame().GameScript.CallFunctionParams(
				m_cbClass, m_cbFnc, null, 
				new Param2<ref DatabaseResponse, ref Param>(dbResponse, m_cbArgs));
		}
	}
	
	override void OnError(int errorCode)
	{
		Print("DZSM ExtraLogs ~ OnError: " + errorCode);
	}
	
	override void OnTimeout()
	{
		Print("DZSM ExtraLogs ~ OnTimeout");
	}
};

class ExtraLogsDatabase
{	
	
	/**
	\brief Processes query and returns data immediately without error hanling (thread blocking operation!)
	*/
	override void QueryNoStrictSync(string databaseName, string queryText)
	{
		DZSMApiOptions apiOptions = GetDZSMApiOptions();
		RestContext restContext = GetRestApi().GetRestContext(apiOptions.host);
		restContext.SetHeader("text/plain");
		restContext.POST_now("/" + databaseName + "/queryNoStrict?key=" + apiOptions.key, queryText);
	}
    
	/**
	\brief Processes query and returns data immediately (thread blocking operation!)
	*/
	override bool QuerySync(string databaseName, string queryText, out DatabaseResponse response)
	{
		DZSMApiOptions apiOptions = GetDZSMApiOptions();
		#ifdef DZSM_DEBUG
		Print("DZSM ExtraLogs ~ QuerySync: " + apiOptions.host + "/" + databaseName + "/query?key=" + apiOptions.key);
		Print("DZSM ExtraLogs ~ QuerySync: " + queryText);
		#endif
		
		RestContext restContext = GetRestApi().GetRestContext(apiOptions.host);
		restContext.SetHeader("text/plain");
		string responseData = restContext.POST_now("/" + databaseName + "/query?key=" + apiOptions.key, queryText);
		#ifdef DZSM_DEBUG
		Print("DZSM ExtraLogs ~ QuerySyncResponse: " + responseData);
		#endif
		if (responseData.Length() > 0 && responseData.Get(0) == "[")
		{
			response = new DatabaseResponse(responseData);
			return true;
		}
		else
		{
			return false;
		}
	}
	
	/**
	\brief Processes query and calls callback function when finished
	*/
	override void QueryAsync(string databaseName, string queryText, Class callbackClass, string callbackFnc, ref Param args = null)
	{
		DZSMApiOptions apiOptions = GetDZSMApiOptions();
		RestContext restContext = GetRestApi().GetRestContext(apiOptions.host);
		restContext.SetHeader("text/plain");
		
		#ifdef DZSM_DEBUG
		Print("DZSM ExtraLogs ~ QueryAsync: " + apiOptions.host + "/" + databaseName + "/query?key=" + apiOptions.key);
		Print("DZSM ExtraLogs ~ QueryAsync: " + queryText);
		#endif
		
		restContext.POST(new ExtraLogsDatabaseCallback(callbackClass, callbackFnc, args), "/" + databaseName + "/query?key=" + apiOptions.key, queryText);
	}
	
	/**
	\brief Processes transaction (multiple queries) and returns data immediately (thread blocking operation!)
	*/
	override void TransactionSync(string databaseName, ref array<string> queries, out DatabaseResponse response)
	{
		string queryText;
		if (!m_databaseResponseDeserializer.WriteToString(queries, false, queryText))
		{
			return;
		}
		
		DZSMApiOptions apiOptions = GetDZSMApiOptions();
		RestContext restContext = GetRestApi().GetRestContext(apiOptions.host);
		restContext.SetHeader("text/plain");

		#ifdef DZSM_DEBUG
		Print("DZSM ExtraLogs ~ TransactionSync: " + apiOptions.host + "/" + databaseName + "/transaction?key=" + apiOptions.key);
		Print("DZSM ExtraLogs ~ TransactionSync: " + queryText);
		#endif

		string responseData = restContext.POST_now("/" + databaseName + "/transaction?key=" + apiOptions.key, queryText);

		#ifdef DZSM_DEBUG
		Print("DZSM ExtraLogs ~ TransactionSyncResponse: " + responseData);
		#endif

		if (responseData.Length() > 0 && responseData.Get(0) == "[")
		{
			response = new DatabaseResponse(responseData);
		}
	}
	
	/**
	\brief Processes transaction (multiple queries) and calls callback function when finished
	*/
	override void TransactionAsync(string databaseName, ref array<string> queries, Class callbackClass, string callbackFnc, ref Param args = null)
	{
		string queryText;
		if (!m_databaseResponseDeserializer.WriteToString(queries, false, queryText))
		{
			GetGame().GameScript.CallFunctionParams(
				callbackClass, callbackFnc, null, 
				new Param2<ref DatabaseResponse, ref Param>(null, args));
			
			return;
		}
		
		DZSMApiOptions apiOptions = GetDZSMApiOptions();
		RestContext restContext = GetRestApi().GetRestContext(apiOptions.host);
		restContext.SetHeader("text/plain");

		#ifdef DZSM_DEBUG
		Print("DZSM ExtraLogs ~ TransactionAsync: " + apiOptions.host + "/" + databaseName + "/transaction?key=" + apiOptions.key);
		Print("DZSM ExtraLogs ~ TransactionAsync: " + queryText);
		#endif

		restContext.POST(new ExtraLogsDatabaseCallback(callbackClass, callbackFnc, args), "/" + databaseName + "/transaction?key=" + apiOptions.key, queryText);
	}
};
