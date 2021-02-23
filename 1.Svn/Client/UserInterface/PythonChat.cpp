//Find
		case CPythonChat::WHISPER_TYPE_GM:
			pChatLine->Instance.SetColor(D3DXCOLOR(1.0f, 0.632f, 0.0f, 1.0f));
			break;
			
///Add
#if defined(BL_OFFLINE_MESSAGE)
		case CPythonChat::WHISPER_TYPE_OFFLINE:
			pChatLine->Instance.SetColor(0xffb9f2ff);
			break;
#endif