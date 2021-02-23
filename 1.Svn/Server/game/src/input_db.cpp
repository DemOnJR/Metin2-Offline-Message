//Find
	case HEADER_DG_ITEMAWARD_INFORMER:
		ItemAwardInformer((TPacketItemAwardInfromer*) c_pData);
		break;
		
///Add
#if defined(BL_OFFLINE_MESSAGE)
	case HEADER_DG_RESPOND_OFFLINE_MESSAGES:
		ReadOfflineMessages(DESC_MANAGER::instance().FindByHandle(m_dwHandle), c_pData);
		break;
#endif

///Add new func
#if defined(BL_OFFLINE_MESSAGE)
#include "buffer_manager.h"
void CInputDB::ReadOfflineMessages(LPDESC desc, const char* pcData)
{
	if (!desc || !desc->GetCharacter())
		return;

	if (desc->GetCharacter()->IsBlockMode(BLOCK_WHISPER))
		return;
	
	auto p = reinterpret_cast<const TPacketDGReadOfflineMessage*>(pcData);

	TPacketGCWhisper pack;
	int len = MIN(CHAT_MAX_LEN, strlen(p->szMessage) + 1);
	pack.bHeader = HEADER_GC_WHISPER;
	pack.wSize = static_cast<WORD>(sizeof(TPacketGCWhisper) + len);
	pack.bType = WHISPER_TYPE_OFFLINE;
	strlcpy(pack.szNameFrom, p->szFrom, sizeof(pack.szNameFrom));

	TEMP_BUFFER buf;
	buf.write(&pack, sizeof(TPacketGCWhisper));
	buf.write(p->szMessage, len);
	desc->Packet(buf.read_peek(), buf.size());
}
#endif