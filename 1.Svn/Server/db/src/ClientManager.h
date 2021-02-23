///Add
#include <unordered_map>
#include <chrono>

//Find
	void		WeddingEnd(TPacketWeddingEnd * p);
	
///Add
#if defined(BL_OFFLINE_MESSAGE)
	void		RequestReadOfflineMessages(CPeer* pkPeer, DWORD dwHandle, TPacketGDReadOfflineMessage* p);
	void		SendOfflineMessage(TPacketGDSendOfflineMessage* p);
	void		OfflineMessageGarbage();
#endif

//Find
	TEventFlagMap m_map_lEventFlag;
	
///Add
#if defined(BL_OFFLINE_MESSAGE)
	struct SOfflineMessage
	{
		std::string From;
		std::string Message;
		std::chrono::system_clock::time_point t;
		SOfflineMessage(const char* szFrom, const char* szMessage)
			: From(szFrom), Message(szMessage), t(std::chrono::system_clock::now()) {}
	};
	std::unordered_map<std::string, std::vector<std::shared_ptr<SOfflineMessage>>> m_OfflineMessage;
#endif