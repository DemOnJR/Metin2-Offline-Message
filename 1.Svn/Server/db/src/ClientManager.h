//Find
	void		WeddingEnd(TPacketWeddingEnd * p);
	
///Add
#if defined(BL_OFFLINE_MESSAGE)
	void		RequestReadOfflineMessages(CPeer* pkPeer, DWORD dwHandle, TPacketGDReadOfflineMessage* p);
	void		SendOfflineMessage(TPacketGDSendOfflineMessage* p);
#endif

//Find
	TEventFlagMap m_map_lEventFlag;
	
///Add
#if defined(BL_OFFLINE_MESSAGE)
	struct SOfflineMessage
	{
		std::string From;
		std::string Message;
		SOfflineMessage(const char* szFrom, const char* szMessage)
			: From(szFrom), Message(szMessage) {}
	};
	std::unordered_map<std::string, std::vector<std::shared_ptr<SOfflineMessage>>> m_OfflineMessage;
#endif