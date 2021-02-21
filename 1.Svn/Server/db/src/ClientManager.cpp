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
#endif