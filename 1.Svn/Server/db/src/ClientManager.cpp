//Find
	m_peerList.clear();
	
///Add
#if defined(BL_OFFLINE_MESSAGE)
	m_OfflineMessage.clear();
#endif

//Find
			case HEADER_GD_REQUEST_CHANNELSTATUS:
				RequestChannelStatus(peer, dwHandle);
				break;
				
///Add
#if defined(BL_OFFLINE_MESSAGE)
			case HEADER_GD_REQUEST_OFFLINE_MESSAGES:
				RequestReadOfflineMessages(peer, dwHandle, (TPacketGDReadOfflineMessage*) data);
				break;
			case HEADER_GD_SEND_OFFLINE_MESSAGE:
				SendOfflineMessage((TPacketGDSendOfflineMessage*) data);
				break;
#endif

//Find
		if (!(thecore_heart->pulse % (thecore_heart->passes_per_sec * 3600)))	// ЗСЅГ°ЈїЎ ЗС№ш
		{
			CMoneyLog::instance().Save();
		}
		
///Add
#if defined(BL_OFFLINE_MESSAGE)
		if (!(thecore_heart->pulse % (thecore_heart->passes_per_sec * 3600)))
		{
			CClientManager::instance().OfflineMessageGarbage();
		}
#endif

///Add new funcs
#if defined(BL_OFFLINE_MESSAGE)
void CClientManager::RequestReadOfflineMessages(CPeer* pkPeer, DWORD dwHandle, TPacketGDReadOfflineMessage* p)
{
	auto it = m_OfflineMessage.find(p->szName);
	if (it == m_OfflineMessage.end())
		return;

	const auto& vec = it->second;
	TPacketDGReadOfflineMessage r;
	for (const auto& msg : vec) {
		strlcpy(r.szFrom, msg->From.c_str(), sizeof(r.szFrom));
		strlcpy(r.szMessage, msg->Message.c_str(), sizeof(r.szMessage));
		pkPeer->EncodeHeader(HEADER_DG_RESPOND_OFFLINE_MESSAGES, dwHandle, sizeof(r));
		pkPeer->Encode(&r, sizeof(r));
	}

	m_OfflineMessage.erase(it);
}

void CClientManager::SendOfflineMessage(TPacketGDSendOfflineMessage* p)
{
	auto msg = std::make_shared<SOfflineMessage>(p->szFrom, p->szMessage);
	m_OfflineMessage[p->szTo].emplace_back(std::move(msg));
}

void CClientManager::OfflineMessageGarbage()
{
	if (m_OfflineMessage.empty())
		return;

	static const/*expr*/ int iHour = 5;
	const auto tCurrent = std::chrono::system_clock::now();

	for (auto& mOff : m_OfflineMessage) {
		auto& vMessage = mOff.second;
		for (auto iter = vMessage.begin(); iter != vMessage.end();) {
			if (std::chrono::duration_cast<std::chrono::hours>(tCurrent - iter->get()->t).count() >= iHour)
				iter = vMessage.erase(iter);
			else
				++iter;
		}
	}
}
#endif