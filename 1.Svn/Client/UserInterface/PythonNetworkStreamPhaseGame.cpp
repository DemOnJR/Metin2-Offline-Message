//Find
	if (CPythonChat::WHISPER_TYPE_CHAT == whisperPacket.bType || CPythonChat::WHISPER_TYPE_GM == whisperPacket.bType)
	
///Change
	if (CPythonChat::WHISPER_TYPE_CHAT == whisperPacket.bType || CPythonChat::WHISPER_TYPE_GM == whisperPacket.bType
#if defined(BL_OFFLINE_MESSAGE)
		|| CPythonChat::WHISPER_TYPE_OFFLINE == whisperPacket.bType
#endif
		)