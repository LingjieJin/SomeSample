int ExecuteShell(LPCSTR pShellName, char *szFormat, ...)
{
	if(pShellName == NULL)
	{
		return SHELL_RET_FAIL;
	}

	char szParam[256] = {0};
	char szCommand[256*2] = {0};
	char szResult[256] = {0};
	FILE* fp = NULL;
	int dwRet = 0;

	va_list pvList;
	va_start(pvList, szFormat); 
	const u32 actLen = vsprintf(szParam, szFormat, pvList);   //把所有参数都存入szParam字符串中
	if((actLen <= 0) || (actLen >= sizeof(szParam)))
	{	
		return SHELL_RET_FAIL;
	}
	va_end(pvList);

	sprintf(szCommand, "%s %s", pShellName, szParam);     //取得执行shell脚本的命令szCommand
	fp = popen(szCommand, "r");         //以读方式，fork产生一个子进程，执行shell命令
	if(fp == NULL)
	{
		return SHELL_RET_FAIL;
	}

	fgets(szResult,sizeof(szResult),fp);                  //读取shell脚本中输出(stdout)的值，即用echo输出的东西。
	pclose(fp);

	dwRet = atol(szResult);      //如果输出不为1，则说明执行失败！
	if( dwRet != 1 )
	{
		return SHELL_RET_FAIL;		
	}

	return SHELL_RET_OK;
}