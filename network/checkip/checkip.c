/*description check if there is ip conflict
 *return 1 ip conflict, 0 not
 */
int check_if_ip_conflict()
{
    char arrcCmd[60] = {0};
    char *pIP = NULL;
    int iConflictFlag = 0;      

    struct in_addr stIPLocal = g_pIPCamSystemInfo->lan_config.net.ip;	// this var is an environmnet which holds the IP address of current device.
    pIP = inet_ntoa(stIPLocal);
    printf("current local ip is %s\n", pIP);
    
    sprintf(arrcCmd, "arping -D -c 1 %s > /mnt/mtd/etc/null", pIP);

    int ret = system(arrcCmd);
    if(-1 != ret && 1 == WEXITSTATUS(ret)) 
    {
        iConflictFlag = 1;
    }

    return iConflictFlag;

}

static int get_random_host_num()
{
    struct drand48_data randbuf;
    struct timeval  tv;
	gettimeofday(&tv, NULL );
	srand48_r(tv.tv_usec, &randbuf);
	double x;
    drand48_r(&randbuf, &x);
    int iHostNum = (int)(x*1000000)%254 + 1;    // range [1,254]
    printf("radom host num is %d\n",iHostNum);
    if(iHostNum < 2)
    {
        iHostNum = 2;   // ignore host num 1;
    }
	return iHostNum;
    
}

/*description find an available ip 
 *@iHostNum random number in [2,254] used as host number
 *@ucIPPart3 the 3rd part of a numbers-and-dots notation ip address.
 *@pstNet a struct to store ip and gateway
 *return 1 available ip has been found, 0 not.
 */

typedef struct 
{
	struct in_addr ip;
	struct in_addr gateway;
} IP_GATE_LAN;

int find_available_ip(int iHostNum, const unsigned char ucIPPart3, IP_GATE_LAN *pstNet)
{
    char arrcCmd[60] = {0};
    char arrcDottedIP[16] = {0};
    int iFindFlag = 0;

    // traverse ip addresses
    for(int i = iHostNum; i < 255; i++)
    {           
        memset(arrcCmd, 0, sizeof(arrcCmd));
        sprintf(arrcDottedIP, "192.168.%d.%d", ucIPPart3, i);
        sprintf(arrcCmd, "arping -c 1 %s > /mnt/mtd/etc/null", arrcDottedIP);
        int ret = system(arrcCmd);
        
        if(-1 != ret && 1 == WEXITSTATUS(ret))    // here dest ip is not alive. ping returns 0 if dest host is alive, 1 if not.
        {            
            iFindFlag = 1;
            printf("the first aviliable IP is %s\n", arrcDottedIP);           
            break;
        }
        
    }

    if(1 == iFindFlag)
    {
        char arrcGateway[16] = {0};
        sprintf(arrcGateway,"192.168.%d.1", ucIPPart3);
        pstNet->ip.s_addr = inet_addr(arrcDottedIP);
        pstNet->gateway.s_addr = inet_addr(arrcGateway);                
    }
    
    return iFindFlag;
    
}

/*decription check if the IP of ipc is in same net segment with that of nvr, 
 *if not find an available ip addr and set.
 *@cuiIPNVR ip of nvr from onvif
 */
int keep_ip_with_nvr_net(const unsigned int cuiIPNVR)
{    
    
    unsigned int uiNetMask = inet_addr("255.255.255.0");
    unsigned int uiIPLocal = g_pIPCamSystemInfo->lan_config.net.ip.s_addr;
    IP_GATE_LAN stNet = {0};
    int iRet = 0; //return value;
    
    const unsigned char *pcucIP = (const unsigned char *)&cuiIPNVR;
    printf("nvr ip is %d.%d.%d.%d\n", *pcucIP, *(pcucIP + 1), *(pcucIP + 2), *(pcucIP + 3));
    unsigned char ucIPPart3 = *(pcucIP + 2);
    int iHostNum = 2;
    int i = 0;
    
    if((uiNetMask & uiIPLocal) == (uiNetMask & cuiIPNVR))
    {
        printf("local ip is in the same net segment with nvr ip\n");
        // check if ip conflict        
        while(check_if_ip_conflict())
        {
            i++;
            printf("while has cycled %d times \n", i);
            
            iHostNum = get_random_host_num();
            iRet = find_available_ip(iHostNum, ucIPPart3, &stNet);
            if(1 == iRet)
            {
                set_ip_and_gateway(&stNet);

            }
            else
            {
                iRet = find_available_ip(2, ucIPPart3, &stNet);
                if(1 == iRet)
                {
                    set_ip_and_gateway(&stNet);
                }
                else
                {
                    printf("There is no available IP left in LAN\n");
                    return 1;

                }
                
            }
            if(i >= 5)
            {
                printf("ip conflict can not handle automaticaly,please handle manualy\n");
                return -1;
            }
           

        }
        
        return 0;
        
    }

    else    
    {   
        do
        {
            i++;
            printf("do while has cycled %d times \n", i);
            
            iHostNum = get_random_host_num();
            iRet = find_available_ip(iHostNum, ucIPPart3, &stNet);
            if(1 == iRet)
            {
                set_ip_and_gateway(&stNet);

            }
            else
            {
                iRet = find_available_ip(2, ucIPPart3, &stNet);
                if(1 == iRet)
                {
                    set_ip_and_gateway(&stNet);
                }
                else
                {
                    printf("There is no available IP left in LAN\n");
                    return 1;

                }
                
            }
            if(i >= 5)
            {
                printf("ip conflict can not handle automaticaly,please handle manualy\n");
                return -1;
            } 
        }
        while(check_if_ip_conflict());
        
        return 0;
        
    }

    return 0;
   
}
/*added by joden 20200514  end*/